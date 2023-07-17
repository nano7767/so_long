# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svikornv <svikornv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 13:53:39 by svikornv          #+#    #+#              #
#    Updated: 2023/07/11 11:35:28 by svikornv         ###   ########.fr        #
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
		player.c \
		map.c \
		validity.c \
		exit.c \
		keyhook.c
BONUS_SRCS = map_bonus.c \
		validity_bonus.c \
		player_bonus.c \
		main.c \
		keyhook.c \
		exit.c
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
BONUS_OBJS = $(BONUS_SRCS:%.c=$(OBJ_DIR)/%.o) $(filter-out $(OBJ_DIR)/main.o $(OBJ_DIR)/player.o $(OBJ_DIR)/exit.o $(OBJ_DIR)/map.o $(OBJ_DIR)/validity.o $(OBJ_DIR)/keyhook.o, $(OBJS))

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
$(OBJS): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) -g $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BONUS_OBJS): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) -g $(CFLAGS) $(INCLUDES) -D BONUS=1 -c $< -o $@

# Target library build rule
$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $^ $(MLX_FLAGS) $(INCLUDES) -o $(NAME)

# Bonus rule to compile bonus sources
bonus: $(BONUS_OBJS) $(LIBFT) $(MLX)
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
.PHONY: all bonus clean fclean re