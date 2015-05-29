/*
** expand.c for 42sh in /home/ouvran_a/Documents/rendu/42sh/src/expand
** 
** Made by Antoine Ouvrans
** Login   <ouvran_a@epitech.net>
** 
** Started on  Sat May 23 15:12:39 2015 Antoine Ouvrans
** Last update Fri May 29 23:42:24 2015 Louis Person
*/

#include <stdlib.h>
#include <assert.h>
#include "tokenizer/tokenizer.h"
#include "tokenizer/token.h"
#include "my/my.h"
#include "expand.h"
#include "env/env.h"

/*
** @TESTABLE
*/

static ssize_t	copy_env(struct s_string *string, char *env)
{
  size_t	i;

  i = 0;
  while (env[i])
    {
      if (env[i] == '\\' || env[i] == ' ')
	{
	  if ((string_push(string, '\\')) == -1)
	    return (-1);
	}
      if ((string_push(string, env[i])) == -1)
	return (-1);
      i++;
    }
  return (i);
}

ssize_t		  expand(const char *str, struct s_string *string)
{
  size_t	  i;
  struct s_string string2;
  char		  *env;

  i = 1;
  if (string_init(&string2) != 0)
    return (-1);
  while (str[i] && str[i] != ' ' && str[i] != '\t' &&
	 str[i] != '/' && str[i] != '-' && str[i] != '\'' &&
	 str[i] != '"' && str[i] != '$')
    {
      if (string_push(&string2, str[i]) != 0)
	return (-1);
      i++;
    }
  if ((env = my_getenv(string2._string)) == NULL)
    return (string_destroy(&string2), -1);
  if ((copy_env(string, env)) == -1)
    return (string_destroy(&string2), -1);
  string_destroy(&string2);
  return (i);
}
