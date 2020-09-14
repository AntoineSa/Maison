#include "libasm.h"
#include "test.h"
#include <stdio.h>
#include <stdlib.h>

void	test_lst_push_front(void)
{
	t_list	*cur;
	t_list	**head;

	if (!(head = (t_list **)malloc(sizeof(t_list *))))
		return;
	cur = lst_new("bonjour");
	*head = cur;
	cur->next = lst_new("aze");
	cur = cur->next;
	cur->next = lst_new("qsd");
	cur = cur->next;
	cur->next = lst_new("wxc");
	cur = lst_new("rank 3");
	ft_list_push_front(head, cur);
	cur = lst_new("rank 2");
	ft_list_push_front(head, cur);
	cur = lst_new("rank 1");
	ft_list_push_front(head, cur);
	cur = *head;
	while (cur)
	{
		printf("data : '%s'\n", (char *)cur->data);
		cur = cur->next;
	}
	free_list(head);
}
