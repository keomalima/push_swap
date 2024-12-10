# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kricci-d <kricci-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/29 14:02:27 by keomalima         #+#    #+#              #
#    Updated: 2024/12/10 08:50:24 by kricci-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
RM = rm -f
CC = cc
FLAGS = -Wall -Werror -Wextra
SRCS = push_swap.c stack_parse_utils.c swap_algo.c push_swap.c \
	rotate_algo.c rev_rot_algo.c small_sort_algo.c \
	push_algo.c turkish_sort.c sort_cost.c action_sort.c \
	turkish_sort_utils.c
OBJS = $(SRCS:.c=.o)

LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	ar rcs $(NAME) $(OBJS) $(LIBFT)

$(LIBFT) :
	$(MAKE) -C $(LIBFTDIR)

$(PRINTF) :
	$(MAKE) -C $(PRINTFDIR)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFTDIR) clean

fclean : clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re : fclean all

.PHONY : all clean fclean re
