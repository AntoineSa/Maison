/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 15:59:04 by user42            #+#    #+#             */
/*   Updated: 2020/09/15 15:59:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libasm.h"

void	test_strlen(void)
{
	char	*s;

	s = "bonjour";
	printf("len of '%s' : %lu\treal : %lu\n", s, ft_strlen(s), strlen(s));
	s = "";
	printf("len of '%s' : %lu\treal : %lu\n", s, ft_strlen(s), strlen(s));
}
