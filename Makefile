# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oadhesiv <secondfry+school21@gmail.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/29 13:58:56 by oadhesiv          #+#    #+#              #
#    Updated: 2020/03/07 00:55:17 by oadhesiv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/zsh

NAME = fdf
SRCS_DIR = ./srcs
INCLUDES_DIR = ./includes
OBJS_DIR = ./objs

LIB = libft.a
LIB_DIR = ./libft

MLX = libmlx.dylib
MLX_DIR = ./minilibx_mms_20191025_beta

SRC_FILES =	main.c \
			color.c

SRCS = $(addprefix $(SRCS_DIR)/, $(SRC_FILES))
OBJS = $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o, $(SRCS))
DEPS = $(OBJS:.o=.d)

ifeq ($(origin CC), default)
CC = clang
endif

CFLAGS_ERRORS = -Wall -Wextra -Werror
CFLAGS_OPTIMIZATIONS = -O1 -funroll-loops
CFLAGS_DEPENDENCIES = -MMD -MP
CFLAGS_INCLUDES = -I$(INCLUDES_DIR) -I$(LIB_DIR) -I$(MLX_DIR)
CFLAGS_DEBUG = -g -fno-omit-frame-pointer -fsanitize=address
CFLAGS +=	$(CFLAGS_INTERNAL) \
			$(CFLAGS_ERRORS) $(CFLAGS_OPTIMIZATIONS) \
			$(CFLAGS_DEPENDENCIES) $(CFLAGS_INCLUDES)

LDFLAGS_DEBUG = -fsanitize=address
LDFLAGS +=	$(LDFLAGS_INTERNAL) \
			-L$(LIB_DIR) -lft -L$(MLX_DIR) -lmlx

DEFAULT = "\033[0;0m"
RED = "\033[0;31m"
GREEN = "\033[0;32m"
BLUE = "\033[0;34m"
CYAN = "\033[0;36m"

.PHONY: all libs dbin clean fclean re

all: libs
	@echo $(CYAN) "Making fdf" $(DEFAULT)
	@echo -n $(GREEN)
	$(MAKE) $(NAME)
	@echo -n $(DEFAULT)

libs:
	@echo $(CYAN) "Making libft" $(DEFAULT)
	@echo -n $(BLUE)
	$(MAKE) $(LIB_DIR)/$(LIB)
	@echo -n $(DEFAULT)

	@echo $(CYAN) "Making minilibx" $(DEFAULT)
	@echo -n $(BLUE)
	$(MAKE) $(MLX_DIR)/$(MLX)
	@echo -n $(DEFAULT)

dbin: clean libs
	@echo $(CYAN) "Making" $(RED) "debug" $(CYAN) "fdf" $(DEFAULT)
	@echo -n $(GREEN)
	CFLAGS_INTERNAL="$(CFLAGS_DEBUG)" LDFLAGS_INTERNAL="$(LDFLAGS_DEBUG)" \
	$(MAKE) $(NAME)
	@echo -n $(DEFAULT)

-include $(DEPS)
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJS)

$(LIB_DIR)/$(LIB):
	$(MAKE) -C $(LIB_DIR)

$(MLX_DIR)/$(MLX):
	$(MAKE) -C $(MLX_DIR)

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

	@echo $(CYAN) "Purging fdf" $(DEFAULT)
	@echo -n $(GREEN)
	if [ -f "$(NAME)" ]; then rm -rf $(NAME); fi
	@echo -n $(DEFAULT)

re: fclean all
