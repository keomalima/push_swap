# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keomalima <keomalima@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/29 14:02:27 by keomalima         #+#    #+#              #
#    Updated: 2024/12/09 22:12:52 by keomalima        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
RM = rm -f
CC = cc
FLAGS = -Wall -Werror -Wextra
SRCS = push_swap.c stack_parse_utils.c swap_algo.c push_swap.c \
	rotate_algo.c rev_rot_algo.c sort_algo.c instru_sort.c \
	push_algo.c turkish_algo.c sort_cost.c action_sort.c
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
