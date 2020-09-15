section .text
	global	ft_read
	extern	__errno_location

ft_read:
	cmp rdx, 2147483647
	jg neg_len
	mov rax, 3
	mov rbx, rdi
	mov rcx, rsi
	int 0x80
	cmp rax, 0
	jl neg_ret
	ret

neg_ret:
	neg rax
	mov rdi, rax
	call __errno_location
	mov [rax], rdi
	mov rax, -1
	ret

neg_len:
	call __errno_location
	mov byte [rax], 9
	mov rax, -1
	ret
