/*
** move_cursor.c for ui in /home/paris_e/Travail/Cprograme/Semestre2/42sh/V2
** 
** Made by Adrien Paris
** Login   <paris_e@epitech.net>
** 
** Started on  Mon Apr 27 12:09:17 2015 Adrien Paris
** Last update Mon May 11 14:47:15 2015 Adrien Paris
*/

#include "pubsub.h"
#include "ui/edit_cmdl.h"

void			ui_move_cursor_left(t_event e, void *data)
{
  extern t_command_line	g_cmdl;

  (void) e;
  (void) data;
  if (g_cmdl.cursor > 0)
    g_cmdl.cursor--;
}

void			ui_move_cursor_right(t_event e, void *data)
{
  extern t_command_line	g_cmdl;

  (void) e;
  (void) data;
  if (g_cmdl.cursor < g_cmdl.size)
    g_cmdl.cursor++;
}

void			ui_move_cursor_begin(t_event e, void *data)
{
  extern t_command_line	g_cmdl;

  (void) e;
  (void) data;
  g_cmdl.cursor = 0;
}

void			ui_move_cursor_end(t_event e, void *data)
{
  extern t_command_line	g_cmdl;

  (void) e;
  (void) data;
  g_cmdl.cursor = g_cmdl.size;
}
