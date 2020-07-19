section .text
	global ft_strcpy

ft_strcpy:
	xor rdx, rdx ; reset counter
	mov r9, rsi ; load second arg
	cmp r9, 0 ; check for NULL
	je error ; if NULL return
	call loop ; enter loop
	ret ; send back to main

loop:
	cmp byte [r9 + rdx], 0x0 ; check for null byte
	je return ; if null byte jmp to return
	mov al, [r9 + rdx] ; else copy src in tmp
	mov [rdi + rdx], al ; copy tmp in dst
	inc rdx ; increment
	jmp loop

return:
	mov rax, rdi ; set return value
	ret

error:
	mov rdi, 0 ; point dst to NULL
	mov rax, rdi ; return 0
	ret
