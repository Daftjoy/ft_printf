SRCS	=	ft_printf.c ft_atoi.c ft_isdigit.c ft_itoa.c ft_strlen.c ft_type_d.c ft_utils.c

OBJS	=	${SRCS:.c=.o}

NAME	=	libftprintf.a

CC		=	gcc

RM		=	rm -f

CFLAGS	= -Wall -Werror -Wextra 

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:	${NAME}

$(NAME):
	${CC} ${CFLAGS} -c ${SRCS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME} 

re:		fclean all

.PHONY:	all clean fclean re