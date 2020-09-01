section .text
	global	ft_list_size

ft_list_size:
	xor rdx, rdx
	cmp qword [rdi], 0
	je return
	inc rdx
	mov r8, rdi
	mov r9, [rdi + 8]
	call loop
	ret

loop:
	cmp qword [r8 + 8], 0
	je return
	inc rdx
	mov qword r8, [r8 + 8]
	jmp loop

return:
	mov rax, rdx
	ret
