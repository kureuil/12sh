/*
** pubsub.c for corewar in /home/brendan/rendu/CPE_2014_corewar
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Fri Feb 27 06:30:06 2015 Brendan Rius
** Last update Mon Mar 16 17:28:06 2015 Brendan Rius
*/

#include <stdlib.h>
#include "pubsub.h"

/*
** As a static variable, the array should be filled with NULL
*/
static t_subscriber	g_subscribers[_NB_EVENTS][MAX_SUBSCRIBERS];

t_vm_hook	vm_register_hook(t_event event,
				 t_subscriber sub)
{
  size_t	i;

  if (event >= _NB_EVENTS)
    return (-1);
  i = 0;
  while (i < MAX_SUBSCRIBERS)
    {
      if (g_subscribers[event][i] == NULL)
	{
	  g_subscribers[event][i] = sub;
	  return (i);
	}
      ++i;
    }
  return (-1);
}

void		vm_unregister_hook(t_event event, t_vm_hook hook_id)
{
  if (hook_id >= 0 && hook_id < MAX_SUBSCRIBERS)
    g_subscribers[event][hook_id] = NULL;
}

void		vm_trigger_event(t_event event, void *data)
{
  size_t	i;

  if (event >= _NB_EVENTS)
    return;
  i = 0;
  while (i < MAX_SUBSCRIBERS)
    {
      if (g_subscribers[event][i] != NULL)
	g_subscribers[event][i](event, data);
      ++i;
    }
}
