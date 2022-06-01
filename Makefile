# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smokashi <smokashi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/01 13:29:50 by smokashi          #+#    #+#              #
#    Updated: 2022/06/01 14:49:13 by smokashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_utils.c


OBJS = ${SRCS:.c=.o}


CC = cc
RM = rm -rf
NAME = libftprintf.a

all : ${NAME}

${NAME} :	${OBJS}
			ar rcs ${NAME} ${OBJS}

clean :		
			${RM} ${OBJS}

fclean:		clean
			$(RM) $(NAME)

re: 		fclean all

.PHONY : all clean fclean re

			

