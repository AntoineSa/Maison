#include <stdio.h>
#include "libasm.h"
#include "test.h"

int	main(void)
{
	test_write();
	printf("\n");
	test_read();
	printf("\n");
	test_strlen();
	printf("\n");
	test_strcpy();
	printf("\n");
	test_strcmp();
	printf("\n");
	test_strdup();
	printf("\n");
	return (0);
}
