/*
** env.c for minishell1 in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Wed Jan 21 22:56:21 2015 Louis Person
** Last update Thu Jan 22 00:17:19 2015 Louis Person
*/

#include <unistd.h>
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
      i++;
    }
  return (env);
}

void	puts_env(void *ptr)
{
  t_bucket	*bucket;

  bucket = (t_bucket *)ptr;
  my_putstr(bucket->key);
  my_putchar('=');
  my_putstr(bucket->data);
  my_putchar('\n');
}
