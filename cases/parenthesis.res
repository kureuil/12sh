##
## Makefile for fabrish in /home/person_l
## 
## Made by Louis Person
## Login   <person_l@epitech.net>
## 
## Started on  Mon Jan 26 09:34:40 2015 Louis Person
## Last update Sun Feb  1 17:51:39 2015 Louis Person
##

NAME	= mysh

CC	= clang

RM	= rm -rf

CFLAGS	+= -g
CFLAGS	+= -Wall
CFLAGS	+= -Wextra
CFLAGS	+= -I ./inc/

LDFLAGS	= -L ./lib/
LDFLAGS	+= -l my

SRCS	= src/behaviors/and.c \
	src/behaviors/call.c \
	src/behaviors/or.c \
	src/behaviors/sleep.c \
	src/builtins/builtins.c \
	src/builtins/cd.c \
	src/builtins/env.c \
	src/builtins/exit.c \
	src/lexer/lexer.c \
	src/lexer/lexicon.c \
	src/lexer/token.c \
	src/lexicon/and.c \
	src/lexicon/call.c \
	src/lexicon/eoc.c \
	src/lexicon/eof.c \
	src/lexicon/lparenthesis.c \
	src/lexicon/or.c \
	src/lexicon/rparenthesis.c \
	src/interpreter/interpreter.c \
	src/parsers/and.c \
	src/parsers/call.c \
	src/parsers/eoc.c \
	src/parsers/eof.c \
	src/parsers/lparenthesis.c \
	src/parsers/or.c \
	src/parsers/rparenthesis.c \
	src/parsers/sof.c \
	src/parsers/string.c \
	src/parsers/undefined.c \
	src/prompt/backslash.c \
	src/prompt/return.c \
	src/prompt/user.c \
	src/alias.c \
	src/char.c \
	src/env.c \
	src/errors.c \
	src/eval.c \
	src/fabrish.c \
	src/parser.c \
	src/prompt.c \
	src/shell.c

OBJS	= $(SRCS:.c=.o)

all:
	$(MAKE) -j $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

test:
	valgrind ./$(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
Hello World
Hello AER
