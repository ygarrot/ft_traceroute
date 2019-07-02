# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/11 12:06:15 by ygarrot           #+#    #+#              #
#    Updated: 2019/03/15 18:09:17 by ygarrot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all $(NAME) clean fclean re
.SUFFIXES:

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -g3
# CFLAGS += -fsanitize=address,undefined

SRCDIR = src
OBJDIR = obj
INCDIR = includes

SRC = \
	  misc/ft_exit.c\
	  misc/ft_occiter.c \
	  misc/ft_occur_in.c \
	  misc/ft_row_div.c \
	  misc/ft_intswap.c \
	  misc/ft_cpy.c

SRC += \
	   to/ft_atoi.c \
	   to/ft_atoi_base.c \
	   to/ft_imaxtoa_base.c \
	   to/ft_itoa.c \
	   to/ft_itoa_base.c \
	   to/ft_uimaxtoa_base.c

SRC += \
	   tern/ft_uint_isin.c \
	   tern/ft_abs.c \
	   tern/ft_int_isin.c \
	   tern/ft_isalnum.c \
	   tern/ft_isalpha.c \
	   tern/ft_isascii.c \
	   tern/ft_isbase.c \
	   tern/ft_isdigit.c \
	   tern/ft_isin.c \
	   tern/ft_isupper.c \
	   tern/ft_islower.c \
	   tern/ft_isprint.c \
	   tern/ft_strisin.c \
	   tern/ft_strisin_tab.c \
	   tern/ft_lenchar_r.c \
	   tern/ft_lenchar_l.c \
	   tern/ft_isin_unicode.c

SRC += \
	   print/ft_putchar.c \
	   print/ft_putchar_fd.c \
	   print/ft_putendl.c \
	   print/ft_putendl_fd.c \
	   print/ft_putnbr.c \
	   print/ft_putnbr_fd.c \
	   print/ft_putnbr_recc.c

SRC += \
	   mem/ft_swap_int.c \
	   mem/ft_memalloc.c \
	   mem/ft_memccpy.c \
	   mem/ft_memchr.c \
	   mem/ft_memcmp.c \
	   mem/ft_memcpy.c \
	   mem/ft_memdel.c \
	   mem/ft_memmove.c \
	   mem/ft_bzero.c \
	   mem/ft_memset.c \
	   mem/ft_realloc.c

SRC += \
	   str/ft_tolower.c \
	   str/ft_toupper.c \
	   str/ft_strcat.c \
	   str/ft_strchr.c \
	   str/ft_strclr.c \
	   str/ft_strcmp.c \
	   str/ft_strcpy.c \
	   str/ft_strdel.c \
	   str/ft_strdup.c \
	   str/ft_strequ.c \
	   str/ft_striter.c \
	   str/ft_striteri.c \
	   str/ft_strjoin.c \
	   str/ft_strlcat.c \
	   str/ft_strlen.c \
	   str/ft_strnlen.c \
	   str/ft_strmap.c \
	   str/ft_strmap2.c \
	   str/ft_strmapi.c \
	   str/ft_strncat.c \
	   str/ft_strncmp.c \
	   str/ft_strncpy.c \
	   str/ft_strnequ.c \
	   str/ft_strnew.c \
	   str/ft_strnstr.c \
	   str/ft_strrchr.c \
	   str/ft_strsplit.c \
	   str/ft_strmsplit.c \
	   str/ft_strstr.c \
	   str/ft_strsub.c \
	   str/ft_strtrim.c \
	   str/ft_implode.c \
	   str/ft_strrlento.c \
	   str/ft_charchr.c \
	   str/ft_mcharchr.c \
	   str/ft_capitalize.c \
	   str/ft_putstr.c \
	   str/ft_putstr_fd.c \
	   str/ft_strndup.c \
	   str/ft_addtofd.c \
	   str/ft_strlento.c \
	   str/ft_strinstr.c \
	   str/ft_strprefix.c \
	   str/ft_str_isdigit.c \
	   str/ft_strdupto.c \
	   str/ft_str_tabjoin.c \
	   str/ft_replace.c \
	   str/ft_strlento_rev.c
SRC += \
	   get_next_line/get_next_line.c \
	   get_next_line/get_next_line_b.c \
	   get_next_line/get_filetochar.c

SRC += \
	   list/ft_lstadd.c \
	   list/ft_lstat.c \
	   list/ft_lstdel.c \
	   list/ft_lstdelone.c \
	   list/ft_lstfree.c \
	   list/ft_lstfusion.c \
	   list/ft_lstiter.c \
	   list/ft_lstmap.c \
	   list/ft_lstnew.c \
	   list/ft_lstnewc.c \
	   list/ft_lstpushback.c \
	   list/ft_lstpushfront.c \
	   list/ft_lstpushsort.c \
	   list/ft_lstremoveif.c \
	   list/ft_lstreverse.c \
	   list/ft_lstsize.c \
	   list/ft_lstsort.c \
	   list/ft_lstvoid.c

SRC += \
	   tab/ft_free_dblechar_tab.c \
	   tab/ft_free_dblint_tab.c \
	   tab/ft_init_char_tab.c \
	   tab/ft_init_int_tab.c \
	   tab/ft_print_chartab.c \
	   tab/ft_print_dbl_inttab.c \
	   tab/ft_print_inttab.c \
	   tab/ft_sizeof_tab.c \
	   tab/ft_tablen.c \
	   tab/ft_dblstr_add.c

SRC += \
	   printf/chooseconv.c \
	   printf/convs.c \
	   printf/convuimax.c \
	   printf/ft_printf.c \
	   printf/parsecolor.c \
	   printf/parser_printf.c \
	   printf/print_nchar.c \
	   printf/printp.c

SRC += \
	   tree/btree_create_node.c \
	   tree/btree_apply_infix.c \
	   tree/btree_apply_prefix.c \
	   tree/btree_apply_suffix.c \
	   tree/btree_search_item.c \
	   tree/btree_level_count.c \
	   tree/btree_insert_data.c \
	   tree/btree_remove_data.c

SRC +=\
			 unix/stat/is_directory.c\
			 unix/stat/is_regular_file.c

SRC +=\
			parsing/ft_getopt.c\
			parsing/ft_getoptvalue.c

SRC +=\
	  math/ft_mean.c\
	  math/ft_std.c\
	  math/ft_sqrt.c\
	  math/ft_ismax.c \
	  math/ft_ismin.c \
	  math/ft_max.c\
	  math/ft_power.c\
	  math/ft_min.c
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

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(_CYAN)\nCompiling library $(NAME)... $(_GREEN)DONE$(_END)"
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(ALL_OBJ_DIR) || true
	@printf "                                                          \r"
	@printf "$(_CYAN)Compiling $@$(_END)\r"
	@$(CC) -o $@ -c $(CFLAGS) $< $(INCS)

clean:
	@echo "$(_RED)Removed objects (.o) files.$(_END)"
	@/bin/rm -f $(OBJS)

fclean: clean
	@echo "$(_RED)Removed library ($(NAME)).$(_END)"
	@/bin/rm -f $(NAME)

re:
	make fclean
	make all


