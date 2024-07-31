	.file	"1.c"
	.text
	.globl	overflow
	.type	overflow, @function
overflow:
.LFB23:
	.cfi_startproc
	endbr64
	mov $0, %rax
	add %edi, %esi
	sets %sil
	movzbl %sil, %esi
	setl %dil
	movzbl %dil, %edi
	movl $1, %edx
	andl %esi, %edi
	cmpl %edi, %edx
	setne %al
	movzbl %al, %eax 
	ret
	.cfi_endproc
.LFE23:
	.size	overflow, .-overflow
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%d\n%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB24:
	.cfi_startproc
	endbr64
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$2, %esi
	movl	$1, %edi
	call	overflow
	movl	%eax, %ebx
	movl	$999999999, %esi
	movl	$101100101, %edi
	call	overflow
	movl	%eax, %ecx
	movl	%ebx, %edx
	leaq	.LC0(%rip), %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	movl	$0, %eax
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE24:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
