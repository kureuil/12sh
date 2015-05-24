/*
** tokenizer.c for 42sh in /home/brendan/rendu/42sh/src/tokenizer
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Tue Apr 21 16:24:48 2015 Brendan Rius
** Last update Sun May 24 17:15:08 2015 Antoine Ouvrans
*/

#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "my/my.h"
#include "tokenizer/tokenizer.h"
#include "tokenizer/token.h"

/*
** These are the token parser sorted by priority
*/

static t_token_parser	g_parsers[] =
  {
    &parse_token_orif,
    &parse_token_andif,
    &parse_token_pipe,
    &parse_token_tlredir,
    &parse_token_drredir,
    &parse_token_dlredir,
    &parse_token_rredir,
    &parse_token_lredir,
    &parse_token_semicolon,
    &parse_token_string,
    NULL
  };

static bool		call_tokenizers(const char *string,
					struct s_vec *queue,
					struct s_token *token,
					size_t *i)
{
  size_t		j;
  ssize_t		tmp;

  j = 0;
  while (g_parsers[j] != NULL)
    {
      tmp = g_parsers[j](string + *i, token);
      if (tmp != -1 && tmp != 0)
	{
	  vec_push(queue, token);
	  *i += tmp;
	  return (true);
	}
      ++j;
    }
  return (false);
}

static void	free_token_queue(struct s_token *t)
{
  string_destroy(&(t->string));
  free(t);
}

ssize_t			tokenize(const char *string,
				 struct s_vec *queue)
{
  size_t		i;
  size_t		len;
  struct s_token	*token;

  assert(string != NULL);
  assert(queue != NULL);
  if (vec_init(queue, 0, &free_token_queue) == -1)
    return (-1);
  len = strlen(string);
  i = 0;
  while (i < len)
    {
      if (string[i] == ' ' || string[i] == '\t')
	{
	  ++i;
	  continue;
	}
      if (token_new(&token) != 0 || token_init(token) != 0)
	return (-1);
      if (!call_tokenizers(string, queue, token, &i))
	i += 1;
    }
  return (queue->size);
}
