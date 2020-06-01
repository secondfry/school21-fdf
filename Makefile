# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oadhesiv <secondfry+school21@gmail.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/29 13:58:56 by oadhesiv          #+#    #+#              #
#    Updated: 2020/03/15 21:31:00 by oadhesiv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/zsh

NAME = fdf
SRCS_DIR = ./srcs
INCLUDES_DIR = ./includes
OBJS_DIR = ./objs

LIB = libft.a
LIB_DIR = ./libft

SRC_FILES =	main.c \
			matrix_factory.c matrix_utils.c \
			quaterion.c vector.c \
			hooks_loop_1.c hooks_loop_2.c bresenham.c \
			teapot.c

SRCS = $(addprefix $(SRCS_DIR)/, $(SRC_FILES))
OBJS = $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o, $(SRCS))
DEPS = $(OBJS:.o=.d)

ifeq ($(origin CC), default)
CC = clang
endif

ifeq ($(OS),Windows_NT)
# huh lol
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		MLX = libmlx.dylib
		MLX_DIR = ./minilibx_mms_20191025_beta
	endif
	ifeq ($(UNAME_S),Darwin)
		UNAME_R := $(shell uname -r | cut -d. -f1)
		VER := $(shell test $(UNAME_R) -ge 17 && echo 'new' || echo 'old')
		ifeq ($(VER),new)
			MLX = libmlx.dylib
			MLX_DIR = ./minilibx_mms_20191025_beta
		endif
		ifeq ($(VER),old)
			MLX = libmlx.a
			MLX_DIR = ./minilibx_macos
			LDFLAGS += -framework OpenGL -framework AppKit
		endif
	endif
endif

CFLAGS_ERRORS = -Wall -Wextra
CFLAGS_OPTIMIZATIONS = -funroll-loops
CFLAGS_DEPENDENCIES = -MMD -MP
CFLAGS_INCLUDES = -I$(INCLUDES_DIR) -I$(LIB_DIR) -I$(MLX_DIR)
CFLAGS_DEBUG = -O0 -pg -g -fno-omit-frame-pointer -mno-omit-leaf-frame-pointer

ifeq ($(CC), clang)
CFLAGS_OPTIMIZATIONS += -O1
endif
ifeq ($(CC), gcc)
CFLAGS_OPTIMIZATIONS += -O3
endif
ifeq ($(CC), gcc-9)
CFLAGS_OPTIMIZATIONS += -O3
endif

CFLAGS_FINAL =	$(CFLAGS_INTERNAL) \
				$(CFLAGS_ERRORS) $(CFLAGS_OPTIMIZATIONS) \
				$(CFLAGS_DEPENDENCIES) $(CFLAGS_INCLUDES) \
				$(CFLAGS)

LDFLAGS +=	-L$(LIB_DIR) -lft -L$(MLX_DIR) -lmlx

DEFAULT = "\033[0;0m"
RED = "\033[0;31m"
GREEN = "\033[0;32m"
BLUE = "\033[0;34m"
CYAN = "\033[0;36m"

.PHONY: all clean fclean re

all:
	@echo $(CYAN) "Making libft" $(DEFAULT)
	@echo -n $(BLUE)
	CC="$(CC)" $(MAKE) -C $(LIB_DIR)
	@echo -n $(DEFAULT)

	@echo $(CYAN) "Making minilibx" $(DEFAULT)
	@echo -n $(BLUE)
	CC="$(CC)" $(MAKE) -C $(MLX_DIR)
	cp $(MLX_DIR)/$(MLX) $(MLX)
	@echo -n $(DEFAULT)

	@echo $(CYAN) "Making fdf" $(DEFAULT)
	@echo -n $(GREEN)
	$(MAKE) $(NAME)
	@echo -n $(DEFAULT)

-include $(DEPS)
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS_FINAL) -c -o $@ $<

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS) $(LIB_DIR)/$(LIB) $(MLX_DIR)/$(MLX)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJS)

clean:
	@echo $(CYAN) "Cleaning libft" $(DEFAULT)
	@echo -n $(BLUE)
	$(MAKE) -C $(LIB_DIR) clean
	@echo -n $(DEFAULT)

	@echo $(CYAN) "Cleaning minilibx" $(DEFAULT)
	@echo -n $(BLUE)
	$(MAKE) -C $(MLX_DIR) clean
	@echo -n $(DEFAULT)

	@echo $(CYAN) "Cleaning fdf" $(DEFAULT)
	@echo -n $(GREEN)
	if [ -d "$(OBJS_DIR)" ]; then rm -rf $(OBJS_DIR); fi
	@echo -n $(DEFAULT)

fclean: clean
	@echo $(CYAN) "Purging libft" $(DEFAULT)
	@echo -n $(BLUE)
	$(MAKE) -C $(LIB_DIR) fclean
	@echo -n $(DEFAULT)

	@echo $(CYAN) "Purging minilibx" $(DEFAULT)
	@echo -n $(BLUE)
	$(MAKE) -C $(MLX_DIR) fclean
	rm -rfv $(MLX)
	@echo -n $(DEFAULT)

	@echo $(CYAN) "Purging fdf" $(DEFAULT)
	@echo -n $(GREEN)
	if [ -f "$(NAME)" ]; then rm -rf $(NAME); fi
	@echo -n $(DEFAULT)

debug:
	CFLAGS="$(CFLAGS_DEBUG)" $(MAKE) all

re: fclean all
