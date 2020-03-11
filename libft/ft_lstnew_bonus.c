/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:04:00 by asablayr          #+#    #+#             */
/*   Updated: 2019/10/17 13:07:19 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*n_link;

	if (!(n_link = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	n_link->content = content;
	n_link->next = NULL;
	return (n_link);
}
