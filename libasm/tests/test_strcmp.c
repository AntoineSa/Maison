/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 15:57:51 by user42            #+#    #+#             */
/*   Updated: 2020/09/15 18:27:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libasm.h"

void	test_strcmp(void)
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
}
