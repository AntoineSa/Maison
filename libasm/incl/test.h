#ifndef TEST_H
# define TEST_H

void	test_write(void);
void	test_read(void);
void	test_strlen(void);
void	test_strcpy(void);
void	test_strcmp(void);
void	test_strdup(void);

void	test_atoi_base(void);
t_list	*lst_new(void *data);
int	f_cmp(void *ref, void *data);
void	free_list(t_list **head);
void	test_lst_push_front(void);
void	test_lst_size(void);
void	test_lst_sort(void);
void	test_lst_remove_if(void);
#endif
