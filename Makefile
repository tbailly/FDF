# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/11 16:01:05 by tbailly-          #+#    #+#              #
#    Updated: 2018/03/13 17:58:00 by tbailly-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	fdf
FLAGS	=	-Werror -Wall -Wextra

LIB		=	./libft/
LIB_LIB	=	$(addprefix $(LIB),libft.a)
LIB_LNK	=	-L libft/ -lft

MLX		=	./miniLibX/
MLX_LIB	=	$(addprefix $(MLX),mlx.a)
MLX_LNK	=	-L ./miniLibX -l mlx -framework OpenGL -framework AppKit

SRCS 	= 	fdf.c \
			ft_get_h_map.c \
			ft_create_point_array.c \
			ft_apply_iso_matrix.c \
			ft_resize.c \
			rotations.c \
			ft_draw_image.c \
			ft_draw_line.c \
			ft_calc_color.c \
			ft_color_datas.c \
			utils.c \
			free_utils.c

OBJS 	= 	$(SRCS:.c=.o)

all		: $(MLX_LIB) $(LIB_LIB) $(NAME)

$(NAME) : $(OBJS)
	gcc $(FLAGS) -o $(NAME) $(OBJS) -I ./ $(MLX_LNK) $(LIB_LNK)

%.o		: %.c
	gcc -c $(FLAGS) $(SRCS)

$(LIB_LIB):
	make -C $(LIB)

$(MLX_LIB):
	make -C $(MLX)

clean	:
	make -C $(LIB) clean
	make -C $(MLX) clean
	rm -rf $(OBJS)

fclean	: clean
	make -C $(LIB) fclean
	rm -f $(NAME)

re		: fclean all

.PHONY	: all lib clean fclean re
