# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/19 12:10:29 by rvalenti          #+#    #+#              #
#    Updated: 2019/04/23 15:15:34 by rvalenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
SRC =	main.c\
		ft_ls.c\
		utils.c\
		utils2.c\
		print_list.c

LIBFT = ./libft/
CC = gcc -Wall -Werror -Wextra -g

INCLUDES = ./
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
			make -C $(LIBFT)
			$(CC) $(OBJ) -o$(NAME) -I$(LIBFT) -I$(INCLUDES) -L $(LIBFT) -lft

%.o: %.c fdf.h
		$(CC) -c $< -o $@

clean:
		rm -rf $(OBJ)
		make clean -C $(LIBFT)

fclean:	clean
		rm -f $(NAME)
		make fclean -C $(LIBFT)
re:	fclean all
