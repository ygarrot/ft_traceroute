# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/11 12:06:15 by ygarrot           #+#    #+#              #
#    Updated: 2019/06/25 13:56:39 by ygarrot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all $(NAME) clean fclean re
.SUFFIXES:

NAME = scop

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -g3
CFLAGS += -fsanitize=address,undefined

FRAMEWORK += -framework OpenGL \
-framework CoreVideo \
-framework IOKit \
-framework Cocoa \
-framework Carbon


SRCDIR = src
OBJDIR = obj
INCDIR =  \
		  Users/ygarrot/.brew/Cellar/glew/2.1.0/include/GL \
		  Users/ygarrot/.brew/Cellar/glfw/3.3/include \
		  includes \
		  libft/includes

SRC = \
	  list/tlist_functions.c\
	  list/vertex_list.c\
	  main.c\
	  draw.c\
	  parser/mtl_parser.c\
	  parser/mtl_set_functions.c\
	  parser/mtl_set_functions_1.c\
	  parser/obj_parser.c\
	  parser/obj_set_functions.c\
	  parser/obj_set_functions_1.c\
	  print/mtl_print.c\
	  matrix/print.c\
	  matrix/basics.c\
	  matrix/transpose.c\
	  matrix/init.c\
	  print/obj_print.c

#Colors

_RED=$(shell tput setaf 1)
_GREEN=$(shell tput setaf 2)
_YELLOW=$(shell tput setaf 3)
_BLUE=$(shell tput setaf 4)
_PURPLE=$(shell tput setaf 5)
_CYAN=$(shell tput setaf 6)
_WHITE=$(shell tput setaf 7)
_END=$(shell tput sgr0)

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(basename $(SRC))))
ALL_OBJ_DIR = $(sort $(dir $(OBJS)))
INCS = $(addprefix -I, $(addsuffix /, $(INCDIR)))

LIBFT = libft/libft.a ~/.brew/lib/libglfw3.a ~/.brew/lib/libGLEW.a


all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(FRAMEWORK) -I $(INCS) $(LIBFT)
	@echo "$(_CYAN)\nCompiling library $(NAME)... $(_GREEN)DONE$(_END)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(ALL_OBJ_DIR) || true
	@printf "                                                          \r"
	@printf "$(_CYAN)Compiling $@$(_END)\r"
	@$(CC) -o $@ -c $(CFLAGS) $< $(INCS)

clean:
	@echo "$(_RED)Removed objects (.o) files.$(_END)"
	@/bin/rm -rf obj
	make clean -C libft

fclean: clean
	@echo "$(_RED)Removed ($(NAME)).$(_END)"
	@/bin/rm -f $(NAME)
	make fclean -C libft

re: fclean
	make all
