/*
** env.c for 42sh in /home/brendan/rendu/42sh/src/interpreter/builtins
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Sun May 24 12:54:54 2015 Brendan Rius
** Last update Sun May 24 13:15:47 2015 Brendan Rius
*/

#include <stdio.h>
#include <stdlib.h>
#include "env/env.h"

static void	setenv_usage()
{
  printf("Usage: setenv VAR [VALUE]\n");
}

int	builtin_setenv(size_t argc, char **args)
{
  if (argc < 2)
    {
      setenv_usage();
      return (-1);
    }
  if (my_setenv(args[0], args[1]) == NULL)
    return (fprintf(stderr, "cannot set environment variable\n"), -1);
  else
    return (0);
}
