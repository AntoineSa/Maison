section .text
	global ft_strcmp

ft_strcmp:
	xor rdx, rdx ; reset counter
	xor r8, r8
	xor r9, r9
	cmp rdi, 0 ;
	je error ;
	cmp rsi, 0 ;
	je error ;
	call loop ;
	ret ;

loop :
	mov r8b, [rdi + rdx] ; tmp = *s1
	mov r9b, [rsi + rdx] ; tmp = *s2
	cmp r8b, r9b ; cmp s1 s2
	jne return ; return
	cmp r8b, 0 ; check end of s1
	je return ; if so return
	cmp r9b, 0 ; check end of s2
	je return ; if so return
	inc rdx
	jmp loop

error :
	mov rax, -1
	ret

return:
	sub r8, r9
	mov rax, r8
	ret
