#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "libasm.h"
#include "test.h"

void	ft_strlen_test(void)
{
	char	*s;

	s = "bonjour";
	printf("len of '%s': %lu\treal : %lu\n", s, ft_strlen(s), strlen(s));
	s = "";
	printf("len of '%s': %lu\treal : %lu\n", s, ft_strlen(s), strlen(s));
}

void	ft_strcpy_test(void)
{
	char	*s1;
	char	*s2;
	char	*s3;

	s1 = "bonjour";
	s2 = (char *)malloc(ft_strlen(s1));
	s3 = ft_strcpy(s2, s1);
	printf("s : '%s'\ns2 : '%s'\ns3 : '%s'\n", s1, s2, s3);
	free(s2);
	s1 = "";
	s2 = (char *)malloc(ft_strlen(s1));
	s3 = ft_strcpy(s2, s1);
	printf("s : '%s'\ns2 : '%s'\ns3 : '%s'\n", s1, s2, s3);
	free(s2);
	s1 = NULL;
	s2 = (char *)malloc(ft_strlen(s1));
	s3 = ft_strcpy(s2, s1);
	printf("s : '%s'\ns2 : '%s'\ns3 : '%s'\n", s1, s2, s3);
}

void	ft_strcmp_test(void)
{
	char	*s1;
	char	*s2;
	int	diff;

	s1 = "bonjour";
	s2 = "bonjour";
	diff = ft_strcmp(s1, s2);
	printf("s1 : '%s'\ts2 : '%s'\tdiff : %d\n", s1, s2, diff);
	s1 = "bon our";
	s2 = "bonjou";
	diff = ft_strcmp(s1, s2);
	printf("s1 : '%s'\ts2 : '%s'\tdiff : %d\n", s1, s2, diff);
	s1 = "bonjour";
	s2 = "bon ou";
	diff = ft_strcmp(s1, s2);
	printf("s1 : '%s'\ts2 : '%s'\tdiff : %d\n", s1, s2, diff);
	s1 = "";
	s2 = "bonjour";
	diff = ft_strcmp(s1, s2);
	printf("s1 : '%s'\ts2 : '%s'\tdiff : %d\n", s1, s2, diff);
	s1 = "";
	s2 = "";
	diff = ft_strcmp(s1, s2);
	printf("s1 : '%s'\ts2 : '%s'\tdiff : %d\n", s1, s2, diff);
	s1 = NULL;
	s2 = "bon";
	diff = ft_strcmp(s1, s2);
	printf("s1 : '%s'\ts2 : '%s'\tdiff : %d\n", s1, s2, diff);
}

void	ft_strdup_test(void)
{
	char	*s;
	char	*s2;

	s = "bonjour";
	s2 = ft_strdup(s);
	printf("s : %p\ts2 : %p\n", s, s2);
	printf("s : '%s'\ts2 : '%s'\n", s, s2);
	free(s2);
	s = "";
	s2 = ft_strdup(s);
	printf("s : %p\ts2 : %p\n", s, s2);
	printf("s : '%s'\ts2 : '%s'\n", s, s2);
	free(s2);
	s = NULL;
	s2 = ft_strdup(s);
	printf("s : %p\ts2 : %p\n", s, s2);
	printf("s : '%s'\ts2 : '%s'\n", s, s2);
	free(s2);
}

void	ft_atoi_base_test(void)
{
	char	*s;
	char	*base;
	int	res;

	s = "   1";
	base = "0";
	res = ft_atoi_base(s, base);
	printf("s : '%s' base : %s res : %d\n", s, base, res);
	s = "   1";
	base = "011";
	res = ft_atoi_base(s, base);
	printf("s : '%s' base : %s res : %d\n", s, base, res);
	s = "   12";
	base = "01";
	res = ft_atoi_base(s, base);
	printf("s : '%s' base : %s res : %d\n", s, base, res);
	s = "   1011";
	base = "01";
	res = ft_atoi_base(s, base);
	printf("s : '%s' base : %s res : %d\n", s, base, res);
	s = "  01";
	base = "01";
	res = ft_atoi_base(s, base);
	printf("s : '%s' base : %s res : %d\n", s, base, res);
	s = "  -11";
	base = "01";
	res = ft_atoi_base(s, base);
	printf("s : '%s' base : %s res : %d\n", s, base, res);
	s = "42";
	base = "0123456789";
	res = ft_atoi_base(s, base);
	printf("s : '%s' base : %s res : %d\n", s, base, res);
	s = "42";
	base = "0123456789ABCDEF";
	res = ft_atoi_base(s, base);
	printf("s : '%s' base : %s res : %d\n", s, base, res);
	s = "-42";
	base = "0123456789";
	res = ft_atoi_base(s, base);
	printf("s : '%s' base : %s res : %d\n", s, base, res);
	s = "aze 42";
	base = "0123456789";
	res = ft_atoi_base(s, base);
	printf("s : '%s' base : %s res : %d\n", s, base, res);
}

