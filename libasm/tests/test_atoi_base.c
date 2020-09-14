#include <stdio.h>
#include "libasm.h"

static void	wrong_base(void)
{
	char	*s;
	char	*base;
	int	res;

	s = "   1";
	base = "0";
	res = ft_atoi_base(s, base);
	printf("s : '%s' base : %s res : %d\n", s, base, res);
	s = "   1";
	base = "011";
	res = ft_atoi_base(s, base);
	printf("s : '%s' base : %s res : %d\n", s, base, res);
	s = "42";
	base = "01234567489";
	res = ft_atoi_base(s, base);
	printf("s : '%s' base : %s res : %d\n", s, base, res);
}

static void	out_of_base(void)
{
	char	*s;
	char	*base;
	int	res;

	s = "   12";
	base = "01";
	res = ft_atoi_base(s, base);
	printf("s : '%s' base : %s res : %d\n", s, base, res);
	s = "aze 42";
	base = "0123456789";
	res = ft_atoi_base(s, base);
	printf("s : '%s' base : %s res : %d\n", s, base, res);
}

static void	negative(void)
{
	char	*s;
	char	*base;
	int	res;

	s = "-42";
	base = "0123456789";
	res = ft_atoi_base(s, base);
	printf("s : '%s' base : %s res : %d\n", s, base, res);
	s = "  -11";
	base = "01";
	res = ft_atoi_base(s, base);
	printf("s : '%s' base : %s res : %d\n", s, base, res);
}

void	test_atoi_base(void)
{
	char	*s;
	char	*base;
	int	res;

	wrong_base();
	negative();
	out_of_base();
	s = "   1011";
	base = "01";
	res = ft_atoi_base(s, base);
	printf("s : '%s' base : %s res : %d\n", s, base, res);
	s = "  10";
	base = "01";
	res = ft_atoi_base(s, base);
	printf("s : '%s' base : %s res : %d\n", s, base, res);
	s = "42";
	base = "0123456789";
	res = ft_atoi_base(s, base);
	printf("s : '%s' base : %s res : %d\n", s, base, res);
	s = "42";
	base = "0123456789ABCDEF";
	res = ft_atoi_base(s, base);
	printf("s : '%s' base : %s res : %d\n", s, base, res);
}


