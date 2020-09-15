/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 15:59:32 by user42            #+#    #+#             */
/*   Updated: 2020/09/15 16:02:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

extern int	errno;

void		test_write(void)
{
	int	nb;

	nb = ft_write(1, "bonjour\n", 10);
	printf("nb = ft_test(1, 'bonjour\\n', 10) = %d\n", nb);
	nb = write(1, "bonjour\n", 10);
	printf("nb = write(1, 'bonjour\\n', 10) = %d\n", nb);
	nb = ft_write(1, "bonjour\n", -10);
	printf("nb = ft_test(1, 'bonjour\\n', -10) = %d\terrno : %d\n", nb, errno);
	nb = write(1, "bonjour\n", -10);
	printf("nb = write(1, 'bonjour\\n', -10) = %d\terrno : %d\n", nb, errno);
	nb = ft_write(-1, "bonjour\n", 10);
	printf("nb = ft_test(-1, 'bonjour\\n', 10) = %d\terrno : %d\n", nb, errno);
	nb = write(-1, "bonjour\n", 10);
	printf("nb = write(-1, 'bonjour\\n', 10) = %d\terrno : %d\n", nb, errno);
	nb = ft_write(42, "bonjour\n", 10);
	printf("nb = ft_test(42, 'bonjour\\n', -10) = %d\terrno : %d\n", nb, errno);
	nb = write(42, "bonjour\n", 10);
	printf("nb = ft_test(42, 'bonjour\\n', -10) = %d\terrno: %d\n", nb, errno);
	nb = ft_write(1, NULL, 10);
	printf("nb = ft_test(1, NULL, 10) = %d\terrno : %d\n", nb, errno);
	nb = write(1, NULL, 10);
	printf("nb = ft_test(1, NULL, 10) = %d\terrno: %d\n", nb, errno);
}
