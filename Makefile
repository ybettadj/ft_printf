# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/23 03:19:20 by ybettadj          #+#    #+#              #
#    Updated: 2018/03/23 03:19:21 by ybettadj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libftprintf.a

NAME2 = ft_printf

LIBFT = ./libft/libft.a

INCLUDE = ./include/ft_printf.h

SRC =	./src/ft_printf.c ./src/init.c ./src/valid.c ./src/parcer.c \
		./src/begin.c ./src/s.c ./src/pourc_conv.c ./src/d_conv.c \
		./src/modif.c ./src/x_conv.c ./src/u_conv.c ./src/o_conv.c \
		./src/c_conv.c ./src/p_conv.c ./src/void_width.c ./src/d_conv2.c \
		./src/d_conv3.c ./src/modifhelp.c ./src/o_conv2.c ./src/p_conv2.c \
		./src/parcer2.c ./src/pourc_conv2.c ./src/x_conv3.c ./src/x_conv2.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME): $(OBJ)
	make -C ./libft/
	#$(CC) -o $(NAME2) $(FLAGS) $(LIBFT) $(OBJ)
	$(CC) -c $(SRC) -I $(INCLUDE)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

clean :
	make clean -C ./libft
	rm -rf $(OBJ)

fclean : clean
	make fclean -C ./libft
	rm -rf $(NAME)
	rm -rf *.o

re : fclean all
