	.file	"addmatsSubr.c"
	.text
	.globl	addMatracies
	.def	addMatracies;	.scl	2;	.type	32;	.endef
	.seh_proc	addMatracies
addMatracies:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	%r8, 32(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L2
.L3:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %ecx
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	32(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %r8
	movq	16(%rbp), %rax
	addq	%r8, %rax
	addl	%ecx, %edx
	movl	%edx, (%rax)
	addl	$1, -4(%rbp)
.L2:
	cmpl	$4, -4(%rbp)
	jle	.L3
	nop
	nop
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
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
	leaq	-96(%rbp), %rcx
	leaq	-64(%rbp), %rdx
	leaq	-32(%rbp), %rax
	movq	%rcx, %r8
	movq	%rax, %rcx
	call	addMatracies
	movl	$1, %eax
	subq	$-128, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (Rev3, Built by MSYS2 project) 14.2.0"
