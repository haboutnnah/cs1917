; for the intel 4004
; prints '0' if $15 contains 2 
; else prints '1'

; Read $15 as rax
xchg %rax $15

; subtract 2 from rax
sub %rax $2
; if rax is 0, go to print func
je %rax .print_0

; else, read 0 in to rax
; we already swapped guaranteed 0
; so this is safer than anything else
xchg %rax $15
add %rax $1
prt
hlt

.print_0: prt
          hlt
