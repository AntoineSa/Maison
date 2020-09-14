#include <stdlib.h>
#include <stdio.h>
#include "libasm.h"

void	test_strcpy(void)
{
	char	*s1;
	char	*s2;

	s1 = "bonjour";
	if (!(s2 = (char *)malloc(ft_strlen(s1) + 1)))
		return;
	s2 = ft_strcpy(s2, s1);
	printf("s : '%s'\ts2 : '%s'\n", s1, s2);
	free(s2);
	s1 = "";
	if (!(s2 = (char *)malloc(ft_strlen(s1) + 1)))
		return;
	s2 = ft_strcpy(s2, s1);
	printf("s : '%s'\ts2 : '%s'\n", s1, s2);
	free(s2);
}
