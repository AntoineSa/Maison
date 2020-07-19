section .text
	global	ft_write


ft_write:
	mov rax, 4 ; write sys call
	mov rbx, rdi ; set fd
	cmp rbx, 01111111b ; check for neg fd
	jg error ; jump if less
	mov rcx, rsi ; set content
	cmp rcx, 0 ; check for NULL
	je error ; jump if NULL
	mov rdx, rdx ; set lentgth
	cmp rdx, 01111111b ; check for neg fd
	jg error ; jump if less
	int 0x80 ; syscall
	mov rdx, rax ; set int return value
	ret

error:
	mov rax, -1 ; set return value
	ret
