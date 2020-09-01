section .text
	global ft_test

ft_test:
	call rdx
	cmp rax, 0
	jl less
	jg more
	ret

less:
	ret

more:
	ret
