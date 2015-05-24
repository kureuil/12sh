/*
** ui_prepare_dict_vec.c for 42sh in /home/paris_e/Travail/Cprograme/Semestre2/42sh/42sh
** 
** Made by Adrien Paris
** Login   <paris_e@epitech.net>
** 
** Started on  Fri May 15 17:02:49 2015 Adrien Paris
** Last update Sun May 24 19:20:08 2015 Adrien Paris
*/

#include <stdarg.h>
#include "my/dictionnary.h"
#include "my/vector.h"
#include "pubsub.h"
#include "ui/get_key.h"
#include "ui/key_code.h"

int		ui_compare_key_eq_int(void *a, void *b)
{
  return (a != b);
}

int			ui_link_ev_kc(t_dict *dict_key,
					unsigned long key, int nb_arg, ...)
{
  va_list		ap;
  struct s_vec		*vec;
  int			value;
  size_t		tmp;

  if (vec_new(&vec) != 0)
    return (1);
  if (vec_init(vec, 4, NULL) != 0)
    return (1);
  va_start(ap, nb_arg);
  while (nb_arg > 0)
    {
      value = va_arg(ap, int);
      tmp = (size_t) value;
      if (vec_push(vec, (void *) tmp) != 0)
	return (1);
      nb_arg--;
    }
  if ((dict_set(dict_key, (void *) key, vec)) != OK)
    return (1);
  return (0);
}
