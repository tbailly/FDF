# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 14:55:46 by tbailly-          #+#    #+#              #
#    Updated: 2018/01/11 18:46:53 by tbailly-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER_PATH = ./

SRC_PATH = ./
SRCS = $(SRC_PATH)ft_memset.c \
	   $(SRC_PATH)ft_bzero.c \
	   $(SRC_PATH)ft_memcpy.c \
	   $(SRC_PATH)ft_memccpy.c \
	   $(SRC_PATH)ft_memmove.c \
	   $(SRC_PATH)ft_memchr.c \
	   $(SRC_PATH)ft_memcmp.c \
	   $(SRC_PATH)ft_strlen.c \
	   $(SRC_PATH)ft_strdup.c \
	   $(SRC_PATH)ft_strcpy.c \
	   $(SRC_PATH)ft_strncpy.c \
	   $(SRC_PATH)ft_strcat.c \
	   $(SRC_PATH)ft_strncat.c \
	   $(SRC_PATH)ft_strlcat.c \
	   $(SRC_PATH)ft_strchr.c \
	   $(SRC_PATH)ft_strrchr.c \
	   $(SRC_PATH)ft_strstr.c \
	   $(SRC_PATH)ft_strnstr.c \
	   $(SRC_PATH)ft_strcmp.c \
	   $(SRC_PATH)ft_strncmp.c \
	   $(SRC_PATH)ft_atoi.c \
	   $(SRC_PATH)ft_isalpha.c \
	   $(SRC_PATH)ft_isdigit.c \
	   $(SRC_PATH)ft_isalnum.c \
	   $(SRC_PATH)ft_isascii.c \
	   $(SRC_PATH)ft_isprint.c \
	   $(SRC_PATH)ft_toupper.c \
	   $(SRC_PATH)ft_tolower.c \
	   \
	   $(SRC_PATH)ft_memalloc.c \
	   $(SRC_PATH)ft_memdel.c \
	   $(SRC_PATH)ft_strnew.c \
	   $(SRC_PATH)ft_strdel.c \
	   $(SRC_PATH)ft_strclr.c \
	   $(SRC_PATH)ft_striter.c \
	   $(SRC_PATH)ft_striteri.c \
	   $(SRC_PATH)ft_strmap.c \
	   $(SRC_PATH)ft_strmapi.c \
	   $(SRC_PATH)ft_strequ.c \
	   $(SRC_PATH)ft_strnequ.c \
	   $(SRC_PATH)ft_strsub.c \
	   $(SRC_PATH)ft_strjoin.c \
	   $(SRC_PATH)ft_strtrim.c \
	   $(SRC_PATH)ft_strsplit.c \
	   $(SRC_PATH)ft_itoa.c \
	   $(SRC_PATH)ft_putchar.c \
	   $(SRC_PATH)ft_putstr.c \
	   $(SRC_PATH)ft_putendl.c \
	   $(SRC_PATH)ft_putnbr.c \
	   $(SRC_PATH)ft_putchar_fd.c \
	   $(SRC_PATH)ft_putstr_fd.c \
	   $(SRC_PATH)ft_putendl_fd.c \
	   $(SRC_PATH)ft_putnbr_fd.c \
	   \
	   $(SRC_PATH)ft_swap.c \
	   $(SRC_PATH)ft_strup.c \
	   $(SRC_PATH)ft_strlw.c \
	   $(SRC_PATH)ft_strcleandbl.c \
	   $(SRC_PATH)ft_strrepchr.c \
	   $(SRC_PATH)ft_putstrarr.c \
	   $(SRC_PATH)ft_itoa_base.c \
	   $(SRC_PATH)ft_abs.c \
	   \
	   $(SRC_PATH)ft_lstnew.c \
	   $(SRC_PATH)ft_lstdelone.c \
	   $(SRC_PATH)ft_lstdel.c \
	   $(SRC_PATH)ft_lstadd.c \
	   $(SRC_PATH)ft_lstiter.c \
	   $(SRC_PATH)ft_lstmap.c \
	   \
	   $(SRC_PATH)get_next_line.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	@gcc $(FLAGS) -c -I $(HEADER_PATH) $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
