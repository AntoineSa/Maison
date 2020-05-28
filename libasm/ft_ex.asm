section .text
	global _start

_start:
	cmp ecx, 0x0
	call funct
	jmp exit

funct:
	push ebp ; save for nested funct
	mov ebp, esp
	mov eax, [ebp + 8] ; fetch first arg
	dec ecx, ecx - 1 ; dec = decrement
	cmp ecx, 0x0 ; cmp = compare
	jg loop ; jump if greater
	mov esp, ebp
	pop ebp ; restore for nested funct
	ret ; send back to main

exit:
	mov eax, 1 ; exit sys call
	mov ebx, 0 ; status exit
	int 0x80 ; performe interupt kernel call
