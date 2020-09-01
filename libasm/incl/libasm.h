#ifndef LIBASM_H
# define LIBASM_H

typedef struct	s_list
{
	void		*data;
	struct s_list	*next;
}		t_list;

unsigned long	ft_strlen(char *s);
char		*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(char *s1, char *s2);
int		ft_write(int fd, char *s, int len);
int		ft_read(int fd, void *buf, size_t len);
char		*ft_strdup(char *s);

int		ft_atoi_base(char *s, char *base);
void		ft_list_push_front(t_list **head, t_list *n_lst);
int		ft_list_size(t_list *head);
void		ft_list_sort(t_list **head, int (*f_cmp)());
t_list		*ft_list_remove_if(t_list *head, void (*del)(void *));

#endif
