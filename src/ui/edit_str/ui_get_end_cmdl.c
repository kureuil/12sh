/*
** get_end_cmdl.c for ui in /home/paris_e/Travail/Cprograme/Semestre2/42sh/V2
** 
** Made by Adrien Paris
** Login   <paris_e@epitech.net>
** 
** Started on  Mon Apr 27 10:38:31 2015 Adrien Paris
** Last update Wed May  6 13:55:41 2015 Adrien Paris
*/

#include "ui/edit_cmdl.h"

int	ui_get_end_cmdl(char str[SIZE_CMDL])
{
  int	i;

  i = 0;
  while (str[i] != '\0' && i < SIZE_CMDL)
    i++;
  if (i == 0)
    {
      str[0] = ' ';
      str[1] = '\0';
      i++;
    }
  else if (i == SIZE_CMDL)
    {
      str[i - 1] = ' ';
      str[i] = '\0';
    }
  return (i - 1);
}
