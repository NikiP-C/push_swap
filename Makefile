# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nphilipp <nphilipp@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/03/15 12:27:34 by nphilipp      #+#    #+#                  #
#    Updated: 2021/03/15 13:58:13 by nphilipp      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = ./push_swap.c

LIBFTDIR = ./libft/

FLAGS = -Wall -Werror -Wextra


all: $(NAME)

$(NAME): $(SRC)
	make -C $(LIBFTDIR)
	gcc $(FLAGS) -Llibft -lft $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ)
	make -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean

re: fclean all
