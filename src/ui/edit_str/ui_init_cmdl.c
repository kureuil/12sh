/*
** init_cmdl.c for ui in /home/paris_e/Travail/Cprograme/Semestre2/42sh/V2
** 
** Made by Adrien Paris
** Login   <paris_e@epitech.net>
** 
** Started on  Mon Apr 27 10:23:10 2015 Adrien Paris
** Last update Sun May 24 18:04:07 2015 Adrien Paris
*/

#include <stdlib.h>
#include "ui/edit_cmdl.h"

void	ui_init_str_line(char str[SIZE_CMDL])
{
  int	i;

  i = 0;
  while (i < SIZE_CMDL)
    {
      str[i] = '1';
      i++;
    }
  str[0] = ' ';
  str[1] = '\0';
}

void			ui_reset_command_line()
{
  extern t_command_line g_cmdl;

  g_cmdl.insert_mod = true;
  ui_init_str_line(g_cmdl.str);
  g_cmdl.size = ui_get_end_cmdl(g_cmdl.str);
  g_cmdl.cursor = g_cmdl.size;
  g_cmdl.select_pos = -1;
  g_cmdl.exit = 0;
}

void			ui_init_command_line()
{
  extern t_command_line g_cmdl;

  g_cmdl.insert_mod = true;
  ui_init_str_line(g_cmdl.str);
  ui_init_str_line(g_cmdl.copy);
  g_cmdl.size = ui_get_end_cmdl(g_cmdl.str);
  g_cmdl.size_copy = ui_get_end_cmdl(g_cmdl.copy);
  g_cmdl.cursor = g_cmdl.size;
  g_cmdl.time = 0;
  g_cmdl.select_pos = -1;
  g_cmdl.exit = 0;
}
