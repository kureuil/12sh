/*
** getenv.c for 42sh in /home/brendan/rendu/42sh/src/interpreter/builtins
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Sun May 24 13:04:16 2015 Brendan Rius
** Last update Sun May 24 15:47:34 2015 Brendan Rius
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include "env/env.h"

int	builtin_getenv(size_t argc, char **args)
{
  char	*value;

  if (argc == 0)
    {
      char	**env;

      if ((env = get_all_env()) == NULL)
	return (fprintf(stderr, "cannot get env\n"), -1);
      while (*env)
	{
	  printf("%s\n", *env);
	  ++env;
	}
      return (0);
    }
  if ((value = my_getenv(args[0])) == NULL)
    return (fprintf(stderr, "cannot get environment variable\n"), -1);
  else
    {
      printf("%s=%s\n", args[0], value);
      return (0);
    }
}
