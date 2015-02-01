/*
** queues.c for libmy in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Wed Jan 28 12:58:29 2015 Louis Person
** Last update Wed Jan 28 13:48:33 2015 Louis Person
*/

#include <stdbool.h>
#include <stdlib.h>
#include "my.h"

t_error	queue_new(t_queue **queue, void (*free_fn)())
{
  if (queue == NULL || free_fn == NULL)
    return (NULL_POINTER);
  if ((*queue = malloc(sizeof(t_queue))) == NULL)
    return (NULL_POINTER);
  (*queue)->size = 0;
  (*queue)->first = NULL;
  (*queue)->last = NULL;
  (*queue)->free = free_fn;
  (*queue)->peek = &queue_peek;
  (*queue)->pop = &queue_pop;
  (*queue)->add = &queue_add;
  return (OK);
}

t_error	queue_delete(t_queue *queue)
{
  void	*elem;

  if (queue == NULL)
    return (NULL_POINTER);
  while ((elem = queue->pop(queue)) != NULL)
    queue->free(elem);
  free(queue);
  return (OK);
}

void	*queue_peek(t_queue *queue)
{
  if (queue == NULL || queue->size == 0)
    return (NULL);
  return (queue->first->data);
}

void		*queue_pop(t_queue *queue)
{
  void		*data;
  t_node	*head;

  if (queue == NULL || queue->size == 0)
    return (NULL);
  data = queue_peek(queue);
  head = queue->first;
  if (queue->size == 1)
    {
      queue->first = NULL;
      queue->last = NULL;
    }
  else
    {
      queue->first = queue->first->next;
      queue->first->prev = NULL;
    }
  free(head);
  queue->size -= 1;
  return (data);
}

bool		queue_add(t_queue *queue, void *data)
{
  t_node	*new;

  if (queue == NULL || data == NULL)
    return (false);
  new = malloc(sizeof(t_node));
  if (new == NULL)
    return (false);
  new->data = data;
  new->prev = queue->last;
  new->next = NULL;
  if (queue->last != NULL)
    queue->last->next = new;
  if (queue->first == NULL)
    queue->first = new;
  queue->last = new;
  queue->size += 1;
  return (true);
}
