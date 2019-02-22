"""
4004 instruction set for asm_4xxx.py
by Hannah Ivy <contact@hannahi.com>

Instructions

| Machine Code | Instruction         | Description            |
|--------------|---------------------|------------------------|
| 0            | HLT                 | Halt                   |
| 1            | ADD %rax $1         | rax = rax+1            |
| 2            | SUB %rax $1         | rax = rax-1            |
| 3            | ADD %rbx $1         | rbx = rbx+1            |
| 4            | SUB %rbx $1         | rax = rax-1            |
| 5            | ADD %rax %rbx       | rax = rax + rbx        |
| 6            | SUB %rax %rbx       | rax = rax - rbx        |
| 7            | PRT                 | Print rax              |
| 8            | JNE %rax [label]    | Jump to X if rax not 0 |
| 9            | JE %rax [label]     | Jump to X if rax == 0  |
| 10           | mov [address] %rax  | [address] -> rax       |
| 11           | mov [address] %rbx  | [address] -> rbx       |
| 12           | mov %rax [address]  | rax -> [address]       |
| 13           | mov %rax [address]  | rbx -> [address]       |
| 14           | xchg %rax [address] | rax <-> [address]      |
| 15           | xchg %rbx [address] | rbx <-> [address]      |

"""

from enum import Enum
from  asm_4xxx import InvalidInstruction

class Instructions(Enum):
    halt           =       0 
    add_rax_1      =       1
    sub_rax_1      =       2
    add_rbx_1      =       3
    sub_rbx_1      =       4
    add_rax_rbx    =       5
    sub_rax_rbx    =       6
    print_int      =       7
    jump_not_equal =       8
    jump_equal     =       9
    mov_x_rax      =       10
    mov_x_rbx      =       11 
    mov_rax_x      =       12
    mov_rbx_x      =       13
    xchg_rax_x     =       14
    xchg_rbx_x     =       15


