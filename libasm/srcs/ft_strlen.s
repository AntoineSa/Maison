section .text
	global ft_strlen

ft_strlen:
	xor rdx, rdx ; reset counter
loop:
	cmp byte [rdi + rdx], 0x00
	je return ; if c = \0 jump to return
	inc rdx ; dec = decrement inc = increment
	jmp loop ; jump if greater

return:
	mov rax, rdx ; set return value
	xor rdx, rdx
	ret ; send back to main
