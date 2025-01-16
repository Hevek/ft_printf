# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: restevez <restevez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/30 02:44:13 by restevez          #+#    #+#              #
#    Updated: 2025/01/03 11:37:18 by restevez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c \
		utils.c

CC = cc

FLAGS = -Wall -Wextra -Werror

OBJECTS = $(SRC:%.c=%.o)

INCLUDES = 	libft/libft.h \
			ft_printf.h

RM = rm -f

all: $(NAME)

$(NAME): $(OBJECTS)

%.o:%.c $(INCLUDES)
	${CC} ${FLAGS} -c $< -o $@
	ar rc $(NAME) $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
