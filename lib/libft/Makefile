NAME		= libft.a
SRCS		= $(shell find "." -name "*.c" ! -name "ft_lst*.c")
BONUS_SRCS	= $(shell find "." -name "ft_lst*.c")
OBJS		= $(SRCS:.c=.o)
INCS		= -I.
CFLAGS		= -Wall -Wextra -Werror $(INCS)
AR			= ar rcs
RM			= rm -f
CC			= cc

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus:	${BONUS_OBJS}
	$(AR) $(NAME) $(BONUS_OBJS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re