/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lst_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 15:57:25 by user42            #+#    #+#             */
/*   Updated: 2020/09/15 15:57:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdio.h>
#include <stdlib.h>
#include "test.h"

void	test_lst_sort(void)
{
	t_list	*cur;
	t_list	**head;

	head = (t_list **)malloc(sizeof(t_list *));
	cur = lst_new("1");
	*head = cur;
	cur->next = lst_new("333");
	cur = cur->next;
	cur->next = lst_new("22");
	cur = cur->next;
	cur->next = lst_new("7777777");
	cur = cur->next;
	cur->next = lst_new("1");
	cur = cur->next;
	cur->next = lst_new("4444");
	ft_list_sort(head, &f_cmp);
	cur = *head;
	while (cur != 0)
	{
		printf("data : %s\n", (char *)cur->data);
		cur = cur->next;
	}
	free_list(head);
}

