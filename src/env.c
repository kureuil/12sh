/*
** env.c<2> for fabrish in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Wed Jan 28 10:23:22 2015 Louis Person
** Last update Thu Jan 29 12:07:41 2015 Louis Person
*/

#include <stdlib.h>
#include "my.h"

t_dict		*parse_env()
{
  extern char	**environ;
  char		*value;
  char		*copy;
  t_dict	*env;
  char		*key;
  int		i;

  i = 0;
  if ((dict_new(&env)) == -1)
    return (NULL);
  while (environ[i] != NULL)
    {
      copy = environ[i];
      key = my_strsep(&copy, "=");
      value = my_strdup(copy);
      dict_set(env, key, value);
      free(key);
      i++;
    }
  return (env);
}

char	*serialize_env(char *key, char *value)
{
  int	klen;
  int	vlen;
  char	*res;

  klen = my_strlen(key);
  vlen = my_strlen(value);
  if ((res = malloc(klen + vlen + 2)) == NULL)
    return (NULL);
  my_strcpy(res, key);
  my_strncat(res, "=", 1);
  my_strncat(res, value, vlen);
  return (res);
}

void	free_env(char **env)
{
  int	i;

  i = 0;
  while (env[i] != NULL)
    {
      free(env[i]);
      i++;
    }
  free(env);
}
