	.file	"Num_By.c"
	.section	.rodata
	.align 4
.LC0:
	.string	"\nTAMA\303\221O DE BYTES DE LOS TIPOS DE DATOS BASICOS EN C:"
.LC1:
	.string	"\nTIPO DE DATO \t TAMA\303\221O"
.LC2:
	.string	"\n char \t\t %2d"
.LC3:
	.string	"\n int \t\t %2d"
.LC4:
	.string	"\n short \t\t %2d"
.LC5:
	.string	"\n long \t\t %2d"
.LC6:
	.string	"\n double \t\t %2d"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$48, %esp
	movl	$.LC0, %eax
	movl	%eax, (%esp)
	call	printf
	movl	$.LC1, %eax
	movl	%eax, (%esp)
	call	printf
	movl	$.LC2, %eax
	movl	$1, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$.LC3, %eax
	movl	$4, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$.LC4, %eax
	movl	$4, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$.LC5, %eax
	movl	$2, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$.LC6, %eax
	movl	$4, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$0, %eax
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.4.4-14ubuntu5) 4.4.5"
	.section	.note.GNU-stack,"",@progbits
