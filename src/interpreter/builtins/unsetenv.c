/*
** unsetenv.c for 42sh in /home/brendan/rendu/42sh
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Sun May 24 13:15:49 2015 Brendan Rius
** Last update Sun May 24 13:21:09 2015 Brendan Rius
*/

#include <stdio.h>
#include <stdlib.h>
#include "env/env.h"

static void	unsetenv_usage()
{
  printf("Usage: unsetenv VAR [VALUE]\n");
}

int	builtin_unsetenv(size_t argc, char **args)
{
  if (argc < 1)
    {
      unsetenv_usage();
      return (-1);
    }
  my_setenv(args[0], NULL);
  return (0);
}
