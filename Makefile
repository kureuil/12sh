##
## Makefile for minishell1 in /home/person_l
## 
## Made by Louis Person
## Login   <person_l@epitech.net>
## 
## Started on  Tue Jan 20 14:03:29 2015 Louis Person
## Last update Sun Jan 25 23:39:48 2015 Louis Person
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

SRCS	= src/minishell.c \
	src/env.c \
	src/error.c \
	src/path.c \
	src/command.c \
	src/input.c \
	src/builtins.c \
	src/prompt.c \
	src/builtins/env.c \
	src/builtins/cd.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

test:
	./$(NAME)

tests:
	testrunner.py

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
