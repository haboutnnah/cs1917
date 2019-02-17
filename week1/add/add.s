; Adds two numbers, only if they are already
; in rax and rbx (r0, r1)
; This is for the Intel 4003
; Hannah Ivy <contact@hannahi.com>

je rax 0 13 ; if it is 0, die

add rbx 1 
sub rax 1

jne rax 0 6

xchg rax rbx
prt
hlt
