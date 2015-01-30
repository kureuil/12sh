/*
** call.c for fabrish in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Tue Jan 27 14:35:57 2015 Louis Person
** Last update Fri Jan 30 12:12:47 2015 Louis Person
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "char.h"
#include "lexer.h"

int	get_word_len(const char *str)
{
  int	i;
  bool	quoted;
  int	q;

  if (str == NULL)
    return (-1);
  i = q = 0;
  quoted = false;
  while (str[i] != '\0' &&
	 (quoted == true ||
	  (quoted == false && char_is_regular(str[i]) == true)))
    {
      if (str[i] == '"')
	{
	  quoted = (quoted == true ? false : true);
	  q++;
	}
      i++;
    }
  if (quoted == false)
    return (i - q);
  return (-1);
}

char	*extract_word(char **str)
{
  int	i;
  int	len;
  char	*word;
  int	shift;

  if ((len = get_word_len(*str)) <= 0)
    return (NULL);
  if ((word = malloc(len + 1)) == NULL)
    return (NULL);
  i = -1;
  shift = 0;
  while (++i < len)
    {
      if ((*str)[i + shift] == '"')
        shift++;
      word[i] = (*str)[i + shift];
    }
  if (shift > 0)
    shift++;
  word[i] = '\0';
  (*str) += (i + shift);
  return (word);
}

t_token		*grammar_call(char **str)
{
  t_darray	*command;
  char		*word;
  t_token	*res;

  if ((command = create_dynamo(NULL)) == NULL)
    return (NULL);
  if (token_new(&res) == -1)
    return (NULL);
  res->type = T_CALL;
  while ((word = extract_word(str)) != NULL)
    {
      command->add(command, word);
      skip_whitespace(str);
    }
  command->add(command, NULL);
  res->value = command;
  return (res);
}
