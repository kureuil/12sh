/*
** inti_disp_cmdl.c for ui in /home/paris_e/Travail/Cprograme/Semestre2/42sh/V2
** 
** Made by Adrien Paris
** Login   <paris_e@epitech.net>
** 
** Started on  Sun Apr 26 22:22:35 2015 Adrien Paris
** Last update Sun May 24 15:02:38 2015 Adrien Paris
*/

#include <stdlib.h>
#include "pubsub.h"
#include "mathematic.h"
#include "ui/disp_cmdl.h"

int	ui_init_disp_cmdl()
{
  int	ret;

  ret = 0;
  ret += math_is_neg(vm_register_hook(UI_DISP_CMDL, &ui_disp_cmdl));
  ret += math_is_neg(vm_register_hook(UI_CLEAR_WIN, &ui_clear_window));
  ui_init_tty();
  return (-ret);
}
