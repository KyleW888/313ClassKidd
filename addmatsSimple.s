	.file	"addmatsSimple.c"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	addq	$-128, %rsp
	.seh_stackalloc	128
	.seh_endprologue
	call	__main
	pxor	%xmm0, %xmm0
	movups	%xmm0, -64(%rbp)
	movd	%xmm0, -48(%rbp)
	movl	$1, -64(%rbp)
	pxor	%xmm0, %xmm0
	movups	%xmm0, -96(%rbp)
	movd	%xmm0, -80(%rbp)
	movl	$2, -96(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L2
.L3:
	movl	-4(%rbp), %eax
	cltq
	movl	-64(%rbp,%rax,4), %edx
	movl	-4(%rbp), %eax
	cltq
	movl	-96(%rbp,%rax,4), %eax
	addl	%eax, %edx
	movl	-4(%rbp), %eax
	cltq
	movl	%edx, -32(%rbp,%rax,4)
	addl	$1, -4(%rbp)
.L2:
	cmpl	$4, -4(%rbp)
	jle	.L3
	movl	$1, %eax
	subq	$-128, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (Rev3, Built by MSYS2 project) 14.2.0"
