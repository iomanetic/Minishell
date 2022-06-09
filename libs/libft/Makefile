# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tyuuki <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 22:00:06 by tyuuki            #+#    #+#              #
#    Updated: 2021/10/19 22:00:17 by tyuuki           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCE = ft_atoi.c \
		 ft_bzero.c \
		 ft_calloc.c \
		 ft_isalnum.c \
		 ft_isalpha.c \
		 ft_isascii.c \
		 ft_isdigit.c \
		 ft_isprint.c \
		 ft_itoa.c \
		 ft_memchr.c \
		 ft_memcmp.c \
		 ft_memcpy.c \
		 ft_memmove.c \
		 ft_memset.c \
		 ft_putchar_fd.c \
		 ft_putendl_fd.c \
		 ft_putnbr_fd.c \
		 ft_putstr_fd.c \
		 ft_strchr.c \
		 ft_strdup.c \
		 ft_strjoin.c \
		 ft_strlcat.c \
		 ft_strlcpy.c \
		 ft_strlen.c \
		 ft_strmapi.c \
		 ft_strncmp.c \
		 ft_strnstr.c \
		 ft_strrchr.c \
		 ft_striteri.c \
		 ft_substr.c \
		 ft_tolower.c \
		 ft_toupper.c \
		 ft_split.c \
		 ft_strtrim.c \
		 ft_strcmp.c \

SOURCE_BONUS = ft_lstadd_front.c \
			   ft_lstclear.c \
			   ft_lstdelone.c \
			   ft_lstiter.c \
			   ft_lstlast.c \
			   ft_lstmap.c \
			   ft_lstsize.c \

OBJECTS = ${SOURCE:.c=.o}

OBJECTS_BONUS = ${SOURCE_BONUS:.c=.o}

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c libft.h Makefile
	gcc $(FLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

bonus: $(OBJECTS) $(OBJECTS_BONUS)
	ar rc $(NAME) $(OBJECTS) $(OBJECTS_BONUS)
	ranlib $(NAME)

clean:
	rm -f $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
