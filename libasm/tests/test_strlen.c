#include <string.h>
#include <stdio.h>
#include "libasm.h"

void	test_strlen(void)
{
	char	*s;

	s = "bonjour";
	printf("len of '%s' : %lu\treal : %lu\n", s, ft_strlen(s), strlen(s));
	s = "";
	printf("len of '%s' : %lu\treal : %lu\n", s, ft_strlen(s), strlen(s));
}
