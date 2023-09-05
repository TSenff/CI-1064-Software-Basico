# Faz um loop que itera até 1000
.section .text
.global _start

_start:
	movq $0, %rdi
_loop_start:
	cmpq $1000, %rdi
	je _loop_end
	add $1, %rdi
	jmp _loop_start
_loop_end:
	movq $60, %rax
	syscall
