section .text
	global ft_atoi_base

ft_atoi_base:
	xor rdx, rdx ; reset counter
	call skipspace ; skip whitespace
	call isneg ; check + skip sign
	call loop

loop:
	cmp byte [rdi + rdx], 48 ; check char < 48
	jl return
	cmp byte [rdi + rdx], 57 ; check char > 57
	jg return
	mov r10, [rdi + rdx]
	sub r10, '0'
	add r9, r10
	inc rdx ; i++

skipspace:
	cmp byte [rdi + rdx], 32 ; is space
	jne return
	inc rdx
	jmp skipspace

isneg:
	cmp byte [rdi + rdx], 45
	je setneg
	cmp byte [rdi + rdx], 43
	je setpos
	ret

setneg:
	mov r8, 1
	inc rdx
	ret

negret:
	add r9, 10000000
	ret
setpos:
	mov r8, 0
	inc rdx
	ret

return:
	cmp r8, 1
	je negret ; set neg return
	mov rax, r9 ; set return value
	ret
