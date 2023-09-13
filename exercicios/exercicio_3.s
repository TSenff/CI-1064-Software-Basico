.section .data
    INI: .quad 0
    END: .quad 21
.section .text
.global _start

_start:
    movq INI, %rdi
    movq END, %rax

    # Verifica INI>END
    cmp %rdi, %rax
    jg _continue
	movq $0 , %rdi
	movq $60, %rax
	syscall
_continue:
    # Loop principal

    movq %rdi, %rbx
_loop_start:
	cmp %rax, %rbx
	je _loop_end
    addq %rbx, %rdi
	addq $1, %rbx
	jmp _loop_start
_loop_end:

    # Verifica se maior que 255 devolve 255
    cmp $255, %rdi
    jle _return 
	movq $255 , %rdi
_return:
	movq $60, %rax
	syscall
    