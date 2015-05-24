/*
** disp_cmdl.c for ui in /home/paris_e/Travail/Cprograme/Semestre2/42sh/V2
** 
** Made by Adrien Paris
** Login   <paris_e@epitech.net>
** 
** Started on  Mon Apr 27 21:08:06 2015 Adrien Paris
** Last update Sun May 24 18:36:47 2015 Adrien Paris
*/

#include <sys/ioctl.h>
#include "pubsub.h"
#include "ui/disp_cmdl.h"
#include "ui/edit_cmdl.h"
#include "mathematic.h"

void			ui_clear_cmdl(int size)
{
  struct winsize        w;
  int			nb_line;

  ioctl(0, TIOCGWINSZ, &w);
  nb_line = (size) / (w.ws_col);
  while (nb_line >= 1)
    {
      ui_modul_str("up");
      nb_line--;
    }
  write(1, "\r", 1);
  ui_modul_str("cd");
  write(1, "\r", 1);
}

void			ui_color_cursor()
{
  extern t_command_line	g_cmdl;

  if (g_cmdl.insert_mod == true)
    ui_modul_str("mr");
  else
    ui_modul_str("us");
  ui_modul_str("mb");
}

void			ui_color_reset()
{
  ui_modul_str("ue");
  ui_modul_str("me");
}

void			ui_disp_cmdl(t_event e, void *data)
{
  extern t_command_line	g_cmdl;
  static int		size = 0;

  (void) e;
  (void) data;
  ui_clear_cmdl(size);
  write(1, "$>", 2);
  size = 2;
  if (g_cmdl.exit == 0)
    {
      if (g_cmdl.select_pos == -1 ||
	  (size_t) g_cmdl.select_pos == g_cmdl.cursor)
	ui_disp_wo_select();
      else
	ui_disp_w_select();
      if (g_cmdl.cursor != g_cmdl.size)
	write(g_cmdl.tty, " ", 1);
      size += g_cmdl.size;
    }
  else
    {
      write(1, g_cmdl.str, g_cmdl.size);
      size = 0;
    }
}
