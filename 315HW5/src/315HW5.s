	.section	.text

	.global		Sum

Sum:
	push	%rbp
	mov		%rsp,	%rbp

	mov		$0,		%rcx
	mov		$0,		%rdx

	cmp		%rsi,	%rdi

	jg		done
	je		rdi_equa

loop:
	add		%rcx,	%rdi
	cmp		%rsi,	%rdi
	jg		done
	add		%rdi,	%rdx
	sub		%rcx, 	%rdi
	add		$1,		%rcx
	jmp 	loop

rdi_equa:
	mov		%rdi, 	%rdx
done:
	mov		%rdx, 	%rax
	leave
	ret
