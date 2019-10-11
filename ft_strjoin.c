/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 10:34:27 by asablayr          #+#    #+#             */
/*   Updated: 2019/10/11 12:03:21 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
		char *str;
		int i;

		i = 0;
		if(!(str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)))))
				return (NULL);
		while (*s1 != '\0')
		{
				str[i] = *s1;
				i++;
				s1++;
		}
		while (*s2 != '\0')
		{
				str[i] = *s2;
				i++;
				s2++;
		}
		str[i] = '\0';
		return (str);
}
