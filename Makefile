# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svikornv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 13:53:39 by svikornv          #+#    #+#              #
#    Updated: 2023/06/05 14:15:15 by svikornv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L$(MLX_DIR) -lmlx \
		-framework OpenGL \
		-framework Appkit
#Commands
RM = rm -rf
AR = ar rc

#Directories
MLX_DIR = mlx
SRC_DIR = srcs
OBJ_DIR = objs
LIBFT_DIR = libft
INCLUDE_DIR = includes

#Sources and objects
SRCS =	main.c \
		#init.c \
		#image.c \
		#hook.c \
		#window.c \
		#test.c
#OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
#Library names
NAME = so_long
LIBFT = libft/libft.a
MLX = mlx/libmlx.a
INCLUDES = -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

#Build
all: $(LIBFT_DIR) $(MLX_DIR) $(NAME)

#Rule to build each libraries
$(LIBFT):
	make -C $(LIBFT_DIR)
$(MLX):
	make -C $(MLX_DIR)

#Compile obj
#$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
#	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) -g $(CFLAGS) $(INCLUDES) -c $< -o $@
# Target library build rule
$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $^ $(MLX_FLAGS) $(INCLUDES) -o $(NAME)

#clean
clean:
	$(RM) $(OBJ_DIR)
	mkdir $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

#fclean
fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_DIR)/libft.a
	$(RM) $(MLX_DIR)/libmlx.a
	make fclean -C $(LIBFT_DIR)

# Clean and rebuild the target library
re: fclean all

# Phony targets
.PHONY: all clean fclean
