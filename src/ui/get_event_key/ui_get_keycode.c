/*
** get_keycode.c for some test in /home/paris_e/Travail/Cprograme/Semestre2/42sh/test_ui
** 
** Made by Adrien Paris
** Login   <paris_e@epitech.net>
** 
** Started on  Wed Apr 15 14:58:11 2015 Adrien Paris
** Last update Thu Apr 30 17:25:32 2015 Adrien Paris
*/

#include <unistd.h>

void	ui_empty_buffer(char *buffer, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      buffer[i] = 0;
      i++;
    }
}

unsigned long		ui_get_keycode()
{
  unsigned long		code;
  char			buffer[8];
  int			i;

  ui_empty_buffer(buffer, 8);
  read(0, buffer, 8);
  i = 8;
  code = 0;
  while (i >= 0)
    {
      code = code * 0x100;
      code += buffer[i];
      i--;
    }
  return (code);
}
