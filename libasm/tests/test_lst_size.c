/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lst_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 15:57:06 by user42            #+#    #+#             */
/*   Updated: 2020/09/15 16:00:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libasm.h"
#include "test.h"

void	test_lst_size(void)
{
	t_list	*ptr;
	t_list	**head;

	if (!(head = (t_list **)malloc(sizeof(t_list *))))
		return ;
	ptr = lst_new("1");
	*head = ptr;
	ptr->next = lst_new("2");
	ptr = ptr->next;
	ptr->next = lst_new("3");
	ptr = ptr->next;
	ptr->next = lst_new("4");
	ptr = *head;
	while (ptr != 0)
	{
		printf("data : %s\n", (char *)ptr->data);
		ptr = ptr->next;
	}
	printf("lst size = %d\n", ft_list_size(*head));
	free_list(head);
}
