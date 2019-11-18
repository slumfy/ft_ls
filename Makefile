# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/19 12:10:29 by rvalenti          #+#    #+#              #
#    Updated: 2019/11/18 15:40:09 by rvalenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
SRC =	main.c\
		ft_ls.c\
		utils.c\
		utils2.c\
		rev_list.c\
		print_list.c\
		print_detail.c

LIBFT = ./libft/
CC = gcc -Wall -Werror -Wextra -fsanitize=address -g

INCLUDES = ./
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
			make -C $(LIBFT)
			$(CC) $(OBJ) -o$(NAME) -I$(LIBFT) -I$(INCLUDES) -L $(LIBFT) -lft

%.o: %.c
		$(CC) -c $< -o $@

clean:
		rm -rf $(OBJ)
		make clean -C $(LIBFT)

fclean:	clean
		rm -f $(NAME)
		make fclean -C $(LIBFT)
re:	fclean all