void	ft_lst_push_front_test()
{
	t_list	list_1;
	t_list	list_2;
	t_list	list_3;
	t_list	list_n;
	t_list	list_n2;
	t_list	list_n3;
	t_list	*ptr;

	ptr = &list_1;
	list_1.data = "bonjour";
	list_1.next = &list_2;
	list_2.next = &list_3;
	list_3.next = 0;
	list_n.data = "wzaqsow";
	list_n2.data = "woooooow";
	list_n3.data = "wow";
	printf("length : %d\n", ft_list_size(ptr));
	ft_list_push_front(&ptr, &list_n);
	ft_list_push_front(&ptr, &list_n2);
	ft_list_push_front(&ptr, &list_n3);
	printf("new length : %d\texpected : 6\n", ft_list_size(ptr));
	printf("data of lst_head : %s\texpected : 'wow'\n", ptr->data);
	printf("data of lst_head->next : %s\texpected : 'woooooow'\n", ptr->next->data);
}

void	ft_lst_size_test(void)
{
	t_list	list_1;
	t_list	list_2;
	t_list	list_3;
	t_list	*ptr;

	ptr = &list_1;
	list_1.data = "bonjour";
	list_1.next = &list_2;
	list_2.next = &list_3;
	list_3.next = 0;
	printf("lst size = %d\n", ft_list_size(ptr));
}

int	f_cmp(void *s1, void *s2)
{
	int	nb;

	nb = ft_strlen(s1) - ft_strlen(s2);
	if (nb < 0)
		return (1);
	return (0);
}

void	ft_lst_sort_test(void)
{
	t_list	list_1;
	t_list	list_2;
	t_list	list_3;
	t_list	list_n;
	t_list	list_n2;
	t_list	list_n3;
	t_list	*ptr;

	list_1.data = "1";
	list_1.next = &list_2;
	list_2.data = "333";
	list_2.next = &list_3;
	list_3.data = "22";
	list_3.next = &list_n;
	list_n.data = "7777777";
	list_n.next = &list_n2;
	list_n2.data = "1";
	list_n2.next = &list_n3;
	list_n3.data = "4444";
	list_n3.next = 0;
	ptr = &list_1;
	ft_list_sort(&ptr, &f_cmp);
	while (ptr != 0)
	{
		printf("data : %s\n", ptr->data);
		ptr = ptr->next;
	}
}

int	rm_cmp(void *ref, void *data)
{
	int	nb;

	//nb = ft_strcmp(ref, data);
	nb = 2;
	return (nb);
}

void	ft_lst_remove_if_test(void)
{
	t_list	*list_1;
	t_list	*list_2;
	t_list	*list_3;
	t_list	*list_n;
	t_list	*list_n2;
	t_list	*list_n3;
	t_list	**ptr;

	list_1 = (t_list *)malloc(sizeof(t_list));
	list_1->data = "55555";
	list_2 = (t_list *)malloc(sizeof(t_list));
	list_1->next = list_2;
	list_2->data = "4444";
	list_3 = (t_list *)malloc(sizeof(t_list));
	list_2->next = list_3;
	list_3->data = "22";
	list_n = (t_list *)malloc(sizeof(t_list));
	list_3->next = list_n;
	list_n->data = "7777777";
	list_n2 = (t_list *)malloc(sizeof(t_list));
	list_n->next = list_n2;
	list_n2->data = "1";
	list_n3 = (t_list *)malloc(sizeof(t_list));
	list_n2->next = list_n3;
	list_n3->data = "4444";
	list_n3->next = NULL;
	*ptr = list_1;
	printf("\nyay ptr : %p\t*ptr : %p\t&list_1 : %p\t list_1 : %p\n", ptr, *ptr, &list_1, list_1);
	while (*ptr != 0)
	{
		printf("data : %s\n", (*ptr)->data);
		*ptr = (*ptr)->next;
	}
	*ptr = list_1;
	ft_list_remove_if(ptr, "333", &rm_cmp);
	printf("\nyay ptr : %p\t*ptr : %p\t&list_1 : %p\t list_1 : %p\n", ptr, *ptr, &list_1, list_1);
	printf("head->data : %s\n", (*ptr)->data);
/*	ft_list_remove_if(ptr, "333", &rm_cmp);
	printf("yeeup\n");
	while (*ptr != 0)
	{
		printf("data : %s\n", (*ptr)->data);
		*ptr = (*ptr)->next;
	}
*/}

int	main(void)
{
/*	test_write();
	printf("\n");
	test_read();
	printf("\n");
	ft_strlen_test();
	printf("\n");
//	ft_strcpy_test();
//	printf("\n");
//	ft_strcmp_test();
//	printf("\n");
//	ft_strdup_test();
//	printf("\n");
//	ft_atoi_base_test();
//	printf("\n");
//	ft_lst_push_front_test();
//	printf("\n");
//	ft_lst_size_test();
//	printf("\n");
*/	ft_lst_sort_test();
	printf("\n");
	ft_lst_remove_if_test();
	printf("\n");
	return (0);
}
