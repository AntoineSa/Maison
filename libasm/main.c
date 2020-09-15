#include <stdio.h>
#include "libasm.h"
#include "test.h"

int	main(void)
{
	printf("ft_write test :\n\n");
	test_write();
	printf("\n");
	printf("ft_read test :\n\n");
	test_read();
	printf("\n");
	printf("ft_strlen test :\n\n");
	test_strlen();
	printf("\n");
	printf("ft_strcpy test :\n\n");
	test_strcpy();
	printf("\n");
	printf("ft_strcmp test :\n\n");
	test_strcmp();
	printf("\n");
	printf("ft_strdup test :\n\n");
	test_strdup();
	printf("\n");
	return (0);
}
