/*
** lexicon.c for fabrish in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Tue Jan 27 13:35:55 2015 Louis Person
** Last update Fri Jan 30 10:20:01 2015 Louis Person
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "lexer.h"
#include "lexicon.h"

int	free_callback(void *ptr)
{
  ptr = NULL;
  return (1);
}

int	lexicon(t_darray **grammar)
{
  if ((*grammar = create_dynamo(&free_callback)) == NULL)
    return (-1);
  (*grammar)->add(*grammar, &grammar_eof);
  (*grammar)->add(*grammar, &grammar_eoc);
  (*grammar)->add(*grammar, &grammar_and);
  (*grammar)->add(*grammar, &grammar_or);
  (*grammar)->add(*grammar, &grammar_lparenthesis);
  (*grammar)->add(*grammar, &grammar_rparenthesis);
  (*grammar)->add(*grammar, &grammar_call);
  return (0);
}
