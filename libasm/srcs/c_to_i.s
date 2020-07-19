section .text
	global ft_strcmp

ft_strcmp:
	xor rdx, rdx
	mov r8b, [rdi + rdx] ; tmp = *s1
	mov rax, r8
	ret
