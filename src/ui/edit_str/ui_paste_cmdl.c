/*
** paste_cmdl.c for ui in /home/paris_e/Travail/Cprograme/Semestre2/42sh/V2
** 
** Made by Adrien Paris
** Login   <paris_e@epitech.net>
** 
** Started on  Mon Apr 27 22:25:30 2015 Adrien Paris
** Last update Fri May 22 19:29:13 2015 Adrien Paris
*/

#include <stdlib.h>
#include "pubsub.h"
#include "mathematic.h"
#include "ui/edit_cmdl.h"

void			ui_paste_cmdl(t_event e, void *data)
{
  extern t_command_line	g_cmdl;
  int			size;

  (void) e;
  (void) data;

  size = ui_get_end_cmdl(g_cmdl.copy);
  size = ui_copy_zone_cmdl(g_cmdl.copy, size, g_cmdl.str, g_cmdl.cursor);
  g_cmdl.size += size;
  g_cmdl.cursor += size;
}
