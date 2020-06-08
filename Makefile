# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bglinda <bglinda@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/25 01:41:32 by bglinda           #+#    #+#              #
#    Updated: 2020/05/25 01:41:38 by bglinda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bglinda.filler

CFLAGS  = -Wall -Wextra -Werror -g

SRC = main.c algorithm.c create_map.c create_figure.c \
				heatmap.c helper.c validation.c

OBJS_D  = obj

SRCS    = src

HEAD = ./includes/filler.h

OBJS    = $(addprefix $(OBJS_D)/,$(SRC:.c=.o))

LIBFT_HDR   = -I ./includes/libft/headers

LIB_BINARY  = -L ./includes/libft -lft

LIBFT       = ./includes/libft/libft.a

GREEN:="\033[1;32m"
ANSI_COLOR_RESET:="\x1b[0m"

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C ./includes/libft

$(OBJS_D):
	@mkdir $@

$(OBJS_D)/%.o: $(SRCS)/%.c $(HEAD)
	@gcc $(CFLAGS) $(LIBFT_HDR) -c $< -o $@

$(NAME): $(OBJS_D) $(OBJS) $(HEAD)
	@gcc $(LIB_BINARY) $(LIBFT_HDR) $(OBJS) -o $@
	@echo $(GREEN)"     $(NAME) is ready"$(ANSI_COLOR_RESET)

clean:
	@/bin/rm -f $(OBJS)
	@rm -rf $(OBJS_D)
	@make -C ./includes/libft clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C ./includes/libft fclean

re: fclean all

.PHONY: all fclean clean re