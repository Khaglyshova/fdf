# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mroland- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/30 13:48:02 by mroland-          #+#    #+#              #
#    Updated: 2018/12/28 17:32:16 by mroland-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = *.c

OUT = *.o

INC = ./

FLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(SRC)
	@gcc $(FLAGS) -c $(SRC) -I $(INC)
	@ar rc $(NAME) $(OUT)

clean:
	@rm -fr $(OUT)

fclean: clean
	 @rm -fr $(NAME)

re: fclean all
