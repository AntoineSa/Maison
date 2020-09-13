section .text
	global	ft_list_remove_if
	extern	free
	extern	funct

ft_list_remove_if:
	mov r12, rdi ; save lst_head_ptr
	push rdi ; save rdi
	cmp qword [r12], 0 ; check lst_head not NULL
	je error
	cmp rdx, 0 ; check funct ptr not null
	je error
	mov r13, rdx
	mov rdi, rsi ; set first funct arg
	mov qword r9, [r12] ; r9 = *head
	mov qword r10, [r9 + 8] ; r10 = cur->next
	call loop
	pop rdi ; set back rdi
	ret

loop:
	push r10 ; save r10
	mov rsi, [r9] ; set second funct arg
	push rdi
	push rsi
	push r9
	push r8
	call r13 ; call funct
	cmp rax, 0
	pop r8
	pop r9
	pop rsi
	pop rdi
	je remove
	pop r10
	mov r8, r9 ; prev = cur
	mov r9, r10 ; cur = next
	cmp r9, 0 ; check for end list
	je return
	mov qword r10, [r9 + 8] ; re = cur->next
	jmp loop

remove:
	cmp r9, [r12] ; check cur not head
	push rdi ; save rdi
	push r9 ; test soluce
	je spe_remove
	mov [r8 + 8], r10 ; prev->next = cur->next
	jmp end_loop

spe_remove:
	mov qword [r12], r10 ; set new lst_head
	jmp end_loop

end_loop:
	mov rdi, r9 ; set free arg
	call free
	pop r9 ; set back r9
	pop rdi ; set back rdi
	pop r10
	mov r9, r10 ; cur = next
	cmp r9, 0 ; check end list
	je return
	mov qword r10, [r9 + 8] ; next = cur->next
	jmp loop

return:
	ret

error:
	pop rdi ; set back rdi
	ret
