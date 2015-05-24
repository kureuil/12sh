/*
** modul_str.c for ui in /home/paris_e/Travail/Cprograme/Semestre2/42sh/Draft
** 
** Made by Adrien Paris
** Login   <paris_e@epitech.net>
** 
** Started on  Wed Apr 22 15:27:18 2015 Adrien Paris
** Last update Sun May 24 15:07:04 2015 Adrien Paris
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <term.h>
#include <termios.h>
#include <termcap.h>
#include "ui/disp_cmdl.h"
#include "ui/edit_cmdl.h"

void			ui_putstr(char *str)
{
  extern t_command_line	g_cmdl;

  write(g_cmdl.tty, str, strlen(str));
}

int	ui_modul_str(char param[2])
{
  char	*str_tc;
  char	buf[30];
  char	*ap;

  ap = buf;
  if ((str_tc = tgetstr(param, &ap)) == NULL)
     return (EXIT_FAILURE);
  ui_putstr(str_tc);
  return (EXIT_SUCCESS);
}
