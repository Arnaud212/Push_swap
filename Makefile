# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 02:03:39 by agiraud           #+#    #+#              #
#    Updated: 2021/10/22 10:10:36 by agiraud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

SRCS =	main.c \
		libft_functions/ft_atoi.c \
		libft_functions/ft_isdigit.c \
		libft_functions/ft_putstr_fd.c \
		libft_functions/ft_split.c \
		libft_functions/ft_strchr.c \
		libft_functions/ft_strdup.c \
		libft_functions/ft_strlen.c \
		free.c \
		ft_error.c \
		get_stack.c \
		initialise.c \
		operations.c \
		operations2.c \
		push_swap_functions.c \
		sort_3_params.c \
		sort_5_params.c \
		sort_100_params.c

NAME = push_swap

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

%.o:%.c *.h
	$(CC) $(CFLAGS) -c $< -o $@

all: *.h
	@$(MAKE) $(NAME)

$(NAME): $(OBJS)
		@$(CC) $(CFLAGS) $(OBJS) $(INC) -o $(NAME)
		@echo "\033[032mpush_swap Created\033[0m"

clean:
		@rm -rf *.o
		@rm -rf libft_functions/*.o
		@echo "\033[32mAll Object files Removed\033[0m"

fclean: clean 
		@rm -rf $(NAME)
		@echo "\033[32mpush_swap Removed\033[0m"

re: fclean all
