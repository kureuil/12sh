/*
** cut_end_cmdl.c for ui in /home/paris_e/Travail/Cprograme/Semestre2/42sh/V2
** 
** Made by Adrien Paris
** Login   <paris_e@epitech.net>
** 
** Started on  Tue Apr 28 12:49:12 2015 Adrien Paris
** Last update Fri May 22 19:28:23 2015 Adrien Paris
*/

#include <stdlib.h>
#include "pubsub.h"
#include "mathematic.h"
#include "ui/edit_cmdl.h"

void			ui_cut_end_cmdl(t_event e, void *data)
{
  extern t_command_line	g_cmdl;
  int			pos_1;
  int			pos_2;
  int			size;

  (void) e;
  (void) data;
  ui_init_str_line(g_cmdl.copy);

  pos_1 = g_cmdl.cursor;
  pos_2 = g_cmdl.size;
  size = math_abs(pos_2 - pos_1);
  ui_copy_zone_cmdl(g_cmdl.str + pos_1, size, g_cmdl.copy, 0);
  ui_delete_zone_str(g_cmdl.str + pos_1, size);
  g_cmdl.cursor = pos_1;
  g_cmdl.size += -size;
}
