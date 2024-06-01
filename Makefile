# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/26 11:59:45 by lgandari          #+#    #+#              #
#    Updated: 2024/06/01 12:28:48 by lgandari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = push_swap

RED		=	\033[0;31m
GREEN	=	\033[0;32m
NC		=	\033[0m 

CFLAGS  = -Wall -Wextra -Werror -g3 -fsanitize=address
CC      = gcc
RM      = rm -f

LIBFT	= libft_v2//libft_v2.a
LIBFT_PATH	= libft_v2/

SRC_DIR = src/
SRCS	= $(addprefix $(SRC_DIR), main.c parser.c error.c init_stack.c)

OBJS	= $(SRCS:.c=.o)

all : $(NAME)

$(NAME)	: $(OBJS)
	@make all -sC $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJS) -I ../../inc/push_swap.h $(LIBFT) -o $(NAME)
	@echo "$(GREEN)Compiling push_swap...$(NC)"

clean:
	@$(RM) $(OBJS)
	@$(RM) $(OBJS_BONUS)
	@make clean -sC $(LIBFT_PATH)
	@echo "$(RED)All Objs Deleted.$(NC)"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
	@$(RM) $(LIBFT)
	@echo "$(RED)Everything Deleted.$(NC)"

re: fclean all

.PHONY: all clean fclean re
.SILENT:
