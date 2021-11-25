# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/07 22:58:48 by mahautlat         #+#    #+#              #
#    Updated: 2021/11/25 16:02:14 by esafar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c \
		./libft/ft_strdup.c \
		./libft/ft_putstr_fd.c \
		./libft/ft_strlen.c \
		./libft/ft_strjoin.c \
		./srcs/exit.c \
		./srcs/ft_putpixel.c \
		./srcs/get_map.c \
		./srcs/move.c \
		./srcs/initialize.c


OBJS 		= ${SRCS:.c=.o}

UNAME		:= $(shell uname)

PATH_MLX	= mlx
CC 			= gcc
CFLAGS		= -g3 -Wall -Wextra -Werror -D BUFFER_SIZE=1
RM			= rm -f
NAME		= so_long
#FLAGS		= -ldl -Imlx -Lmlx -lmlx -lm /*-lbsd*/-lz -lXext -lX11 -Wl,-rpath=./bass/,-rpath=./mlx/,-rpath=./delay/
FLAGS		= -ldl -Imlx -Lmlx -lmlx -lm -lz -lXext -lX11 -Wl,-rpath=./bass/,-rpath=./mlx/,-rpath=./delay/

all: 		${NAME}

.c.o:
			${CC} ${CFLAGS} -Imlx -Ibass -c $< -o ${<:.c=.o}

$(NAME): 	$(OBJS)
			make -C $(PATH_MLX)
			${CC} $(CFLAGS) -o $(NAME) $(OBJS) $(FLAGS)

bonus:		${OBJS} ${OBJS_B}
			make -C $(PATH_MLX)
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} $(FLAGS)

clean:
			make -C $(PATH_MLX) clean
			${RM} ${OBJS}
fclean: 	clean
			make -C $(PATH_MLX) clean
			${RM} ${NAME}

re: 		fclean all

.PHONY:		bonus all clean fclean re
