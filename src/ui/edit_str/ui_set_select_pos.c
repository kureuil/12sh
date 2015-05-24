/*
** set_select_pos.c for ui in /home/paris_e/Travail/Cprograme/Semestre2/42sh/V2
** 
** Made by Adrien Paris
** Login   <paris_e@epitech.net>
** 
** Started on  Mon Apr 27 14:40:20 2015 Adrien Paris
** Last update Mon May  4 22:36:37 2015 Adrien Paris
*/

#include "pubsub.h"
#include "ui/edit_cmdl.h"

void			ui_set_select_pos(t_event e, void *data)
{
  extern t_command_line	g_cmdl;

  (void) e;
  (void) data;
  if (g_cmdl.select_pos == -1)
    g_cmdl.select_pos = g_cmdl.cursor;
}

void			ui_reset_select_pos(t_event e, void *data)
{
  extern t_command_line	g_cmdl;

  (void) e;
  (void) data;
  g_cmdl.select_pos = -1;
}
