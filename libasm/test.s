section .text
	global	_ft_list_remove_if
	extern	_free
	extern	_funct

_ft_list_remove_if:
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
	mov rsi, [r9] ; set second funct arg
	call r13 ; call funct
	call r13 ; call funct
	cmp rax, 0
	je remove
	mov r9, r10 ; cur = next
	cmp r9, 0 ; check for end list
	je return
	mov qword r10, [r9 + 8] ; re = cur->next
	jmp loop

remove:
	cmp r9, [r12] ; check cur not head
	mov rdi, [r9] ; test
	mov rsi, [r12] ; test
	call r13 ; test
	je spe_remove
	mov [r8 + 8], r10 ; prev->next = cur->next
	push rdi ; save rdi
	mov rdi, r9 ; set free arg
	call _free
	pop rdi ; reset rdi
	mov r9, r10 ; cur = cur->next
	mov r10, [r9 + 8] ; next = next->next
	jmp loop

spe_remove:
	;call _funct ; test
	mov qword [r12], r10 ; set new lst_head
	push rdi ; save rdi
	mov rdi, r9 ; set free arg
	call _free
	pop rdi ; restore rdi
	mov r9, r10 ; cur = cur->next
	cmp r9, 0
	je return
	mov r10, [r9 + 8] ; next = next->next
	jmp loop

return:
	ret

error:
	pop rdi ; set back rdi
	ret
