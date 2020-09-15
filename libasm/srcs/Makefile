SRCS = ft_strlen.s \
       ft_strcpy.s \
       ft_strcmp.s \
       ft_write.s \
       ft_read.s \
       ft_strdup.s \

SRCS_BONUS = ft_atoi_base.s \
	     ft_list_push_front.s \
	     ft_list_size.s \
	     ft_list_sort.s \
	     ft_list_remove_if.s \

OBJS = $(SRCS:.s=.o)
BONUS_OBJS = $(SRCS_BONUS:.s=.o)

SRCS_PATH = ./
OBJS_PATH = ./
INCL_PATH = ../incl/

AS = nasm
ASFLAGS = -felf64
#ASFLAGS = -f macho64

NAME = libasm.a

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(addprefix $(OBJS_PATH), $(OBJS))
#	$(LD) $(LDFLAGS) $(addprefix $(OBJS_PATH), $(OBJS))

$(SRCS):
	$(AS) $(ASFLAGS) $@

$(SRCS_BONUS):
	$(AS) $(ASFLAGS) $(addprefix $(SRCS_PATH), $@)

bonus : $(OBJS) $(BONUS_OBJS)
	ar -rc $(NAME) $(addprefix $(OBJS_PATH), $(OBJS)) $(addprefix $(OBJS_PATH), $(BONUS_OBJS))
#	$(LD) $(LDFLAGS) $(addprefix $(OBJS_PATH), $(OBJS)) $(addprefix $(OBJS_PATH), $(OBJS_BONUS))

clean :
	rm -rf $(addprefix $(OBJS_PATH), $(OBJS))
	rm -rf $(addprefix $(OBJS_PATH), $(BONUS_OBJS))

fclean : clean
	rm -f $(NAME)

re : fclean all