def parse_instruction(instruction: str) -> dict:
    """
    Parses instructions for the 4003
    """ 
    # The dict we return
    returnable = {}
    # Clean up the input
    instruction = instruction.lower()

    # Tests for if it is a labelled block
    a_block = instruction.split(':')
    if len(a_block) > 1:
        if len(a_block) > 2:
            raise InvalidInstruction("You can not label an instruction twice.")
        returnable['label'] = a_block[0]
        instruction = a_block[1]


    machine_code: list = []
    multibyte: bool = False

    instruction_found: bool = True
    # Measure the bytes of the instruction given

    arr_inst = instruction.split()
    arr_inst_len = len(arr_inst)

    bytes_arr: dict = {}
    
    # Count the bytes and distribute them
    for i in range(arr_inst_len):
        bytes_arr[i+1]  = arr_inst[i].strip()
    
    instruction = bytes_arr[1]

    # Check for multibyte
    if arr_inst_len > 1:
        multibyte = True
    if arr_inst_len != 3 and arr_inst_len != 1:
        raise InvalidInstruction("Instructions must be either 1 or 3 bytes.")

    # Goes through the multibyte instructions
    if multibyte:
        if instruction == 'add':
            # Check if the user gave us a number
            if bytes_arr[3][0] == '$':
                to_add = int(bytes_arr[3][1:])
                # add numbers
                if bytes_arr[2] == '%rax':
                    for i in range(to_add):
                        machine_code.append(Instructions.add_rax_1.value)
                elif bytes_arr[2] == '%rbx':
                    for i in range(to_add):
                        machine_code.append(Instructions.add_rbx_1.value)
            # If they gave us a register, we have to do that
            elif bytes_arr[3][0] == '%':
                if bytes_arr[2] == '%rax':
                    if bytes_arr[3] == '%rbx':
                        machine_code.append(Instructions.add_rax_rbx.value)
                else:
                    raise InvalidInstruction("You can only add "
                                             "rbx and rax")
            else:
                raise InvalidInstruction("In the 4004 instruction set,"
                                         " prefix registers with %,"
                                         " and integers with $.")
        # If we're subtracting
        elif instruction == 'sub':
            # Check if the user gave us a number
            if bytes_arr[3][0] == '$':
                to_sub = int(bytes_arr[3][1:])
                # sub numbers
                if bytes_arr[2] == '%rax':
                    for i in range(to_sub):
                        machine_code.append(Instructions.sub_rax_1.value)
                elif bytes_arr[2] == '%rbx':
                    for i in range(to_sub):
                        machine_code.append(Instructions.sub_rbx_1.value)
            # If they gave us a register, we have to do that
            elif bytes_arr[3][0] == '%':
                if bytes_arr[2] == '%rax':
                    if bytes_arr[3] == '%rbx':
                        machine_code.append(Instructions.sub_rax_rbx.value)
                else:
                    raise InvalidInstruction("You can only sub "
                                             "rbx and rax")
            else:
                raise InvalidInstruction("In the 4004 instruction set,"
                                         " prefix registers with %,"
                                         " and integers with $.")
                                         
        # If we have to exchange data between register and memory
        elif instruction == 'xchg':
            if bytes_arr[2] == '%rax':
                machine_code.append(Instructions.xchg_rax_x.value)
            elif bytes_arr[2] == '%rbx':
                machine_code.append(Instructions.xchg_rbx_x.value)
            else:
                raise InvalidInstruction("rax and rbx are the only"
                                         " registers")

            if bytes_arr[3][0] == '$': # they gave an address directly
                machine_code.append(int(bytes_arr[3][1:]))
            elif bytes_arr[3][0] == '.': # they gave us a label
                machine_code.append(bytes_arr[3])
            
        # Copy data
        elif instruction == 'mov':
            # Find out the instruction
            if bytes_arr[2][0] == "%":
                if bytes_arr[2] == '%rax':
                    machine_code.append(Instructions.mov_rax_x.value)
                elif bytes_arr[2] == '%rbx':
                    machine_code.append(Instructions.mov_rbx_x.value)
                else:
                    raise InvalidInstruction("rax or rbx are the "
                                             "registers on the 4004")
                # Parse payload
                if bytes_arr[3][0] == '$': # they gave an address 
                    machine_code.append(int(bytes_arr[3][1:]))
                elif bytes_arr[3][0] == '.': # they gave us a label
                    machine_code.append(bytes_arr[3])
                else:
                    raise InvalidInstruction("You have not provided "
                                            "an address or register.")

            elif bytes_arr[3][0] == "%":
                if bytes_arr[3] == '%rax':
                    machine_code.append(Instructions.mov_x_rax.value)
                elif bytes_arr[3] == '%rbx':
                    machine_code.append(Instructions.mov_x_rbx.value)
                else:
                    raise InvalidInstruction("rax or rbx are the "
                                             "registers on the 4004")
                # Parse payload
                if bytes_arr[2][0] == '$': # they gave an address 
                    machine_code.append(int(bytes_arr[2][1:]))
                elif bytes_arr[2][0] == '.': # they gave us a label
                    machine_code.append(bytes_arr[2])
                else:
                    raise InvalidInstruction("You have not provided "
                                            "an address or register.")

            else:
                raise InvalidInstruction("You must address a register")



        # Jump if not equal to 
        elif instruction == 'jne':
            machine_code.append(Instructions.jump_not_equal.value)

            if bytes_arr[3][0] == '$': # they gave an address directly
                machine_code.append(int(bytes_arr[3][1:]))
            elif bytes_arr[3][0] == '.': # they gave us a label
                machine_code.append(bytes_arr[3])

        # Jump if equal to
        elif instruction == 'je':
            machine_code.append(Instructions.jump_equal.value)

            if bytes_arr[3][0] == '$': # they gave an address directly
                machine_code.append(int(bytes_arr[3][1:]))
            elif bytes_arr[3][0] == '.': # they gave us a label
                machine_code.append(bytes_arr[3])
        else: 
            instruction_found = False
    # Halt
    elif instruction == 'hlt':
        machine_code.append(Instructions.halt.value)
    # Print
    elif  instruction == 'prt': # Custom instruction, no x86 print
        machine_code.append(Instructions.print_int.value)
    # Ring bell
    
    # If the instruction is none of these
    elif not instruction_found:
        raise NotImplementedError(\
        f"The instruction {instruction} does not exist.")
    # If it's not a non-multibyte either
    else:
        raise NotImplementedError(\
        f"The instruction {instruction} does not exist.")
    
    returnable["machine_code"] = machine_code
    return returnable
