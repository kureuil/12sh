/*
** call.c for fabrish in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Tue Jan 27 14:35:57 2015 Louis Person
** Last update Sun Feb  1 16:33:27 2015 Louis Person
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "char.h"
#include "lexer.h"
#include "shell.h"
#include "lexicon.h"

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

void		add_command(t_darray *cmd, char *word)
{
  t_shell	*shell;
  t_token	*tok;
  char		*alias;
  int		i;

  shell = get_shell();
  if (word[0] != '\\' && (alias = dict_search(shell->alias, word)) != NULL)
    {
      if ((tok = grammar_call(&alias)) == NULL)
	return;
      i = -1;
      while (++i < (((t_darray *)tok->value)->current_size - 1))
        cmd->add(cmd, my_strdup(((t_darray *)tok->value)->data[i]));
      free_dynamo(tok->value);
      tok->value = NULL;
      tok->type = T_UNDEFINED;
      token_delete(tok);
    }
  else if (word[0] == '\\')
    {
      cmd->add(cmd, my_strdup(word + 1));
      free(word);
    }
  else
    cmd->add(cmd, word);
}

t_token		*grammar_call(char **str)
{
  static int	call = 0;
  t_darray	*command;
  char		*word;
  t_token	*res;
  bool		first;

  if (call++ > 100)
    return (NULL);
  first = true;
  if ((command = create_dynamo(NULL)) == NULL)
    return (NULL);
  if (token_new(&res) == -1)
    return (NULL);
  res->type = T_CALL;
  while ((word = extract_word(str)) != NULL)
    {
      first == true ? add_command(command, word) : command->add(command, word);
      skip_whitespace(str);
      first = false;
    }
  command->add(command, NULL);
  res->value = command;
  call--;
  return (res);
}
