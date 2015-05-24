/*
** ui_exit_cmdl.c for 42sh in /home/adrien/Travail/Cprograme/Semestre2/42sh/42sh
** 
** Made by Adrien Paris
** Login   <adrien@epitech.net>
** 
** Started on  Fri May 22 08:52:10 2015 Adrien Paris
** Last update Sat May 23 12:44:57 2015 Adrien Paris
*/

#include <stdlib.h>
#include "ui/edit_cmdl.h"

void			ui_exit_cmdl(t_event e, void *data)
{
  extern t_command_line	g_cmdl;

  (void) e;
  (void) data;
  g_cmdl.exit = 2;
}

void			ui_abort_cmdl(t_event e, void *data)
{
  (void) e;
  (void) data;
  ui_reset_command_line();
}
