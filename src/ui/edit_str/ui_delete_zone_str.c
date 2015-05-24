/*
** delete_zone_str.c for  in /home/paris_e/Travail/Cprograme/Semestre2/42sh/V2
** 
** Made by Adrien Paris
** Login   <paris_e@epitech.net>
** 
** Started on  Mon Apr 27 16:21:52 2015 Adrien Paris
** Last update Fri May 22 19:28:46 2015 Adrien Paris
*/
#include "mathematic.h"
#include "ui/edit_cmdl.h"

void	ui_delete_zone_str(char *str, int size)
{
  int	i;

  i = 0;
  while (str[i + size] != '\0')
    {
      str[i] = str[i + size];
      i++;
    }
  str[i] = '\0';
}

void			ui_delete_selection()
{
  extern t_command_line	g_cmdl;
  int			pos_1;
  int			pos_2;
  int			size;

  pos_1 = math_min(g_cmdl.cursor, g_cmdl.select_pos);
  pos_2 = math_max(g_cmdl.cursor, g_cmdl.select_pos);
  size = math_abs(pos_2 - pos_1);
  ui_delete_zone_str(g_cmdl.str + pos_1, size);
  g_cmdl.cursor = pos_1;
  g_cmdl.size += -size;
}
