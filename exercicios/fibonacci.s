 .section .data
 .section .text
 .global _start
 _start:

   /*Inicia variaveis*/
   movq $1, %rdx
   movq $0, %rcx
   movq $1, %rdi

   /* Inicia loop*/
   movq $0, %rbx
_loop:
   cmp $9, %rbx
   je _end_loop 

   addq %rcx, %rdi
   movq %rdx, %rcx
   movq %rdi, %rdx

   /* Fim do loop */
   addq $1, %rbx
   jmp _loop
_end_loop:
   movq $60, %rax
   syscall
