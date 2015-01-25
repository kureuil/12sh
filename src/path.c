/*
** path.c for minishell1 in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Thu Jan 22 00:19:20 2015 Louis Person
** Last update Mon Jan 26 00:51:20 2015 Louis Person
*/

#include <stdlib.h>
#include "my.h"

char	*path(char *base, char *add)
{
  int	blen;
  int	alen;
  char	*res;

  blen = my_strlen(base);
  alen = my_strlen(add);
  if ((res = malloc(blen + alen + 2)) == NULL)
    return (NULL);
  res[0] = '\0';
  my_strcpy(res, base);
  my_strncat(res, "/", 1);
  my_strncat(res, add, alen);
  return (res);
}

void	update_wd(t_dict *env, char *newd)
{
  char	*oldpwd;

  oldpwd = dict_search(env, "PWD");
  dict_set(env, "OLDPWD", oldpwd);
  if (newd[0] == '/')
    dict_set(env, "PWD", newd);
  else
    dict_set(env, "PWD", path(oldpwd, newd));
}
