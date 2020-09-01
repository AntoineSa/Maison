section .text
	global ft_strlen

ft_strlen:
	xor rdx, rdx ; reset counter
	mov rcx, rdi ; load arg in rcx
	cmp rdi, 0 ; check for NULL
	je return
loop:
	cmp byte [rcx + rdx], 0x00
	je return ; if c = \0 jump to return
	inc rdx ; dec = decrement inc = increment
	jmp loop ; jump if greater

return:
	mov rax, rdx ; set return value
	xor rdx, rdx
	ret ; send back to main
