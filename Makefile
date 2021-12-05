SRCS	=	\
			stack_manager.c	\
			stack_constructor.c \
			moves_1.c \
			moves_2.c \
			main.c \
			parsing.c \
			utils.c \
			\

BONUS	=	\
						
OBJS 	= 	${SRCS:.c=.o}
OBJS_B	= 	${BONUS:.c=.o}
CC 		= 	gcc
RM		= 	rm -rf
NAME	=	push_swap

CFLAGS	= 	-Wall -Wextra -Werror

HEADERS	=	./

.c.o : 		${SRCS}
			${CC} ${CFLAGS} -I ${HEADERS} -c $< -o $@

all	:		${NAME}

$(NAME) :	${OBJS}
			${CC} ${CFLAGS} -I ${HEADERS} ${OBJS} -o $@

bonus :		${OBJS_B}
			${CC} ${CFLAGS} -I ${HEADERS} ${OBJS_B} -o $@

clean :	
			${RM} ${OBJS} ${OBJS_B}

fclean :	clean 
			${RM} ${NAME}

re :		fclean all

.PHONY :	all clean fclean re



