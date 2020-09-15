/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lst_remove_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 15:56:50 by user42            #+#    #+#             */
/*   Updated: 2020/09/15 18:11:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libasm.h"

t_list	*lst_new(void *data)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	new->data = data;
	new->next = NULL;
	return (new);
}

int	f_cmp(void *ref, void *data)
{
	int	nb;

	nb = ft_strlen((char *)ref) - ft_strlen((char *)data);
	if (nb < 0)
		return (1);
	return (0);
}

void	init_list(t_list **head)
{
	t_list	*cur;

	cur = lst_new("22");
	*head = cur;
	cur->next = lst_new("55555");
	cur = cur->next;
	cur->next = lst_new("4444");
	cur = cur->next;
	cur->next = lst_new("333");
	cur = cur->next;
	cur->next = lst_new("7777777");
	cur = cur->next;
	cur->next = lst_new("1");
	cur = cur->next;
	cur->next = lst_new("4444");
}

void	free_list(t_list **head)
{
	t_list	*cur;
	t_list	*nxt;

	cur = *head;
	nxt = cur->next;
	while (nxt)
	{
		free(cur);
		cur = nxt;
		nxt = cur->next;
	}
	free(nxt);
	free(head);
}

void	test_lst_remove_if(void)
{
	char	*data_ref;
	t_list	*cur;
	t_list	**head;

	head = (t_list **)malloc(sizeof(t_list *));
	init_list(head);
	cur = *head;
	printf("before remove :\n");
	while (cur != 0)
	{
		printf("data : %s\n", (char *)cur->data);
		cur = cur->next;
	}
	data_ref = "333";
	ft_list_remove_if(head, data_ref, &f_cmp);
	cur = *head;
	printf("\nafter remove :\tdata_ref : '%s'\n", data_ref);
	while (cur != 0)
	{
		printf("data : %s\n", (char *)cur->data);
		cur = cur->next;
	}
	free_list(head);
}
