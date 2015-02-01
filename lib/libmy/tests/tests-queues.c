/*
** tests-queues.c for libmy in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Wed Jan 28 13:34:27 2015 Louis Person
** Last update Wed Jan 28 21:34:52 2015 Louis Person
*/

#include <stdlib.h>
#include "my.h"

int		main()
{
  t_queue	*q;

  if (queue_new(&q, &free) != OK)
    chalk_red("Could not create queue\n");
  q->add(q, my_strdup("Hello World"));
  q->add(q, my_strdup("Carabaffe"));
  q->add(q, my_strdup("Scyther"));
  if (q->size != 3)
    chalk_red("size error\n");
  my_putstr(q->peek(q));
  free(q->pop(q));
  my_putchar('\n');
  my_putstr(q->peek(q));
  free(q->pop(q));
  my_putchar('\n');
  my_putstr(q->peek(q));
  free(q->pop(q));
  my_putchar('\n');
  if (queue_delete(q) != OK)
    chalk_red("Could not free queue\n");
  return (0);
}
