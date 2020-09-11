#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include "libasm.h"

extern int	errno;

void	test_read(void)
{
	int	ret;
	int	fd;
	char	*buf;

	buf = (char *)malloc(5);
	fd = open("./test.c", O_RDONLY);
	ret = ft_read(fd, buf, 4);
	printf("buf : '%s'\tret : %d\terrno : %d\n", buf, ret, errno);
	ret = read(fd, buf, 4);
	printf("muf : '%s'\tret : %d\terrno : %d\n", buf, ret, errno);
	free(buf);
	close(fd);
	buf = (char *)malloc(5);
	fd = -1;
	ret = ft_read(fd, buf, 4);
	printf("buf : '%s'\tret : %d\terrno : %d\n", buf, ret, errno);
	ret = read(fd, buf, 4);
	printf("muf : '%s'\tret : %d\terrno : %d\n", buf, ret, errno);
	free(buf);
	buf = (char *)malloc(5);
	fd = 42;
	ret = ft_read(fd, buf, 4);
	printf("buf : '%s'\tret : %d\terrno : %d\n", buf, ret, errno);
	ret = read(fd, buf, 4);
	printf("muf : '%s'\tret : %d\terrno : %d\n", buf, ret, errno);
	free(buf);
	buf = (char *)malloc(5);
	fd = open("./test.c", O_RDONLY);
	ret = ft_read(fd, buf, -4);
	printf("buf : '%s'\tret : %d\terrno : %d\n", buf, ret, errno);
	ret = read(fd, buf, -4);
	printf("muf : '%s'\tret : %d\terrno : %d\n", buf, ret, errno);
	free(buf);
	close(fd);
	buf = (char *)malloc(5);
	fd = open("./test.c", O_RDONLY);
	ret = ft_read(fd, NULL, 4);
	printf("buf : '%s'\tret : %d\terrno : %d\n", buf, ret, errno);
	ret = read(fd, NULL, 4);
	printf("muf : '%s'\tret : %d\terrno : %d\n", buf, ret, errno);
	free(buf);
	close(fd);
	printf("\n\n");
	buf = (char *)malloc(5);
	fd = open("./test.c", O_RDONLY);
	ret = ft_read(fd, buf, 42);
	printf("buf : '%s'\tret : %d\terrno : %d\n", buf, ret, errno);
	ret = read(fd, buf, 42);
	printf("muf : '%s'\tret : %d\terrno : %d\n", buf, ret, errno);
	free(buf);
	close(fd);
	fd = open("./test.c", O_RDONLY);
	ret = ft_read(fd, buf, 42);
	printf("buf : '%s'\tret : %d\terrno : %d\n", buf, ret, errno);
	ret = read(fd, buf, 42);
	printf("muf : '%s'\tret : %d\terrno : %d\n", buf, ret, errno);
	close(fd);
}
