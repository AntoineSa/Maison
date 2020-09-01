section .text
	global ft_atoi_base
	extern ft_strlen
	extern ft_write

ft_atoi_base:
	xor rdx, rdx ; reset counter
	cmp rdi, 0 ; check for NULL
	je error
	push rdi
	mov rdi, rsi
	call ft_strlen ; get base
	pop rdi
	cmp rax, 1 ; check base len
	jle error
	mov r12, rax ; set base len
	call check_base
	cmp rax, 0 ; check for valid base
	je error
	call skipspace ; skip whitespaces
	mov r8, 1 ; set default sign
	call isneg ; check + skip sign
	xor r9, r9 ; set ret value
	call loop
	ret

check_base:
	mov r8b, [rsi + rdx]
	inc rdx
	mov r9, rdx
	cmp byte [rsi + r9], 0
	jne sub_check
	mov rax, 1
	xor rdx, rdx
	mov r8, 0
	ret
sub_check:
	cmp byte [rsi + r9], 0
	je check_base
	cmp r8b, [rsi + r9]
	je error
	inc r9
	jmp sub_check

skipspace:
	mov r9, rdx
	inc r9
	cmp byte [rdi + rdx], 32 ; is space
	cmove rdx, r9
	je skipspace
	ret

isneg:
	cmp byte [rdi + rdx], '-'
	je setneg
	cmp byte [rdi + rdx], '+'
	je setpos
	ret
setneg:
	mov r8, -1
	inc rdx
	ret
setpos:
	mov r8, 1
	inc rdx
	ret

loop:
	mov byte [count], 0
	call get_in_base
	cmp rax, -1
	je return
	mov r10, rax ; save result
	mov rax, r12 ; set multiplier
	push rdx ; save i on stack
	mul r9
	add rax, r10 ; add result
	mov r9, rax
	pop rdx ; get i back
	inc rdx ; i++
	jmp loop

get_in_base:
	mov r10, rsi
	add r10, [count]
	mov r11b, [r10]
	cmp r11b, 0
	je not_in_base
	mov r10, rdx
	cmp [rdi + r10], r11b
	je is_in_base
	add byte [count], 1
	jmp get_in_base

test:
	xor rax, rax
	mov al, r11b
	mov rax, rdx
	ret
	
is_in_base:
	mov rax, [count]
	ret
	
not_in_base:
	mov rax, -1
	ret

return:
	mov rax, r8
	mul r9
	ret

error:
	mov rax, 0
	ret

section .data

count:	db	0
