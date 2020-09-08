section .text
	global	ft_list_sort

ft_list_sort:
	mov r12, rdi ; save lst_head_ptr
	push rdi ; save rdi
	cmp qword [r12], 0 ; check lst_head not NULL
	je error
	cmp rsi, 0 ; check funct ptr not null
	je error
	mov r9, rsi ; save function ptr
	call loop
	pop rdi ; set back rdi
	ret

loop:
	mov r8, [r12] ; cur = lst_head
	xor r13, r13 ; reset prev
sub_loop:
	mov qword r10,  [r8 + 8] ; r10 = cur->next
	mov rdi, [r8] ; set first funct param
	mov rsi, [r10] ; set second funct param
	call r9 ; call funct
	cmp rax, 0
	jne sort
	mov r13, r8 ; prev = cur
	mov r8, r10 ; r8 = cur->next
	cmp qword [r8], 0
	je return
	cmp qword [r8 + 8], 0 ; check end lst
	je return
	jmp sub_loop
	
sort:
	mov qword r11, [r10 + 8] ; save cur->next->next
	mov qword [r10 + 8], r8 ; next->next = cur
	mov qword [r8 + 8], r11 ; cur->next = cur->next->next
	cmp qword r8, [r12] ; check cur not equal lst_head
	je spe_sort
	mov qword [r13 + 8], r10 ; prev->next = new_cur
	jmp loop

spe_sort:
	mov qword [r12], r10 ; set new lst_head
	jmp loop

return:
	ret

error:
	pop rdi ; set back rdi
	ret ; exit
