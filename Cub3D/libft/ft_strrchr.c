/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:27:40 by asablayr          #+#    #+#             */
/*   Updated: 2019/10/10 10:29:11 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char *cur;

	cur = (char *)s;
	while (*cur != '\0')
		cur++;
	while (cur != s && *cur != c)
		cur--;
	if (cur == s && *cur != c)
		return ((void *)0);
	else
		return (cur);
}
