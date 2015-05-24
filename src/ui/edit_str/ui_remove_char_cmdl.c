/*
** remove_char_cmdl.c for ui in /home/paris_e/Travail/Cprograme/Semestre2/42sh/V2
** 
** Made by Adrien Paris
** Login   <paris_e@epitech.net>
** 
** Started on  Mon Apr 27 15:55:22 2015 Adrien Paris
** Last update Thu Apr 30 17:27:42 2015 Adrien Paris
*/

#include <stdlib.h>
#include "ui/edit_cmdl.h"

int	ui_remove_char_to_cmdl(int pos, char *str)
{
  int	size;

  size = ui_get_end_cmdl(str);
  while (pos <= size)
    {
      str[pos] = str[pos + 1];
      pos++;
    }
  return (EXIT_SUCCESS);
}
