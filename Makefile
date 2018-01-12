# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/11 16:01:05 by tbailly-          #+#    #+#              #
#    Updated: 2018/01/12 15:26:26 by tbailly-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	mlx
FLAGS	=	-Werror -Wall -Wextra
LIB		=	-L libft/ -lft
MLX		=	-lmlx -framework OpenGL -framework AppKit

SRCS 	= 	fdf.c \
			ft_get_map.c

OBJS 	= 	$(SRCS:.c=.o)

all		: $(NAME)

$(NAME) : lib $(OBJS)
	gcc -o $(NAME) $(OBJS) -I ./ $(MLX) $(LIB)
	#gcc $(FLAGS) -o $(NAME) $(OBJS) -I ./ $(MLX) $(LIB)

%.o		: %.c
	gcc -c $(SRCS)
	#gcc -c $(FLAGS) $(SRCS)

lib		:
	make -C libft/ re

clean	:
	rm -rf $(OBJS)

fclean	: clean
	rm -f $(NAME)

re		: fclean all

.PHONY	: all lib clean fclean re
