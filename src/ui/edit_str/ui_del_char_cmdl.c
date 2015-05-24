/*
** del_char_cmdl.c for ui in /home/paris_e/Travail/Cprograme/Semestre2/42sh/V2
** 
** Made by Adrien Paris
** Login   <paris_e@epitech.net>
** 
** Started on  Mon Apr 27 16:36:43 2015 Adrien Paris
** Last update Mon May  4 22:33:07 2015 Adrien Paris
*/

#include "pubsub.h"
#include "ui/edit_cmdl.h"

void			ui_delete_char_cmdl(t_event e, void *data)
{
  extern t_command_line	g_cmdl;

  (void) e;
  (void) data;
  if (g_cmdl.select_pos == -1 && g_cmdl.cursor < g_cmdl.size)
    {
      g_cmdl.size--;
      ui_remove_char_to_cmdl(g_cmdl.cursor, g_cmdl.str);
    }
  else if (g_cmdl.select_pos != -1)
    ui_delete_selection();
}
