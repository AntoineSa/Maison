section .text
	global ft_strlen

ft_strlen:
	push rbp ; save for nested funct
	mov rbp, rsp
	mov ecx, [ebp + 8] ; fetch first arg
	mov rdx, 0
	cmp byte [ecx + edx], 0x0 ;	cmp [ecx + edx], 0x0
	call loop ; enter loop
	mov rax, rdx
	mov rsp, rbp
	pop rbp ; restore for nested funct
	ret ; send back to main

loop:
	inc rdx ; dec = decrement inc = increment
	cmp byte [ecx + edx], 0x0
	jg loop ; jump if greater
	ret ; exit loop
