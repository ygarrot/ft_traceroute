# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/11 13:13:35 by ygarrot           #+#    #+#              #
#    Updated: 2019/07/06 13:37:40 by ygarrot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: $(NAME) all clean fclean re

NAME = ft_traceroute

FLAGS = -Wall -Werror -Wextra -MMD
FLAGS += -g3
FLAGS += -Wunused
# FLAGS += -fsanitize=address,undefined
SRC_DIR = src

INCLUDE =  includes/

OBJ_DIR = obj

CC = gcc
SRC =\
	 ping_struct.c\
	 setopt.c\
	 setopt2.c\
	 print.c\
	 packet.c\
	 checksum.c\
	 ip_version.c\
	 main.c\
	 ping.c\
	 set_socket.c\
	 time.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRC))

OBJS = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(basename $(SRC))))

OBJ_FILES = $(sort $(dir $(OBJS) $(dir $SHARED_OBJS)))

LIBFT = libft/libft.a

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c includes/$(NAME).h
	@$(CC) $(FLAGS) -o $@ -c $<  -I $(INCLUDE)


$(NAME): obj_dir $(OBJS)
	@make -C libft
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS)  -I $(INCLUDE) -L libft -l ft
	@echo $(NAME) is compiled

obj_dir:
	@mkdir -p $(OBJ_DIR) || true

clean:
	@rm -rf $(OBJ_DIR)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

exec: $(NAME)
	./$(NAME) www.google.com

re: fclean all
PHONY: $(NAME) all clean fclean re
