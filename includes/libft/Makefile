# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bglinda <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/05 16:18:11 by bglinda           #+#    #+#              #
#    Updated: 2020/03/05 16:18:13 by bglinda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

FLAGS = -Wall -Werror -Wextra

NAME = libft.a

PRINTF_C = float.c number.c parser.c display.c string.c  base_numbers.c define.c ft_printf.c define_nb.c display_nb.c

GNL_C = get_next_line.c

LIBFT_C = ft_itoa.c ft_memccpy.c ft_putchar_fd.c ft_strchr.c ft_striteri.c ft_strncmp.c ft_strsub.c \
ft_atoi.c ft_lstadd.c ft_memchr.c ft_putendl.c ft_strclr.c ft_strjoin.c ft_strncpy.c ft_strtrim.c \
ft_bzero.c ft_lstdel.c ft_memcmp.c ft_putendl_fd.c ft_strcmp.c ft_strjoinf.c ft_strnequ.c ft_swap.c \
ft_isalnum.c ft_lstdelone.c ft_memcpy.c ft_putnbr.c ft_strcpy.c ft_strlcat.c ft_strnew.c ft_tolower.c \
ft_isalpha.c ft_lstiter.c ft_memdel.c ft_putnbr_fd.c ft_strdel.c ft_strlen.c ft_strnstr.c ft_toupper.c \
ft_isascii.c ft_digitmass_cpy.c ft_lstmap.c ft_memmove.c ft_putstr.c ft_strdup.c ft_strmap.c ft_strrchr.c \
ft_isdigit.c ft_lstnew.c ft_memset.c ft_putstr_fd.c ft_strequ.c ft_strmapi.c ft_strsplit.c \
ft_isprint.c ft_memalloc.c ft_putchar.c ft_strcat.c ft_striter.c ft_strncat.c ft_strstr.c ft_to_power.c\


DIR_C_PRF = ./src/ft_printf/
DIR_C_GNL = ./src/get_next_line/
DIR_C_LIB = ./src/libft/

DIR_O = obj


BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"

CFILES = $(LIBFT_C) $(PRINTF_C) $(GNL_C)

PATH_C = $(addprefix $(DIR_C_LIB),$(LIBFT_C)) $(addprefix $(DIR_C_PRF),$(PRINTF_C)) $(addprefix $(DIR_C_GNL),$(GNL_C))

OFILES = $(CFILES:.c=.o)

PATH_O = $(addprefix $(DIR_O)/,$(OFILES))

all: $(NAME)

$(NAME): $(PATH_O)
	@ar rc $(NAME) $(PATH_O)
	@ranlib $(NAME)
	@echo $(GREEN)"     $(NAME) is ready"

$(DIR_O)/%.o: $(DIR_C_LIB)%.c
	@mkdir -p $(DIR_O)
	@$(CC) $(FLAGS) -c $< -o $@;

$(DIR_O)/%.o: $(DIR_C_PRF)%.c
	@mkdir -p $(DIR_O)
	@$(CC) $(FLAGS) -c $< -o $@;

$(DIR_O)/%.o: $(DIR_C_GNL)%.c
	@mkdir -p $(DIR_O)
	@$(CC) $(FLAGS) -c $< -o $@;

clean:
	@rm -f $(DIR_O)/*.o
	@rm -rf $(DIR_O)

fclean: clean
	@rm -f $(NAME)

re: fclean all
