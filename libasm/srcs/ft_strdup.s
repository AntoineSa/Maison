section .text
	global ft_strdup
	extern ft_strlen
	extern ft_strcpy
	extern malloc

ft_strdup:
	cmp rdi, 0
	je error
	call ft_strlen ; get arg len
	push rdi ; save arg
	inc rax ; len + 1 for malloc
	mov rdi, rax ; set malloc arg
	call malloc ; allocate len
	pop rdi ; get back arg
	cmp rax, 0 ; c
	je error
	mov r9, rax ; save pointer
	mov r8, rdi ; save arg
	mov rdi, r9 ; set dst
	mov rsi, r8 ; set src
	call ft_strcpy ; copy
	ret

error:
	mov rax, 0
	ret
