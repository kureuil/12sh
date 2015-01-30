/*
** char.c for fabrish in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Tue Jan 27 14:43:27 2015 Louis Person
** Last update Fri Jan 30 12:13:04 2015 Louis Person
*/

#include <stdbool.h>
#include <stdlib.h>

bool	char_is_whitespace(char c)
{
  return (c == '\t' || c == ' ');
}

bool	char_is_regular(char c)
{
  return (!char_is_whitespace(c) && c != '|' && c != '&' &&
	  c != ';' && c != '\n' && c != '(' && c != ')');
}

void	skip_whitespace(char **str)
{
  if (str == NULL || *str == NULL)
    return;
  while (char_is_whitespace(**str) == true)
    (*str)++;
}
