/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 09:44:52 by asablayr          #+#    #+#             */
/*   Updated: 2019/10/24 18:11:02 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len > 0)
	{
		i = 0;
		while (haystack[i] == needle[i] && needle[i] &&
				haystack[i] && len - i > 0)
			i++;
		if (needle[i] == '\0')
			return ((char *)haystack);
		else
		{
			haystack++;
			len--;
		}
	}
	return (NULL);
}
