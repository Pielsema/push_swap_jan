# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsobotka <jsobotka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/15 14:00:00 by jsobotka         #+#    #+#              #
#    Updated: 2026/06/15 14:00:00 by jsobotka        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# Directories
LIBFT_DIR = libft

# Source files - push_swap
SRC = main.c \
      check_args.c \
      instr_push.c \
	  instr_rotate.c \
	  instr_swap.c \
	  instr_rotate_reverse.c \
      simple_sort.c \
      radix.c \
      index.c \
      t_stack.c \
      utils.c \
	  chunk_sort.c \
	  almost_sorted.c \
	  simple_utils.c \
	  adaptive_sort.c \
	  parse_mode.c \
	  parse_debug.c \
	  stack_lifecycle.c \
	  benchmark.c \
	  benchmark_print.c \
	  sort_four_special.c \
	  parse_options.c

# Source files - libft
LIBFT_SRC = libft/ft_isalpha.c \
			libft/ft_isdigit.c \
			libft/ft_isalnum.c \
			libft/ft_isascii.c \
			libft/ft_isprint.c \
			libft/ft_strlen.c \
			libft/ft_memset.c \
			libft/ft_bzero.c \
			libft/ft_memcpy.c \
			libft/ft_memmove.c \
			libft/ft_strlcpy.c \
			libft/ft_strlcat.c \
			libft/ft_toupper.c \
			libft/ft_tolower.c \
			libft/ft_strchr.c \
			libft/ft_strrchr.c \
			libft/ft_strncmp.c \
			libft/ft_memchr.c \
			libft/ft_memcmp.c \
			libft/ft_strnstr.c \
			libft/ft_atoi.c \
			libft/ft_calloc.c \
			libft/ft_strdup.c \
			libft/ft_substr.c \
			libft/ft_strtrim.c \
			libft/ft_split.c \
			libft/ft_strjoin.c \
			libft/ft_itoa.c \
			libft/ft_strmapi.c \
			libft/ft_striteri.c \
			libft/ft_putchar_fd.c \
			libft/ft_putstr_fd.c \
			libft/ft_putendl_fd.c \
			libft/ft_putnbr_fd.c \
			libft/ft_strcmp.c \
			libft/ft_printf.c \
	  		libft/ft_putchar.c \
			libft/ft_putnbr.c \
			libft/ft_putunbr.c \
			libft/ft_putstr.c \
			libft/ft_puthex.c \
			libft/ft_puthexup.c \
			libft/ft_putptr.c \

# Object files
OBJ = $(SRC:.c=.o)
LIBFT_OBJ = $(LIBFT_SRC:.c=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_OBJ) -lm -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

libft/%.o: libft/%.c libft/libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(LIBFT_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
