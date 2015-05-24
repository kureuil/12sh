/*
** init_termcaps.c for ui in /home/paris_e/Travail/Cprograme/Semestre2/42sh/Draft
** 
** Made by Adrien Paris
** Login   <paris_e@epitech.net>
** 
** Started on  Wed Apr 22 10:52:46 2015 Adrien Paris
** Last update Sun May 24 15:49:44 2015 Adrien Paris
*/

#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include "my/dictionnary.h"
#include "ui/get_key.h"
#include "ui/disp_cmdl.h"

int	ui_end_termcaps(struct termios *save_tc)
{
  ui_modul_str("ve");
  if (ui_set_attr(save_tc) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int	ui_init_termcaps(struct termios *save_tc)
{
  if (tcgetattr(0, save_tc) == -1)
    return (EXIT_FAILURE);
  if ((ui_raw_mode()) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  ui_modul_str("vi");
  return (EXIT_SUCCESS);
}
