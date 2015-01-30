/*
** parser.c for fabrish in /home/person_l/rendu/minishell1/fabrish
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Wed Jan 28 11:25:28 2015 Louis Person
** Last update Fri Jan 30 10:47:24 2015 Louis Person
*/

#include <stdlib.h>
#include "my.h"
#include "lexer.h"
#include "parser.h"

t_parser	*get_parsers()
{
  t_parser	*parsers;

  if ((parsers = malloc(sizeof(t_parser) * TOKEN_TYPES)) == NULL)
    return (NULL);
  parsers[T_UNDEFINED] = &parse_undefined;
  parsers[T_STRING] = &parse_string;
  parsers[T_CALL] = &parse_call;
  parsers[T_AND] = &parse_and;
  parsers[T_OR] = &parse_or;
  parsers[T_EOC] = &parse_eoc;
  parsers[T_EOF] = &parse_eof;
  parsers[T_SOF] = &parse_sof;
  parsers[T_LPARENTHESIS] = &parse_lparenthesis;
  parsers[T_RPARENTHESIS] = &parse_rparenthesis;
  return (parsers);
}

t_error			parse(t_queue *tokens, t_tree *parent)
{
  static t_parser	*parsers = NULL;
  t_token		*token;

  if (parent == NULL)
    return (NULL_POINTER);
  if (parsers == NULL && (parsers = get_parsers()) == NULL)
    return (COULD_NOT_MALLOC);
  token = tokens->peek(tokens);
  if (token == NULL)
    return (PARSE_ERROR);
  return (parsers[token->type](tokens, parent));
}
