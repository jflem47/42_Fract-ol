# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 16:48:41 by jlemieux          #+#    #+#              #
#    Updated: 2023/03/16 20:10:42 by jlemieux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol
BONUS_NAME = fractol_bonus 
CFLAGS	= -Wextra -Wall -Werror
LIBMLX	= ./lib/MLX42
HEADERS = ./include/fractol.h ./include/fractol_bonus.h 
INCLUDES	= -I ./include -I $(LIBMLX)/include -I lib/libft -I/Users/jlemieux/.brew/opt/libomp/include
LIBS	= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -L "/Users/$(USER)/homebrew/opt/glfw/lib/" -pthread -lm ./lib/libft/libft.a

SRCS	= 	src/main.c \
			src/utils/input_utils.c \
			src/utils/init.c \
			src/mandelbrot.c \
			src/utils/hooks.c \
			src/utils/hooks_utils.c \
			src/julia.c \
			

BONUS_SRCS = src/burningship_bonus.c \
			 src/main.c \
			 src/utils/input_utils_bonus.c \
			 src/utils/init_bonus.c \
			 src/mandelbrot_bonus.c \
			 src/utils/hooks.c \
			 src/utils/hooks_utils.c \
			 src/julia_bonus.c \
			 src/utils/threads_bonus.c \
			
OBJS	= ${SRCS:.c=.o}

BONUS_OBJS = ${BONUS_SRCS:.c=.o}

$(NAME): $(OBJS) $(HEADERS)
	@$(CC) $(OBJS) $(LIBS) -o $(NAME) $(INCLUDES)

bonus : libft libmlx $(BONUS_OBJS)
	@$(CC) $(BONUS_OBJS) $(LIBS) -o $(BONUS_NAME) $(INCLUDES)

all: libft libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	$(info Compiling libft...)
	@make -C lib/libft

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES) && printf "Compiling: $(notdir $<)\n"

clean:
	@rm -f $(OBJS)
	@rm -f $(BONUS_OBJS)
	$(info Cleaning MLX42...)
	@rm -rf $(LIBMLX)/build
	@make clean -C lib/libft
	$(info Done!)

fclean: clean
	$(info Cleaning fract'ol...)
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)
	@make fclean -C lib/libft
	$(info Done!)

re: fclean all

.PHONY: all, clean, fclean, re, libmlx