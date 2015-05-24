/*
** ui_disp_part_cmdl.c for 42sh in /home/adrien/Travail/Cprograme/Semestre2/42sh/42sh
** 
** Made by Adrien Paris
** Login   <adrien@epitech.net>
** 
** Started on  Sat May 23 21:50:01 2015 Adrien Paris
** Last update Sun May 24 15:06:29 2015 Adrien Paris
*/

#include "ui/disp_cmdl.h"
#include "ui/edit_cmdl.h"
#include "mathematic.h"

void			ui_disp_wo_select()
{
  extern t_command_line	g_cmdl;

  write(g_cmdl.tty, g_cmdl.str, g_cmdl.cursor);
  ui_color_cursor();
  write(g_cmdl.tty, g_cmdl.str + g_cmdl.cursor, 1);
  ui_color_reset();
  if (g_cmdl.cursor != g_cmdl.size)
  write(g_cmdl.tty, g_cmdl.str + g_cmdl.cursor + 1, g_cmdl.size -
  	(g_cmdl.cursor + 1));
}

void			ui_disp_w_select()
{
  extern t_command_line	g_cmdl;
  size_t		min;
  size_t		max;

  min = math_min(g_cmdl.cursor, g_cmdl.select_pos);
  max = math_max(g_cmdl.cursor, g_cmdl.select_pos);
  write(g_cmdl.tty, g_cmdl.str, min);
  ui_putstr("\033[37m\033[44m");
  if (g_cmdl.cursor == min)
    ui_color_cursor();
  write(g_cmdl.tty, g_cmdl.str + min, 1);
  ui_color_reset();
  ui_putstr("\033[37m\033[44m");
  write(g_cmdl.tty, g_cmdl.str + min + 1, max - (min + 1));
  ui_color_reset();
  if (g_cmdl.cursor == max)
    ui_color_cursor();
  write(g_cmdl.tty, g_cmdl.str + max, 1);
  ui_color_reset();
  write(g_cmdl.tty, g_cmdl.str + max + 1, g_cmdl.size - max - 1);
}
