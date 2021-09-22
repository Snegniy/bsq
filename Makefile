# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: imelody <imelody@student.21-school.ru>     +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2021/09/21 01:09:56 by imelody           #+#    #+#             #
#   Updated: 202#   Updated: 2021/09/22 05:48:15 by imelody          ###   ########.fr       #                                                              #
# ************************************************************************** #
NAME	=	bsq

CC = gcc

SRC	=		main.c algorithm.c check_file.c read_file.c map.c map_ex.c

INC		=	-I /include/

OBJ = $(patsubst %.c, %.o, $(SRC))

CFLAGS		= -Wall -Werror -Wextra -c
LFLAGS		= -Wall -Werror -Wextra -o

all: $(NAME)

 $(NAME):
	$(CC) $(CFLAGS) $(SRC)
	$(CC) $(LFLAGS) $(NAME) $(OBJ) $(INC)

clean:
	@rm -f *.o

fclean: clean
	@rm $(NAME)

re: fclean all

.PHONY: all clean fclean re