#!/usr/bin/env python3
"""
Parses 4*** asm code to machine code.
Might not work on a real machine -- this is for UNSW's [CS|HS]1917

By Hannah Ivy <contact@hannahi.com>
"""

import argparse   # Used to parse arguments 
import importlib  # So we can import the instruction set of a given processor
import os         # To check if a file exists
import sys        # To check python version

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
    print("Checking your version of python . . .")
    assert sys.version_info >= (3, 6) 
    print("All good!")
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

    final_instructions = []
    follow_up = []
    instruction_count = 0
    labels = {}
    # For each line in the input file, and keep count starting at 1
    for line in open(asm_file, 'r'):
        # Remove newlines
        instruction = line.strip()
        # Make sure it's not an empty line or a comment
        if len(instruction) > 0 and instruction[0] != ';':
            # Remove the comment
            instruction = line.split(";")[0]
            # I dunno why this is here but one time before I needed it
            instruction = instruction.strip()
            # Parses the instruction given
            returned_data= parse_instruction(instruction)

            # Parse the returned data
            machine_code = returned_data["machine_code"]

            # If ther is a label
            if "label" in returned_data:
                # It's a labelled block
                label = returned_data["label"]
                if label[0] == '.':
                    labels[label] = instruction_count
                else:
                    raise InvalidInstruction("Labels must start with .")

            for mini_instruction in machine_code:
                if type(mini_instruction) == str:
                    follow_up.append(instruction_count)
                final_instructions.append(mini_instruction)
                instruction_count += 1
            # Print the instruction translation if the user requests

            if verbosity:
                print(f"Instruction {instruction} = {machine_code}")

    # For each instruction that we must follow up on
    # This is instructions that are jumping to a block
    for instruction in follow_up:
        # The label we are to follow up
        label = final_instructions[instruction]
        pointer = labels[label]
        # Change the final instruction
        final_instructions[instruction] = pointer
        # Tell the user if they ask
        if verbosity:
            print(f"Label {label} is instruction number {labels[label]}")

    # Open the output file that the user told us to
    # The w+ means we make it if it doesn't exist already
    outfile_handle = open(outfile, 'w+')
    # count the amount of instructions in the file
    for instruction in final_instructions:
        # Write it out
        outfile_handle.write(f"{instruction} ")
    # Exit
    print(f"Compiled with an output of {instruction_count} instructions.")
    exit(0)