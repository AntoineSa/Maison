#include <stdio.h>
#include "libasm.h"
#include "test.h"

int	main(void)
{
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
