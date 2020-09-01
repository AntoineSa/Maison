section .text
	global ft_list_push_front

ft_list_push_front:
	mov qword r8, [rdi] ; save head link
	mov qword r9, rsi ; get new head data pointer
	mov qword [r9 + 8], r8 ; set new head next
	mov [rdi], r9 ; set head ptr
	ret
