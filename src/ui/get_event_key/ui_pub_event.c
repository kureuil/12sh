/*
** ui_pub_event.c for 42sh in /home/paris_e/Travail/Cprograme/Semestre2/42sh/42sh
** 
** Made by Adrien Paris
** Login   <paris_e@epitech.net>
** 
** Started on  Tue May 12 17:01:12 2015 Adrien Paris
** Last update Sat May 23 23:13:27 2015 Adrien Paris
*/

#include "my/my.h"
#include "pubsub.h"
#include "ui/get_key.h"
#include "ui/key_code.h"

/*
** @TESTABLE
*/

void			ui_pub_event(unsigned long code, t_dict *dict_key)
{
  void			*event;
  size_t		tmp;
  struct s_vec		*vec;
  struct s_iterator	i;

  if (code >= ' ' && code <= '~')
    vm_trigger_event(UI_WRITE, &code);
  if ((vec = dict_get(dict_key, (void *) code)) != NULL)
    {
      i = vec_iterator(vec);
      FOREACH(event IN &i)
	{
	  tmp = (size_t) event;
	  vm_trigger_event((int) tmp, NULL);
	}
    }
  if (code != K_M_LEFT && code != K_CTRL_M_LEFT && code != K_M_RIGHT
      && code != K_CTRL_M_RIGHT && code != K_INSERT)
    vm_trigger_event(UI_RESET_SELECT_POS, NULL);
}
