"""
4001 instruction set for asm_4xxx.py
by Hannah Ivy <contact@hannahi.com>

Instructions

| Machine Code |  Instruction      |         Description       |
|--------------|-------------------|---------------------------|
|       0      |      HLT          |          Halt             |
|       1      |     ADD rax, 1    |         rax = rax+1       |
|       2      |     SUB rax, 1    |         rax = rax-1       |
|       3      |     ADD rbx, 1    |         rbx = rbx+1       |
|       4      |     SUB rbx, 1    |         rax = rax-1       |
|       5      |    XCHG rax rbx   |      Swap rax <-> rbx     |
|       6      |      BEL          |         Ring Bell         |
|       7      |      PRT          |         Print rax         |
|       8      |     JNE rax 0 X   |  Jump to X if rax not 0   |
|       9      |      JE rax 0 X   |   Jump to X if rax == 0   |

"""

from  asm_4xxx import InvalidInstruction

def parse_instruction(instruction: str) -> int:
    """
    Parses instructions for the 4003
    """ 
    # Clean up the input
    instruction = instruction.lower()
    machine_code: list = []
    multibyte: bool = False
    secondbyte: str = ''
    instruction_found: bool = True
    # Measure the bytes of the instruction given
    arr_inst = instruction.split()
    arr_inst_len = len(arr_inst)

    instruction = arr_inst[0] # Strips any whitespace
    
    # Count the bytes and distribute them
    if arr_inst_len >= 3:
        multibyte = True
        secondbyte  = arr_inst[1]
        thirdbyte   = arr_inst[2]
        if arr_inst_len == 4:
            fourthbyte  = arr_inst[3]
    elif arr_inst_len != 1:
        # If we don't get the correct amount of instructions
        raise InvalidInstruction("Instructions must be either 1 or 3 bytes")

    # Goes through the multibyte instructions
    if multibyte:
        if instruction == 'add':
            # Manipulate the correct register
            if secondbyte == 'rax':
                for i in range(int(thirdbyte)):
                    machine_code.append(1)
            elif secondbyte == 'rbx':
                for i in range(int(thirdbyte)):
                    machine_code.append(3)
            # The user gave us the wrong register
            else:
                raise InvalidInstruction("add  instructions must only manipulate rax or rbx")
        # If we're subtracting
        elif instruction == 'sub':
            # Work on the correct register
            if secondbyte == 'rax':
                for i in range(int(thirdbyte)):
                    machine_code.append(2)
            elif secondbyte == 'rbx':
                for i in range(int(thirdbyte)):
                    machine_code.append(4)
            # the user gave us the wrong thing again
            else:
                raise InvalidInstruction("SUB instructions must only manipulate rax or rbx")
        # If we have to invert the registers
        elif instruction == 'xchg':
            # this processor only supports inverting them,
            # so complain if the user expects better
            if secondbyte == 'rax' and thirdbyte == 'rbx':
                machine_code.append(5)
            else:
                raise InvalidInstruction("xchg instructions"
                " on the 4003 can only exchange rax and rbx")
        # Jump if not equal to 
        elif instruction == 'jne':
            machine_code.append(8)
            machine_code.append(int(fourthbyte))
            machine_code.append(True)
        # Jump if equal to
        elif instruction == 'je':
            machine_code.append(9)
            machine_code.append(int(fourthbyte))
            machine_code.append(True)
        else: 
            instruction_found = False
    # Halt
    elif instruction == 'hlt':
        machine_code.append(0)
    # Print
    elif  instruction == 'prt': # Custom instruction, no x86 print
        machine_code.append(7)
    # Ring bell
    elif  instruction == 'bel': # Custom instruction, no x86 bell
        machine_code.append(7)
    # If the instruction is none of these
    elif not instruction_found:
        raise NotImplementedError(\
        f"The instruction {instruction} does not exist."
        " Perhaps it is meant to be a multibyte instruction?")
    # If it's not a non-multibyte either
    else:
        raise NotImplementedError(\
        f"The instruction {instruction} does not exist."
        " Perhaps it is meant to be a multibyte instruction?")
    return machine_code
