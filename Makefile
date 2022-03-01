# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: barcher <barcher@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/17 18:00:33 by barcher           #+#    #+#              #
#    Updated: 2021/04/22 23:01:15 by barcher          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D

LIBFT_PATH	=	libft/

LIBA		=	libft.a

LIBMINILIB_PATH = minilibx-linux/

MINILIBA	=	libmlx_Linux.a

SRC_PATH	=	include/

SRC_FILES	=	bitmap.c \
				geom_utils.c \
				h_line.c \
				linef.c \
				listf.c \
				matf.c \
				moving.c \
				parser_utils.c \
				parser.c \
				plf.c \
				sprite.c \
				utils_color.c \
				utils.c \
				v_line.c \
				wallf.c

GNL_FILES	=	gnl/get_next_line.c \
				gnl/get_next_line_utils.c

CUB3D		=	main.c

CC			=	gcc

FLAGS		= -Wall -Werror -Wextra

%.o:		%.c
			$(CC) $(FLAGS) -c $< -o $(<:.c=.o) 

GNL_OBJ		=	$(GNL_FILES:.c=.o)

SRC_OBJ		=	$(addprefix $(SRC_PATH),$(SRC_FILES:.c=.o))

CUB3D_OBJ	=	$(CUB3D:.c=.o)

all:		libfta mllib $(NAME)

libfta:
			make -C $(LIBFT_PATH)

mllib:
			make -C $(LIBMINILIB_PATH)

$(NAME):	$(SRC_OBJ) $(CUB3D_OBJ) $(GNL_OBJ) libft/libft.a include/ft_cub3d.h \
			libft/libft.h gnl/get_next_line.h
			gcc $(SRC_OBJ) $(CUB3D_OBJ) $(GNL_OBJ) libft/libft.a minilibx-linux/libmlx_Linux.a -lXext -lX11 -lm -lz -o $(NAME)

clean:
			make -C $(LIBFT_PATH) clean
			make -C $(LIBMINILIB_PATH) clean
			rm -rf $(SRC_OBJ) $(CUB3D_OBJ) $(GNL_OBJ)

eval:		all clean
			norminette include/ gnl/ libft/ main.c

fclean:		clean
			rm -rf $(NAME)
			make -C $(LIBFT_PATH) fclean

re:			fclean all

main:
			make
			gcc main.c libftprintf.a

norm:
			norminette.exe $(addprefix $(SRC_PATH),$(SRC_FILES)) $(PRINTF) ft_printf.h libft/libft.h libft/*.c

test:		norm
			make -C ./pft/
			#make -C ./pft_2019/
			(cd pft && ./test) | grep "FAIL\|Tests completed"  
			#(cd pft_2019 && ./test) | grep "FAIL\|Tests completed"  
			#(cd 42TESTERS-PRINTF && ./runtest.sh)
			
.PHONY: 	all clean fclean re bonus
