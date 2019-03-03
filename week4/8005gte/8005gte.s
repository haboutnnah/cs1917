; by hannah ivy
; takes two numbers in $14 and $15 
; if rax > rbx prints nonzero
; else, prints zero

xchg %rax $14
xchg %rbx $15

.main_loop: xchg %rax %rbx
            je %rax .exit
            sub %rbx $1
            sub %rax $1
            jne %rax .main_loop

.exit: prt
       hlt