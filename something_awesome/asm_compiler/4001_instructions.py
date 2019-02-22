"""
4001 instruction set
by Hannah Ivy <contact@hannahi.com>

Instructions
| Machine Code | Instruction | Description | Long Description          |
|--------------|-------------|-------------|---------------------------|
| 0            | HLT         | Halt        | Stop the program          |
| 1            | ADD 1       | rax = rax+1 | Increase rax by 1         |
| 2            | ADD 2       | rax = rax+2 | Increase rax by 2         |
| 3            | ADD 4       | rax = rax+4 | Increase rax by 4         |
| 4            | ADD 8       | rax = rax+8 | Increase rax by 8         |
| 7            | PRT         | Print rax   | Print the contents of rax |

"""


from asm_4xxx import InvalidInstruction
from itertools import combinations

def iterate_through_options(length: int, aim, ADDS: dict) -> list:
    """
    Goes through all combinations of a list where len(combo) == length.
    Returns a list of a combination that matches the aim, or an empty list.
    """
    combination_arr = combinations(ADDS.keys(),length)
    combo = []
    for option in combination_arr:
        if len(combo) == 0:
            if sum(option) == aim:
                for item in option:
                    combo.append(ADDS[item])
    return combo

def get_combo(aim: int, ADDS: list) -> list:
    """
    Goes through combinations of len >2 and <4 until one is found that meets
    *aim*. Otherwise, it returns an empty an array.
    """
    for i in [2, 3, 4]:
        combo = iterate_through_options(i, aim, ADDS)
        if len(combo) > 0:
            return combo

def parse_instruction(instruction: str) -> list:
    """
    Parses instructions for the 4001
    """ 
    # A dictionary of the amount to add : machine code
    ADDS = {
        1:1,
        2:2,
        4:3,
        8:4
    }
    # The dict we return
    returnable = {}

    # Clean up instruction
    instruction = instruction.lower()

    # Tests for if it is a labelled block
    a_block = instruction.split(':')

    if len(a_block) > 1:
        if len(a_block) > 2:
            raise InvalidInstruction("You can not label an instruction twice.")
        returnable['label'] = a_block[0]
        instruction = a_block[1]


    arr_inst = instruction.split()

    # Removes trailing whitespace
    instruction = arr_inst[0]
    machine_code: list = []
    multibyte: bool = False
    secondbyte: str = ''

    # if the length is 2, 
    if len(arr_inst) == 2:
        # Add the flag for multibyte and store the second byte
        multibyte = True
        secondbyte = arr_inst[1]
    # If it's not 2 or 1, the user might have entered the wrong processor.
    elif len(arr_inst) != 1:
        raise InvalidInstruction("Instructions must be either 1 or 2 bytes."
                                 "Perhaps the code is for the Intel 4003?")
    
    # If the instruction is to halt
    if instruction == 'hlt':
        machine_code.append(0)
    # If it's to add
    elif instruction == 'add':
        # If it is not the correct amount of bytes, complain.
        if not multibyte:
            raise InvalidInstruction("add instructions must be exactly 2 bytes")
        # If we can hit the aim in 1 instruction, go for it.
        elif int(secondbyte) in ADDS:
            machine_code.append(ADDS[int(secondbyte)])
        # Otherwise,
        else:
            # Go find a combo that matches
            out = get_combo(int(secondbyte), ADDS)
            # If there are no combinations, complain.
            if len(out) == 0:
                raise InvalidInstruction("add instructions must only modify"
                " one byte (or get there in 4 modifications)")
            # Add the combination in the array of output nicely
            for code in out:
                machine_code.append(code)
    # If it's to print.
    elif  instruction == 'PRT': # Custom instruction, no x86 print
        machine_code.append(7)
    else:
        raise NotImplementedError(f"The instruction {instruction} does not exist.")
    
    returnable["machine_code"] = machine_code
    
    return returnable
