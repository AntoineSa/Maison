/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 10:19:54 by asablayr          #+#    #+#             */
/*   Updated: 2020/02/13 17:29:00 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		ft_pow(int n, int p)
{
	int nb;

	nb = 1;
	while (p--)
		nb *= n;
	return (nb);
}

static int		set_neg(const char *s, int *neg)
{
	int	i;

	i = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
		i++;
	if (s[i] == '-')
		*neg = 1;
	if (s[i] == '+' || *s == '-')
		i++;
	return (i);
}

static float	get_float(const char *str)
{
	float	res;
	float	i;
	int		nb;

	res = 0;
	nb = 1;
	while (*str >= '0' && *str <= '9')
	{
		i = *str++ - '0';
		i /= ft_pow(10, nb++);
		res += i;
	}
	return (res);
}

float			ft_atof(const char *str)
{
	int		neg;
	float	res;

	neg = 0;
	res = 0;
	str += set_neg(str, &neg);
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	if (*str++ == '.')
		res += get_float(str);
	if (neg == 1)
		res = -res;
	return (res);
}

int				ft_atoi(const char *str)
{
	int neg;
	int	res;

	neg = 0;
	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-')
		neg = 1;
	if (*str == '+' || *str == '-')
		str++;
	if (*str < '0' || *str > '9')
		return (res);
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	if (neg == 1)
		res = -res;
	return (res);
}
