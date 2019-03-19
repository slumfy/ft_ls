# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/19 12:10:29 by rvalenti          #+#    #+#              #
#    Updated: 2019/03/19 12:16:31 by rvalenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
SRC =	ft_ls.c

LIBFT = ./libft/
CC = gcc -Wall -Werror -Wextra
INCLUDES = ./
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
			make -C $(LIBFT)
				$(CC) $(OBJ) -o$(NAME) -I$(LIBFT) -I$(INCLUDES) -L $(LIBFT)

%.o: %.c fdf.h
		$(CC) -c $< -o $@

clean:
		rm -rf $(OBJ)
		make clean -C $(LIBFT)

fclean:	clean
		rm -f $(NAME)
		make fclean -C $(LIBFT)
re:	fclean all
