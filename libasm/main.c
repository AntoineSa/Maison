#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

unsigned long	ft_strlen(char *s);
int	ft_strcmp(char *s1, char *s2);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strdup(char *s);
int	ft_write(int fd, const void *buf, size_t count);
int	ft_read(int fd, void *buf, size_t count);

void	ft_write_test(void)
{
	int	len;
	char	*s = "bonjour";

	len = ft_write(1, NULL, 5);
	printf("NULL\tret = %d\n", len);
	len = write(1, NULL, 5);
	printf("NULL\tret = %d\n", len);
	len = ft_write(1, s, 5);
	ft_write(1, "\n", 1);
	printf("ret = %d\n", len);
	len = ft_write(-1, s, 5);
	printf("fd = -1\tret = %d\n", len);
//	len = ft_write(1, s, -5);
//	printf("length = -5\tret = %d\n", len);
}

void	ft_read_test(void)
{
	int	ret;
	int	fd;
	char	*buf;

	buf = (char *)malloc(5);
	fd = open("./main.c", O_RDONLY);
	ret = ft_read(fd, buf, 4);
	printf("buf : '%s'\tret : %d\n", buf, ret);
	free(buf);
	close(fd);
}

void	ft_strlen_test(void)
{
	char	*s;

	s = "bonjour";
	printf("len of '%s': %lu\treal : %lu\n", s, ft_strlen(s), strlen(s));
	s = "";
	printf("len of '%s': %lu\treal : %lu\n", s, ft_strlen(s), strlen(s));
	s = NULL;
	printf("len of '%s': %lu\n", s, ft_strlen(s));
}

void	ft_strcpy_test(void)
{
	char	*s1;
	char	*s2;
	char	*s3;

	s1 = "bonjour";
	s2 = (char *)malloc(ft_strlen(s1));
	s3 = ft_strcpy(s2, s1);
	printf("s : '%s'\ns2 : '%s'\ns3 : '%s'\n", s1, s2, s3);
	free(s2);
	s1 = "";
	s2 = (char *)malloc(ft_strlen(s1));
	s3 = ft_strcpy(s2, s1);
	printf("s : '%s'\ns2 : '%s'\ns3 : '%s'\n", s1, s2, s3);
	free(s2);
	s1 = NULL;
	s2 = (char *)malloc(ft_strlen(s1));
	s3 = ft_strcpy(s2, s1);
	printf("s : '%s'\ns2 : '%s'\ns3 : '%s'\n", s1, s2, s3);
}

void	ft_strcmp_test(void)
{
	char	*s1;
	char	*s2;
	int	diff;

	s1 = "bonjour";
	s2 = "bonjour";
	diff = ft_strcmp(s1, s2);
	printf("s1 : '%s'\ts2 : '%s'\tdiff : %d\n", s1, s2, diff);
	s1 = "bon our";
	s2 = "bonjou";
	diff = ft_strcmp(s1, s2);
	printf("s1 : '%s'\ts2 : '%s'\tdiff : %d\n", s1, s2, diff);
	s1 = "bonjour";
	s2 = "bon ou";
	diff = ft_strcmp(s1, s2);
	printf("s1 : '%s'\ts2 : '%s'\tdiff : %d\n", s1, s2, diff);
	s1 = "";
	s2 = "bonjour";
	diff = ft_strcmp(s1, s2);
	printf("s1 : '%s'\ts2 : '%s'\tdiff : %d\n", s1, s2, diff);
	s1 = "";
	s2 = "";
	diff = ft_strcmp(s1, s2);
	printf("s1 : '%s'\ts2 : '%s'\tdiff : %d\n", s1, s2, diff);
}

void	ft_strdup_test(void)
{
	char	*s;
	char	*s2;

	s = "bonjour";
	s2 = ft_strdup(s);
	printf("s2 : %d\n", (int)s2);
	printf("s : '%s'\ts2 : '%s'\n", s, s2);
	free(s2);
	s = "";
	s2 = ft_strdup(s);
	printf("s : '%s'\ts2 : '%s'\n", s, s2);
	free(s2);
	s = NULL;
	s2 = ft_strdup(s);
	printf("s : '%s'\ts2 : '%s'\n", s, s2);
//	free(s2);
}

int	main(void)
{
	ft_write_test();
	printf("\n");
	ft_strlen_test();
	printf("\n");
	ft_strcpy_test();
	printf("\n");
	ft_strcmp_test();
	printf("\n");
	ft_read_test();
	printf("\n");
	ft_strdup_test();
	printf("\n");
	return (0);
}
