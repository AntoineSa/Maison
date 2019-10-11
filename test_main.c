#include <stdio.h>

char 	**ft_split(char const *s, char c);

int	main()
{
		char str1[] = "bonjour";
		char str2[] = "qwe/qwe/asd/zxc/";
		char str3[] = "12345678901234567890";
		char **tab;

		printf("feck \n");
		tab = ft_split(str1, 'o');
		printf("str1 test 1 -o- %s\t%s\t%s\n", tab[0], tab[1], tab[2]);
		tab = ft_split(str1, 'b');
		printf("str1 test 2 -b- %s\n", tab[0]);
		tab = ft_split(str2, '/');
		printf("str2 test 1 -/- %s\t%s\t%s\t%s\n", tab[0], tab[1], tab[2], tab[4]);
		tab = ft_split(str2, 'a');
		printf("str2 test 2 -a- %s\t%s\n", tab[0], tab[1]);
		tab = ft_split(str3, '5');
		printf("str3 test 1 -5- %s\t%s\t%s\n", tab[0], tab[1], tab[2]);

		return (0);
}
