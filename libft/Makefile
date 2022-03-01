# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: barcher <barcher@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/17 12:10:23 by barcher           #+#    #+#              #
#    Updated: 2020/10/17 12:10:23 by barcher          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRC		=	ft_atoi.c			\
			ft_bzero.c			\
			ft_calloc.c			\
			ft_isalnum.c		\
			ft_isalpha.c		\
			ft_isascii.c		\
			ft_isdigit.c		\
			ft_isprint.c		\
			ft_memccpy.c		\
			ft_memchr.c			\
			ft_memcmp.c			\
			ft_memcpy.c			\
			ft_memmove.c		\
			ft_memset.c			\
			ft_strchr.c			\
			ft_strdup.c			\
			ft_strlcat.c		\
			ft_strlcpy.c		\
			ft_strlen.c			\
			ft_strncmp.c		\
			ft_strnstr.c		\
			ft_strrchr.c		\
			ft_tolower.c		\
			ft_toupper.c		\
			ft_substr.c			\
			ft_strjoin.c		\
			ft_split.c 			\
			ft_strmapi.c 		\
			ft_putchar_fd.c 	\
			ft_putstr_fd.c 		\
			ft_putendl_fd.c 	\
			ft_putnbr_fd.c 		\
			ft_itoa.c 			\
			ft_strtrim.c

SRC_B	=	ft_lstnew.c 		\
			ft_lstadd_front.c 	\
			ft_lstsize.c 		\
			ft_lstlast.c 		\
			ft_lstadd_back.c 	\
			ft_lstdelone.c 		\
			ft_lstclear.c 		\
			ft_lstiter.c 		\
			ft_lstmap.c

OBJ     = $(SRC:.c=.o)

OBJ_B   = $(SRC_B:.c=.o)

HEADER		= -I libft.h

CFLAGS		= -Wall -Wextra -Werror

CC			= gcc

.c.o:		$(HEADER)
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

RM			= rm -rf

NAME		= libft.a

$(NAME):	$(OBJ) $(OBJ_B)
			ar rc $(NAME) $(OBJ) $(OBJ_B)
			ranlib $(NAME)	

all:		$(NAME)

clean:
			$(RM) $(OBJ) $(OBJ_B) *.gch

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

so:			$(OBJ) $(OBJ_B)
			gcc -shared -o $(NAME:.a=.so) $(OBJ) $(OBJ_B)

.PHONY: 	all clean fclean re bonus
