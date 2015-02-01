/*
** alias.c for fabrish in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Sun Feb  1 14:59:20 2015 Louis Person
** Last update Sun Feb  1 17:17:40 2015 Louis Person
*/

#include <stdlib.h>
#include "my.h"

t_dict		*get_alias()
{
  t_dict	*alias;

  if (dict_new(&alias) == -1)
    return (NULL);
  return (alias);
}
