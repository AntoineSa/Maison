/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:03:01 by asablayr          #+#    #+#             */
/*   Updated: 2019/10/16 14:19:03 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	ft_write(char *str, int len, unsigned int n)
{
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = (n % 10) + 48;
		len--;
		n = n / 10;
	}
}

char		*ft_itoa(int n)
{
	unsigned int	temp;
	int				len;
	char			*str;

	len = 1;
	temp = (n >= 0 ? n : -n);
	while ((temp /= 10) > 0)
		len++;
	temp = (n >= 0 ? n : -n);
	if (n < 0)
	{
		if (!(str = (char *)malloc(sizeof(char) * len + 2)))
			return (NULL);
	}
	else
	{
		if (!(str = (char *)malloc(sizeof(char) * len + 1)))
			return (NULL);
	}
	if (n < 0)
		len++;
	ft_write(str, len, temp);
	if (n < 0)
		str[0] = '-';
	return (str);
}
