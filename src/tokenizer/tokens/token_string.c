/*
** token_string.c for 42sh in /home/ouvran_a/Documents/rendu/42sh
** 
** Made by Antoine Ouvrans
** Login   <ouvran_a@epitech.net>
** 
** Started on  Sun May 24 08:26:11 2015 Antoine Ouvrans
** Last update Sun May 24 19:32:41 2015 Antoine Ouvrans
*/

#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "tokenizer/tokenizer.h"
#include "tokenizer/token.h"
#include "my/my.h"

/*
** @TESTABLE
*/

static int	init_string_token(const char *str, struct s_string *str2, int *i,
				  char	*inib)
{
  while (str[(*i)] && (str[(*i)] != '"' && str[(*i)] != '\'' &&
		       str[(*i)] != 0 && str[(*i)] != '\t' &&
		       str[(*i)] != ' ' && str[(*i)] != '<')
         && str[(*i)] != '&' && str[(*i)] != '|' &&
	 str[(*i)] != ';' && str[(*i)] != '>')
    if (string_push(str2, str[(*i)++]) != 0)
      return (-1);
  if (str[(*i)] != '"' && str[(*i)] != '\'')
    return ((*i));
  inib[0] = str[(*i)++];
  return (-2);
}
static int      get_string_token(const char *str, struct s_string *str2)
{
  int	        i;
  char		inib;
  int		j;

  i = 0;
  if ((j = init_string_token(str, str2, &i, &inib)) != -2)
    return (j);
  while (str[i] && str[i] != inib)
    {
      if (str[i] == '\\' && (str[i + 1] == inib || str[i + 1] == '\\'))
	{
	  if ((string_push(str2, str[++i]) != 0))
	    return (-1);
	  i++;
	}
      if (string_push(str2, str[i++]) != 0)
	return (-1);
    }
  if (str[i] == inib && (str[i + 1] != ' ' || str[i + 1] != '\t'))
    {
      if ((j = get_string_token(str + ++i, str2)) == -1)
	return (-1);
      i += j;
    }
  return (i);
}

static int	is_syntax_correct(const char *str)
{
  int		i;
  char		inib;

  i = 0;
  while (str[i] != 0 && str[i] != '\'' && str[i] != '"')
    i++;
  if ((inib = str[i]) == 0)
    return (0);
  i++;
  while (str[i] != 0)
    {
      if (str[i] == inib)
        {
          if (str[i - 1] != '\\')
            break;
        }
      i++;
    }
  if (str[i] != inib)
    return (-1);
  i++;
  if ((is_syntax_correct(str + i)) == -1)
    return (-1);
  return (0);
}

ssize_t	parse_token_string(const char *s, struct s_token *t)
{
  assert(s != NULL);
  assert(t != NULL);
  if (is_syntax_correct(s) == -1)
    return (-1);
  t->type = TT_STRING;
  return (get_string_token(s, &(t->string)));
}
