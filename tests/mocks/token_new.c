/*
** mock_malloc.c for 42sh in /home/brendan/rendu/42sh
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu Apr 23 16:12:29 2015 Brendan Rius
** Last update Fri May  1 20:03:45 2015 Brendan Rius
*/

#include "tokenizer/token.h"

static int	(*mock_token_new)(struct s_token **) = &token_new;

int	my_mock_token_new(struct s_token **t)
{
  return (mock_token_new(t));
}

int	my_mock_token_new_fail(struct s_token **t)
{
  (void) t;
  return (-1);
}

void	set_mock_token_new(int (*f)(struct s_token **))
{
  mock_token_new = f;
}
