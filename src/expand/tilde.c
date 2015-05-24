/*
** tilde.c for 42sh in /home/ouvran_a/Documents/rendu/42sh
** 
** Made by Antoine Ouvrans
** Login   <ouvran_a@epitech.net>
** 
** Started on  Sat May 23 15:39:44 2015 Antoine Ouvrans
** Last update Sun May 24 19:41:56 2015 Antoine Ouvrans
*/

#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <pwd.h>
#include <stdio.h>
#include "tokenizer/tokenizer.h"
#include "tokenizer/token.h"
#include "my/my.h"
#include "env/env.h"
#include "expand.h"

/*
** @TESTABLE
*/

static ssize_t		get_home(struct s_string *string,
				 struct s_string *string2,
				 int i)
{
  char			*env;

  if ((env = my_getenv("HOME")) == NULL)
    return (string_destroy(string2), -1);
  if ((string_cat_str(string, env)) == -1)
    return (string_destroy(string2), -1);
  string_destroy(string2);
  return (i);
}

ssize_t           tilde(const char *str, struct s_string *string)
{
  size_t          i;
  struct s_string string2;
  struct passwd   *pass;

  i = 1;
  if (string_init(&string2) != 0)
    return (-1);
  while (str[i] && str[i] != ' ' && str[i] != '/')
    {
      if (string_push(&string2, str[i]) != 0)
	return (-1);
      i++;
    }
  if (i == 1)
    return (get_home(string, &string2, i));
  else
    {
      if ((pass = getpwnam(string2._string)) == NULL)
	return (-1);
      if ((string_cat_str(string, pass->pw_dir)) == -1)
	return (string_destroy(&string2), -1);
    }
  string_destroy(&string2);
  return (i);
}
