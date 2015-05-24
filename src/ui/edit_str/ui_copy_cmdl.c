/*
** copy_cmdl.c for ui in /home/paris_e/Travail/Cprograme/Semestre2/42sh/V2
** 
** Made by Adrien Paris
** Login   <paris_e@epitech.net>
** 
** Started on  Mon Apr 27 21:38:37 2015 Adrien Paris
** Last update Fri May 22 19:27:42 2015 Adrien Paris
*/

#include <stdlib.h>
#include "pubsub.h"
#include "mathematic.h"
#include "ui/edit_cmdl.h"

void			ui_copy_cmdl(t_event e, void *data)
{
  extern t_command_line	g_cmdl;
  int			pos_1;
  int			pos_2;
  int			size;

  (void) e;
  (void) data;
  ui_init_str_line(g_cmdl.copy);
  if (g_cmdl.select_pos != -1)
    {
      pos_1 = math_min(g_cmdl.cursor, g_cmdl.select_pos);
      pos_2 = math_max(g_cmdl.cursor, g_cmdl.select_pos);
      size = math_abs(pos_2 - pos_1);
      g_cmdl.size_copy = ui_copy_zone_cmdl(g_cmdl.str + pos_1,
					   size, g_cmdl.copy, 0);
    }
}
