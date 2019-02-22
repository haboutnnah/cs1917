; Subtracts two numbers, only if they are already
; in rax and rbx (r0, r1) (i. e. rax - rbx)
; This is for the Intel 4003
; Hannah Ivy <contact@hannahi.com>

; rax = thing to subtract from
; rbx = amount to subtract

je rax 0 17 ; if we need to subtract 0, we can safely exit.

sub rbx 1   ; subtract 1 from rbx and rax.
sub rax 1

xchg rax rbx ; focus on the amount to subtract
jne rax 0 10 ; if it's not zero, then subtract another number (loop)

xchg rax rbx ; if it's not zero, swap them so we can
prt          ; print the answer and
hlt          ; exit
