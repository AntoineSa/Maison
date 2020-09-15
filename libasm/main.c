#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
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
	test_atoi_base();
	printf("\n");
	test_lst_push_front();
	printf("\n");
	test_lst_size();
	printf("\n");
	test_lst_sort();
	printf("\n");
	test_lst_remove_if();
	printf("\n");
	return (0);
}
