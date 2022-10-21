# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfamilar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/01 11:28:51 by cfamilar          #+#    #+#              #
#    Updated: 2022/10/20 20:57:08 by cfamilar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex

LIBFT_PATH	=	./libraries/libft
LIBFT		=	$(LIBFT_PATH)/libft.a

SRCS_DIR	=	sources
INC_DIR		=	includes
OBJS_DIR	=	objects

HEADER		=	$(INC_DIR)/pipex.h
SRCS		=	$(SRCS_DIR)/error.c $(SRCS_DIR)/files.c $(SRCS_DIR)/parse.c $(SRCS_DIR)/pipex.c
OBJS		=	$(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

CC			=	gcc
RM			=	rm -rf
CFLAGS		=	-Wall -Wextra -Werror -std=c99

all:				$(NAME)

$(NAME):			$(LIBFT) $(OBJS_DIR) $(OBJS) $(HEADER)
					$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c $(HEADER)
					$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
					$(MAKE) -C $(LIBFT_PATH) bonus

$(OBJS_DIR):
					mkdir -p $(OBJS_DIR)

clean:
					$(MAKE) -C $(LIBFT_PATH) clean
					$(RM) $(OBJS_DIR) 

fclean:				clean
					$(MAKE) -C $(LIBFT_PATH) fclean
					$(RM) $(NAME) *.txt

re:					fclean all

.PHONY:				all clean fclean re libft 