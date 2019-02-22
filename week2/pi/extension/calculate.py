import sys

PREV_CHAR: int  =  0
CURR_RECD: int  =  0

for i, character in enumerate(open(sys.argv[1], 'r').read()): # the thing the user gives us
    character = int(character)
    if character == PREV_CHAR or character == PREV_CHAR + 1:
        if CURR_RECD == 0:
            CURR_RECD = 1
        CURR_RECD += 1
        print(i, character, CURR_RECD)
    else:
        PREV_CHAR = character
        CURR_RECD = 0

