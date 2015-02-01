/*
** dynamo.c for libmy in /home/person_l
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Wed Nov 26 22:56:49 2014 Louis Person
** Last update Mon Jan 26 00:41:41 2015 Louis Person
*/

#include <stdlib.h>
#include "my.h"

t_darray	*create_dynamo(int (*free_fn)(void *))
{
  t_darray	*dynamo;
  int		c;

  if ((dynamo = malloc(sizeof(t_darray))) == NULL)
    return (NULL);
  dynamo->total_size = 2;
  dynamo->current_size = 0;
  if ((dynamo->data = malloc(sizeof(void *) * dynamo->total_size)) == NULL)
    return (NULL);
  c = -1;
  while (++c < dynamo->total_size)
    dynamo->data[c] = NULL;
  dynamo->add = &add_item_to_dynamo;
  if (free_fn != NULL)
    dynamo->free = free_fn;
  else
    dynamo->free = &free_item_from_dynamo;
  return (dynamo);
}

int	free_dynamo(t_darray *dynamo)
{
  int	c;

  c = 0;
  while (c < dynamo->current_size)
    {
      if (dynamo->data[c] != NULL)
	dynamo->free(dynamo->data[c]);
      c++;
    }
  free(dynamo->data);
  free(dynamo);
  return (0);
}

t_error	dynamo_map(t_darray *dynamo, int (*fn)(void *))
{
  int	c;

  c = -1;
  while (++c < dynamo->current_size)
    fn(dynamo->data[c]);
  return (OK);
}

int	add_item_to_dynamo(t_darray *dynamo, void *item)
{
  void	**new_data;
  int	c;

  if (dynamo->current_size == dynamo->total_size)
    {
      dynamo->total_size *= 2;
      if ((new_data = malloc(sizeof(void *) * dynamo->total_size)) == NULL)
	return (-1);
      c = -1;
      while (++c < dynamo->current_size)
	new_data[c] = dynamo->data[c];
      c -= 1;
      while (++c < dynamo->total_size)
	new_data[c] = NULL;
      free(dynamo->data);
      dynamo->data = new_data;
    }
  dynamo->data[dynamo->current_size] = item;
  dynamo->current_size++;
  return (0);
}

int	free_item_from_dynamo(void *item)
{
  free(item);
  return (0);
}
