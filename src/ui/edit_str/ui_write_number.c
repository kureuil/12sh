/*
** ui_write_number.c for 42sh in /home/paris_e/Travail/Cprograme/Semestre2/42sh/V2
** 
** Made by Adrien Paris
** Login   <paris_e@epitech.net>
** 
** Started on  Thu May  7 15:36:05 2015 Adrien Paris
** Last update Fri May 22 19:29:26 2015 Adrien Paris
*/

#include "pubsub.h"
#include "mathematic.h"
#include "ui/edit_cmdl.h"

void		ui_write_number(int nb)
{
  char		c;

  if (nb < 0)
    ui_write_cmdl(UI_WRITE, "-");
  if (math_abs(nb / 10) != 0)
    ui_write_number(math_abs(nb / 10));
  c = math_abs(nb % 10) + '0';
  ui_write_cmdl(UI_WRITE, &c);
}
