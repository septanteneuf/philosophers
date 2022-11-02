NAME		=	philo

HEADER		=	./include/

CC			=	gcc

SRCS		=	srcs/main.c \
				srcs/activity.c \
				srcs/threads.c \
				srcs/init_parse.c \
				srcs/utils_philo.c \
				srcs/utils.c \

OBJS		=	$(SRCS:.c=.o)

RM		=	rm -f

CFLAGS		=	-Werror -Wall -Wextra -g -I $(HEADER) -pthread

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean		:
				${RM} $(OBJS)

fclean		:	clean
				${RM} $(NAME)

re			:	fclean all

.PHONY		: 	all clean fclean re