#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/19 12:05:23 by jde-maga          #+#    #+#              #
#    Updated: 2016/04/29 16:50:11 by jde-maga         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC_PATH = src/
SRC_NAME = main.c operations.c solver.c struct_init.c input_parser.c get_properties.c get_properties_pile.c solver_operations.c solver_properties.c solver_precision.c
OBJ_PATH = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./includes
NAME = push_swap
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
LIBS = libft/libft.a

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		@mkdir $(OBJ_PATH) 2> /dev/null || true
		$(CC) -c $(CFLAGS) $< -o $@

clean :
		rm -rf $(OBJ_PATH)

fclean : clean
		rm -rf $(NAME)

re : fclean all
