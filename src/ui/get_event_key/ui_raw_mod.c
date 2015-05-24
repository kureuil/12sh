/*
** raw_mod.c for allum1 in /home/paris_e/Travail/Cprograme/Semestre2/Allum1/Draft
** 
** Made by Adrien Paris
** Login   <paris_e@epitech.net>
** 
** Started on  Wed Feb 18 16:09:33 2015 Adrien Paris
** Last update Sat May 23 00:42:41 2015 Adrien Paris
*/

#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include <stdio.h>

int             ui_set_attr(struct termios *t)
{
  if (tcsetattr(0, 1, t) == -1)
    {
      fprintf(stderr, "/!\\ tcsetattr failled\n");
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int                     ui_raw_mode()
{
  struct termios        t;
  int			failure;

  tcgetattr(0, &t);
  t.c_cc[VMIN] = 1;
  t.c_cc[VTIME] = 0;
  t.c_lflag &= ~(ECHO | ICANON);
  failure = ui_set_attr(&t);
  if (failure == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
