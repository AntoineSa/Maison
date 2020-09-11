section .text
	global	ft_write
	extern	__errno_location

ft_write:
	cmp rdx, 2147483647
	jg neg_len
	mov rax, 4 ; write sys call
	mov rbx, rdi ; set fd
	mov rcx, rsi ; set content
	int 0x80 ; syscall
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
	mov byte [rax], 14
	mov rax, -1
	ret
