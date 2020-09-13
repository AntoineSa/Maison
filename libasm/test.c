#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

typedef struct	s_list
{
	void		*data;
	struct s_list	*next;
}		t_list;

void	ft_list_remove_if(t_list **head, void *data_ref, int (*cmp)());

unsigned long	ft_strlen(char *s);

void	funct(void	*ptr)
{
	printf("in remove, rdi ; %p\n", ptr);
}

int	rm_cmp(char *ref, char *data)
{
	int	nb;

	nb = ft_strlen(ref) - ft_strlen(data);
	if (nb < 0)
		return (0);
	return (1);
}

int	main(void)
{
	t_list	*list_1;
	t_list	*list_2;
	t_list	*list_3;
	t_list	*list_n;
	t_list	*list_n2;
	t_list	*list_n3;
	t_list	**ptr;

	ptr = (t_list **)malloc(sizeof(t_list *));
	list_1 = (t_list *)malloc(sizeof(t_list));
	list_1->data = "55555";
	list_2 = (t_list *)malloc(sizeof(t_list));
	list_1->next = list_2;
	list_2->data = "4444";
	list_3 = (t_list *)malloc(sizeof(t_list));
	list_2->next = list_3;
	list_3->data = "333";
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
	while (*ptr != 0)
	{
		printf("data : %s\n", (*ptr)->data);
		*ptr = (*ptr)->next;
	}
	*ptr = list_1;
	printf("&list_2 : %p\tlist_2 : %p\n", &list_2, list_2);
	printf("ptr : %p\t*ptr : %p\n", ptr, *ptr);
	ft_list_remove_if(ptr, "333", &rm_cmp);
	printf("yay\n");
	printf("&list_1 : %p\tlist_1 : %p\n", &list_1, list_1);
	printf("ptr : %p\t*ptr : %p\n", ptr, *ptr);
	while (*ptr != 0)
	{
		printf("data : %s\n", (*ptr)->data);
		*ptr = (*ptr)->next;
	}
	return (0);
}
