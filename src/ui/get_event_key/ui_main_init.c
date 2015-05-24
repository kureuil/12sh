/*
** ui_main_init.c for 42sh in /home/adrien/Travail/Cprograme/Semestre2/42sh/42sh
** 
** Made by Adrien Paris
** Login   <adrien@epitech.net>
** 
** Started on  Sat May 23 14:11:42 2015 Adrien Paris
** Last update Sun May 24 21:42:14 2015 Adrien Paris
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include "pubsub.h"
#include "mathematic.h"
#include "my/dictionnary.h"
#include "ui/get_key.h"
#include "ui/edit_cmdl.h"
#include "ui/disp_cmdl.h"

int			ui_init(t_dict **dict_key)
{
  int			ret;
  extern t_command_line	g_cmdl;

  ret = 0;
  (*dict_key) = NULL;
  g_cmdl.emergency = true;
  if (isatty(0) != 1)
    return (EXIT_FAILURE);
  if (dict_key != NULL)
    if (((*dict_key) = ui_link_event_keycode()) == NULL)
      return (EXIT_FAILURE);
  ret += math_is_neg(ui_init_edit_cmdl());
  ret += math_is_neg(ui_init_disp_cmdl());
  if (ret != 0)
    return (EXIT_FAILURE);
  if (ui_set_tgetenv() == EXIT_FAILURE)
    return (EXIT_FAILURE);
  g_cmdl.emergency = false;
  ui_init_prompt();
  return (EXIT_SUCCESS);
}

void			ui_destroy(t_dict *dict_key)
{
  extern t_command_line	g_cmdl;
  free(g_cmdl.hostname);
  if (dict_key != NULL)
    dict_destroy(dict_key);
}
