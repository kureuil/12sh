/*
** move_up.c for ui in /home/paris_e/Travail/Cprograme/Semestre2/42sh/V2
** 
** Made by Adrien Paris
** Login   <paris_e@epitech.net>
** 
** Started on  Tue Apr 28 16:01:28 2015 Adrien Paris
** Last update Wed May 13 15:28:42 2015 Adrien Paris
*/

#include "pubsub.h"
#include "ui/edit_cmdl.h"

void			ui_move_cursor_up(t_event e, void *data)
{
  struct winsize        w;
  extern t_command_line	g_cmdl;
  int			size;

  (void) e;
  (void) data;
  ioctl(0, TIOCGWINSZ, &w);
  size = g_cmdl.size + g_cmdl.prompt_size;
  if (w.ws_row / size )

}
