section .text
	global ft_strdup
	extern ft_strlen
	extern ft_strcpy
	extern malloc
	extern __errno_location

ft_strdup:
	cmp rdi, 0
	je error
	call ft_strlen ; get arg len
	push rdi ; save arg
	inc rax ; len + 1 for malloc
	mov rdi, rax ; set malloc arg
	call malloc ; allocate len
	pop rdi ; get back arg
	cmp rax, 0 ; check malloc
	je error
	mov r9, rax ; save pointer
	mov r8, rdi ; save arg
	mov rdi, r9 ; set dst
	mov rsi, r8 ; set src
	call ft_strcpy ; copy
	ret

error:
	call __errno_location
	mov byte [rax], 12
	mov rax, 0
	ret
