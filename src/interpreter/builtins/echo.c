/*
** echo.c for 42sh in /home/brendan/rendu/42sh
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Sun May 24 06:43:35 2015 Brendan Rius
** Last update Sun May 24 07:59:44 2015 Brendan Rius
*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

static bool	g_nonewline = false;
static bool	g_specialchars = false;

static void	parse_params(size_t argc, char **argv)
{
  size_t	i;

  i = 0;
  while (i < argc)
    {
      if (strcmp(argv[i], "-n") == 0)
	g_nonewline = true;
      else if (strcmp(argv[i], "-e") == 0)
	g_specialchars = true;
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
	continue;
      else if (strcmp(argv[i], "-e") == 0)
	continue;
      if (i == argc - 1)
	printf("%s", argv[i]);
      else
	printf("%s ", argv[i]);
      ++i;
    }
  if (!g_nonewline)
    printf("\n");
  return (0);
}
