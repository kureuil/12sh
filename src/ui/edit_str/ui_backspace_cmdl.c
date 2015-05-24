/*
** backspace_cmdl.c for ui in /home/paris_e/Travail/Cprograme/Semestre2/42sh/V2
** 
** Made by Adrien Paris
** Login   <paris_e@epitech.net>
** 
** Started on  Mon Apr 27 15:21:34 2015 Adrien Paris
** Last update Thu May  7 21:48:08 2015 Adrien Paris
*/

#include <stdlib.h>
#include "pubsub.h"
#include "ui/edit_cmdl.h"

void			ui_backspace_cmdl(t_event e, void *data)
{
  extern t_command_line	g_cmdl;

  (void) e;
  (void) data;
  if (g_cmdl.select_pos == -1 && g_cmdl.cursor > 0)
    {
      g_cmdl.cursor--;
      if (g_cmdl.cursor + 1 == g_cmdl.size || g_cmdl.insert_mod == true)
	{
	  ui_remove_char_to_cmdl(g_cmdl.cursor, g_cmdl.str);
	  g_cmdl.size--;
	}
      else
	{
	  g_cmdl.str[g_cmdl.cursor] = ' ';
	}
    }
  else if (g_cmdl.select_pos != -1)
      ui_delete_selection();
}
