/*
** env.c for 42sh in /home/brendan/rendu/42sh/src/interpreter/builtins
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Sun May 24 12:54:54 2015 Brendan Rius
** Last update Sat May 30 13:45:58 2015 Louis Person
*/

#include <stdio.h>
#include <stdlib.h>
#include "env/env.h"
#include "shell.h"

static void	setenv_usage()
{
  printf("Usage: setenv VAR [VALUE]\n");
}

int	builtin_setenv(size_t argc, char **args)
{
  if (argc == 0 || argc > 2)
    {
      setenv_usage();
      return (sh_return(sh_get(), EXIT_FAILURE), -1);
    }
  else if (argc == 1)
    {
      if (my_setenv(args[0], "") == NULL)
	{
	  sh_return(sh_get(), EXIT_FAILURE);
	  return (fprintf(stderr, "cannot set environment variable\n"), -1);
	}
    }
  else if (my_setenv(args[0], args[1]) == NULL)
    {
      sh_return(sh_get(), EXIT_FAILURE);
      return (fprintf(stderr, "cannot set environment variable\n"), -1);
    }
  sh_return(sh_get(), EXIT_SUCCESS);
  return (0);
}
