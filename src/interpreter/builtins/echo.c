/*
** echo.c for 42sh in /home/brendan/rendu/42sh
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Sun May 24 06:43:35 2015 Brendan Rius
** Last update Fri May 29 22:14:54 2015 Louis Person
*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include "shell.h"

static bool	g_nonewline = false;

static void	parse_params(size_t argc, char **argv)
{
  size_t	i;

  i = 0;
  while (i < argc)
    {
      if (strcmp(argv[i], "-n") == 0)
	g_nonewline = true;
      ++i;
    }
}

int		builtin_echo(size_t argc, char **argv)
{
  size_t	i;

  parse_params(argc, argv);
  i = 0;
  while (i < argc)
    {
      if (strcmp(argv[i], "-n") == 0)
	{
	  ++i;
	  continue;
	}
      if (i == argc - 1)
	write(sh_get()->fd[1][1], argv[i], strlen(argv[i]));
      else
	{
	  write(sh_get()->fd[1][1], argv[i], strlen(argv[i]));
	  write(sh_get()->fd[1][1], " ", 1);
	}
      ++i;
    }
  if (!g_nonewline)
    write(sh_get()->fd[1][1], "\n", 1);
  return (0);
}
