section .text
	global ft_read

ft_read:
	mov rax, 3 ; read syscall
	mov rbx, rdi ; set fd
	cmp rbx, 01111111b ; check for neg fd
	jg error ; if so error
	mov rcx, rsi ; set buffer
	cmp rcx, 0 ; check for NULL
	je error
	mov rdx, rdx
	int 0x80
	mov rdx, rax
	ret

error:
	mov rax, -1
	ret
