/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 10:19:54 by asablayr          #+#    #+#             */
/*   Updated: 2019/10/10 17:47:44 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v'
						|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == 43 || *str == 45)
		str++;
	if (*str < 48 || *str > 57)
		return (res);
	while (*str >= 48 && *str <= 57)
	{
		i++;
		res = res * 10 + (*str - 48);
		str++;
	}
	if (*(str - (i + 1)) == '-')
		res = -res;
	return (res);
}
