/*
** find_executable.c for 42sh in /home/brendan/rendu/42sh/src
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Sat May 23 03:07:45 2015 Brendan Rius
** Last update Sun May 24 22:01:35 2015 Louis Person
*/

/*
** @TESTABLE
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "env/env.h"

static int	check_executable(const char *executable, char *dest, size_t n)
{
  if (access(executable, X_OK) != -1)
    {
      strncpy(dest, executable, n - 1);
      dest[strnlen(executable, n - 1)] = '\0';
      return (0);
    }
  else
    return (-1);
}

int	find_executable(const char *name, char *dest, size_t n)
{
  char	*path;
  char	*dir;
  char	executable[n];

  if (n == 0 || strlen(name) == 0)
    return (-1);
  if (check_executable(name, dest, n) == 0)
    return (0);
  path = my_getenv("PATH");
  if (path == NULL)
    return (-1);
  if ((path = strdup(path)) == NULL)
    return (-1);
  while ((dir = strtok(path, ":")) != NULL)
    {
      path = NULL;
      snprintf(executable, n, "%s/%s", dir, name);
      if (check_executable(executable, dest, n) == 0)
	return (0);
    }
  return (-1);
}
