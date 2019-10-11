/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:03:01 by asablayr          #+#    #+#             */
/*   Updated: 2019/10/11 18:15:07 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_itoa(int n)
{
		int temp;
		int len;
		char *str;

		temp = n;
		len = 0;
		while (temp /= 10 > 1)
			len++;
		temp = n;
		if (!((char *)malloc(sizeof(char) * len + 1)))
			return(NULL);
		if (n < 0)

		while (len > 0)
			str[len]
