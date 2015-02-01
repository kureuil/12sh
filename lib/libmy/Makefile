##
## Makefile for libmy in /home/person_l
##
## Made by Louis Person
## Login   <person_l@epitech.net>
##
## Started on  Fri Nov  14 14:59:03 2014 Louis Person
## Last update Sun Feb  1 13:16:42 2015 Louis Person
##

NAME	= libmy.a

CC	= clang

RM	= rm -f

INC_DIR	= ./include/

CFLAGS	+= -c
CFLAGS	+= -Wall
CFLAGS	+= -Wextra
CFLAGS	+= -pedantic
CFLAGS	+= -I $(INC_DIR)

LDFLAGS	= -L .
LDFLAGS += -l my

SRCS	= src/chalk/chalk.c \
	src/culotte/my_char_iswordsep.c \
	src/culotte/my_putstr.c \
	src/culotte/my_puterr.c \
	src/culotte/my_revstr.c \
	src/culotte/my_showstr.c \
	src/culotte/my_strcapitalize.c \
	src/culotte/my_strcat.c \
	src/culotte/my_strcmp.c \
	src/culotte/my_strcount.c \
	src/culotte/my_strcpy.c \
	src/culotte/my_strdup.c \
	src/culotte/my_str_isalpha.c \
	src/culotte/my_str_islower.c \
	src/culotte/my_str_isnum.c \
	src/culotte/my_str_isprintable.c \
	src/culotte/my_str_isupper.c \
	src/culotte/my_strlen.c \
	src/culotte/my_strlowcase.c \
	src/culotte/my_strncat.c \
	src/culotte/my_strncmp.c \
	src/culotte/my_strncpy.c \
	src/culotte/my_strndup.c \
	src/culotte/my_strsep.c \
	src/culotte/my_strsplit.c \
	src/culotte/my_strstr.c \
	src/culotte/my_str_trim.c \
	src/culotte/my_strupcase.c \
	src/larousse/buckets.c \
	src/larousse/dictionary.c \
	src/larousse/utils.c \
	src/tetris/deletion.c \
	src/tetris/free.c \
	src/tetris/trees.c \
	src/tetris/utils.c \
	src/queues/queues.c \
	src/copy.c \
	src/dynamo.c \
	src/env.c \
	src/file.c \
	src/get_nbr_len.c \
	src/get_next_line.c \
	src/my_dputchar.c \
	src/my_dputstr.c \
	src/my_dput_nbr.c \
	src/my_dputnbr_base.c \
	src/my_getnbr_base.c \
	src/my_getnbr.c \
	src/my_index_of.c \
	src/my_is_in.c \
	src/my_memcpy.c \
	src/my_pow.c \
	src/my_putchar.c \
	src/my_putnbr_base.c \
	src/my_put_nbr.c \
	src/my_read.c \
	src/my_show_wordtab.c \
	src/my_sort_int_tab.c \
	src/my_square_root.c \
	src/path.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

install:
	cp $(NAME) ../
	mkdir -p ../../inc/my
	cp $(INC_DIR)my.h ../../inc/
	cp $(INC_DIR)my/*.h ../../inc/my/
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(TMPS)

re:
	$(MAKE) fclean
	$(MAKE) -j all

.PHONY: re all install clean fclean
