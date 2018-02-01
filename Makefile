# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/11 16:01:05 by tbailly-          #+#    #+#              #
#    Updated: 2018/02/01 22:35:41 by tbailly-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	fdf
FLAGS	=	-Werror -Wall -Wextra
LIB		=	-L libft/ -lft
MLX		=	-lmlx -framework OpenGL -framework AppKit

SRCS 	= 	fdf.c \
			ft_get_map.c \
			ft_draw_image.c \
			ft_draw_line.c \
			ft_apply_iso_matrix.c \
			ft_resize.c \
			ft_rotate.c \
			ft_calculate_color.c \
			ft_color_datas.c \
			utilities.c

OBJS 	= 	$(SRCS:.c=.o)

all		: $(NAME)

$(NAME) : $(OBJS)
	make -C libft/
	gcc $(FLAGS) -o $(NAME) $(OBJS) -I ./ $(MLX) $(LIB)

%.o		: %.c
	gcc -c $(FLAGS) $(SRCS)

clean	:
	make -C libft/ clean
	rm -rf $(OBJS)

fclean	: clean
	make -C libft/ fclean
	rm -f $(NAME)

re		: fclean all

.PHONY	: all lib clean fclean re
