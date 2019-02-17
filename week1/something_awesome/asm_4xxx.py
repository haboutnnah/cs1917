#!/usr/bin/env python3
"""
Parses 4*** asm code to machine code.
Might not work on a real machine -- this is for UNSW's [CS|HS]1917

By Hannah Ivy <contact@hannahi.com
"""

import argparse   # Used to parse arguments 
import importlib  # So we can import the instruction set of a given processor
import os         # To check if a file exists
import sys        # To check python version


print("Checking your version of python . . .")
assert sys.version_info >= (3, 6) 
print("All good!")

class InvalidInstruction(Exception):
    """
    An exception for when there is an invalid instruction by the enduser.
    """
    pass

def get_args() -> tuple: 
    """ 
    Parses arguments. 
    Returns (processor: str, filename: str, outfile: str, verbose: bool)
    """
    parser: argparse.ArgumentParser = argparse.ArgumentParser(
        description="Converts 4001 assembly code to machine code.")
    parser.add_argument('processor', metavar='processor',
                        type=str, help='Processor: eg 4001, 4003') 
    parser.add_argument('filename', metavar='filename',
                        type=str, help='The file name to convert from')
    parser.add_argument('outfile', metavar='outfile',
                        type=str, help='The file name to convert to')
    parser.add_argument('--verbose', '-v', dest='verbose',
                        action='store_true', 
                        help='Shows the asm and instruction for each as it goes along.')
    parser.set_defaults(verbose=False)
    args = parser.parse_args()
    return args.processor, args.filename, args.outfile, args.verbose  

def get_dict_index(dictionary: dict, item: int) -> int:
    """
    Finds the index of *item* in *dict. 
    Only works in Python 3.7+ (requires ordered dictionary behaviour.)
    """
    i = 0
    for key in dictionary:
        if key == item:
            return i
        i += 1

if __name__ == "__main__":
    # Get arguments
    processor, asm_file, outfile, verbosity = get_args()
    # Protect the user from themselves if they are going to overwrite 
    # their own code.
    if outfile == asm_file:
        print("You have the same outfile as your input. "
        "This will overwrite your code.")
        exit(1)

    # The file name to import
    inst_filename: str = f"{processor}_instructions"
    # Test if its there
    if os.path.isfile(f"{inst_filename}.py"):
        # Import it and set the function to a neat name
        proc_instructions = importlib.import_module(inst_filename)
        parse_instruction = proc_instructions.parse_instruction
    else:
        # We don't have that processor
        raise NotImplementedError("This processor hasn't been implemented.")

    # A dictionary {line_of_instruction: resulting machine code}
    final_instructions = {}

    # For each line in the input file, and keep count starting at 1
    for line_num, line in enumerate(open(asm_file, 'r'), 1):
        # Remove newlines
        instruction = line.strip()
        # Make sure it's not an empty line or a comment
        if len(instruction) > 0 and instruction[0] != ';':
            # Remove the comment
            instruction = line.split(";")[0]
            # I dunno why this is here but one time before I needed it
            instruction = instruction.strip()
            # Parses the instruction given
            machine_code= parse_instruction(instruction)
            # Add it to the dictionary
            final_instructions[line_num] = machine_code
            # Print the instruction translation if the user requests
            if verbosity:
                print(f"Instruction {instruction} = {machine_code}")

    # For each instruction,
    for _, instruction in final_instructions.items():
        # If we have the flag at the end,
        if type(instruction[-1]) == bool and instruction[-1] == True:
            # Remove the last entry
            instruction.pop()
            # The item before the flag is the line to jump to
            jmp_to = instruction[-1]
            # Get the instruction number of the line jumping to 
            # And store it so the processor can understand
            instruction[-1] = get_dict_index(final_instructions, jmp_to)
    # Open the output file that the user told us to
    # The w+ means we make it if it doesn't exist already
    ofile = open(outfile, 'w+')
    # count the amount of instructions in the file
    instruction_count = 0
    for _, instructionarr in final_instructions.items():
        for instruction in instructionarr:
            instruction_count += 1
            # Write it out
            ofile.write(f"{instruction} ")
    # Exit
    print(f"Compiled with an output of {instruction_count} instructions.")
    exit(0)