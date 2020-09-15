/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 15:58:19 by user42            #+#    #+#             */
/*   Updated: 2020/09/15 15:58:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libasm.h"
#include <stdlib.h>

void	test_strdup(void)
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
