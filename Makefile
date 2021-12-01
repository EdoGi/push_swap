SRCS	=	\
			stack_manager.c	\
			clean_leaks.c \
			\

BONUS	=	
						
OBJS 	= 	${SRCS:.c=.o}
OBJS_B	= 	${BONUS:.c=.o}
CC 		= 	gcc
RM		= 	rm -rf
NAME	=	push_swap

CFLAGS	= 	-Wall -Wextra -Werror

HEADERS	=	./

.c.o : 		${SRCS}
			${CC} ${CFLAGS} -I ${HEADERS} -c $< -o $@

all	:		${NAME} bonus

$(NAME) :	${SRCS}
			${CC} ${CFLAGS} -I ${HEADERS} -c $< -o $@

bonus :		${SRCS_BONUS}
			${CC} ${CFLAGS} -I ${HEADERS} -c $< -o $@

clean :	
			${RM} ${OBJS} ${OBJS_B}

fclean :	clean 
			${RM} ${NAME}

re :		fclean all

.PHONY :	all clean fclean re



