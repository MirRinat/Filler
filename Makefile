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

SRC_FILLER = main.c algorithm.c create_map.c create_figure.c heatmap.c helper.c \

OBJSFD  = obj

SRCS    = src

OBJS1    = $(addprefix $(OBJSFD)/,$(SRC_FILLER:.c=.o))

DFS = ./includes/filler.h

LIBFT_HDR   = -I ./includes/libft/headers

LIB_BINARY  = -L ./includes/libft -lft

LIBFT       = ./includes/libft/libft.a

GREEN:="\033[1;32m"

ANSI_COLOR_RESET:="\x1b[0m"

all: $(LIBFT) $(NAME)

$(OBJSFD):
	@mkdir $@

$(OBJSFD)/%.o: $(SRCS)/%.c | $(OBJSFD)
	@gcc $(CFLAGS) $(LIBFT_HDR) -c $< -o $@

$(LIBFT):
	@make -C ./includes/libft

$(NAME): $(OBJS1) $(DFS)
	@gcc $(OBJS1) $(LIB_BINARY) -o $@
	@echo $(GREEN)"     $(NAME) is ready"$(ANSI_COLOR_RESET)


clean:
	@/bin/rm -f $(OBJS)
	@rm -rf $(OBJSFD)
	@make -C ./includes/libft clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C ./includes/libft fclean

re: fclean all
