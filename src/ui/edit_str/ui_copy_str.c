/*
** copy_str.c for ui in /home/paris_e/Travail/Cprograme/Semestre2/42sh/V2
** 
** Made by Adrien Paris
** Login   <paris_e@epitech.net>
** 
** Started on  Mon Apr 27 21:30:35 2015 Adrien Paris
** Last update Mon May  4 22:31:33 2015 Adrien Paris
*/

#include <string.h>
#include "ui/edit_cmdl.h"

int	ui_copy_zone_cmdl(char *src, int size, char *dest, int pos)
{
  int	i;
  int	len;

  len = strlen(dest);
  if (len + size >= SIZE_CMDL - 1)
    size = SIZE_CMDL - len - 1;
  len += size;
  while (len > pos)
    {
      dest[len] = dest[len - size];
      len--;
    }
  i = 0;
  while (i < size)
    {
      dest[pos + i] = src[i];
      i++;
    }
  return (size);
}
