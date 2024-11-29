# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keomalima <keomalima@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/29 14:02:27 by keomalima         #+#    #+#              #
#    Updated: 2024/11/29 14:58:20 by keomalima        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
RM = rm -f
CC = cc
FLAGS = -Wall -Werror -Wextra
SRCS = push_swap.c
OBJS = $(SRCS:.c=.o)

LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a

PRINTFDIR = ./printf
PRINTF = $(PRINTFDIR)/libftprintf.a

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT) $(PRINTF)
	ar rcs $(NAME) $(OBJS) $(LIBFT) $(PRINTF)

$(LIBFT) :
	$(MAKE) -C $(LIBFTDIR)

$(PRINTF) :
	$(MAKE) -C $(PRINTFDIR)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(PRINTFDIR) clean

fclean : clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(PRINTFDIR) fclean

re : fclean all

.PHONY : all clean fclean re