/*
** env.c for minishell1 in /home/brendan/rendu/PSU_2014_minishell1
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Sat Jan 31 16:55:35 2015 Brendan Rius
** Last update Sun May 24 13:07:02 2015 Brendan Rius
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "my/my.h"
#include "env/env.h"
#include "error.h"

/*
** @TESTABLE
*/

static t_dict	*g_envdict = NULL;

int		init_env()
{
  extern char	**environ;
  char		*key;
  char		*value;

  g_envdict = dict_new(llist_get_dict(), &free, &free, &strcmp);
  if (g_envdict == NULL)
    return (-1);
  while (*environ != NULL)
    {
      if ((key = strtok(*environ, "=")) == NULL)
	return (-1);
      if ((value = strtok(NULL, "=")) == NULL)
	value = "";
      if ((key = strdup(key)) == NULL)
	return (-1);
      if ((value = strdup(value)) == NULL)
	return (free(key), -1);
      dict_set(g_envdict, key, value);
      ++environ;
    }
  return (0);
}

void	destroy_env()
{
  if (g_envdict != NULL)
    dict_destroy(g_envdict);
}

char		**get_all_env()
{
  char		**env;
  char		*key;
  char		*value;
  t_dict_entry	**entries;
  unsigned int	size;
  unsigned int	i;

  assert(g_envdict != NULL);
  size = dict_length(g_envdict);
  entries = dict_get_entries(g_envdict);
  if (entries == NULL ||
      (env = malloc(sizeof(char *) * (size + 1))) == NULL)
    return (NULL);
  i = 0;
  while (i < size)
    {
      key = DICT_KEY(entries[i], char *);
      value = DICT_VALUE(entries[i], char *);
      if ((env[i] = malloc(strlen(key) + 1 + strlen(value) + 1)) == NULL)
	return (NULL);
      sprintf(env[i], "%s=%s", key, value);
      ++i;
    }
  env[i] = NULL;
  return (env);
}

char	*my_getenv(char *key)
{
  assert(g_envdict != NULL);
  assert(key != NULL);
  return (dict_get(g_envdict, key));
}

char	*my_setenv(char *key, char *value)
{
  assert(g_envdict != NULL);
  assert(key != NULL);
  if (value == NULL)
    {
      dict_remove(g_envdict, key);
      return (NULL);
    }
  if (dict_set(g_envdict, strdup(key), strdup(value)) != 0)
    return (NULL);
  else
    return (value);
}
