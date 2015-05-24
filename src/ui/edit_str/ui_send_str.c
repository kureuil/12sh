/*
** ui_send_str.c for 42sh in /home/adrien/Travail/Cprograme/Semestre2/42sh/42sh
** 
** Made by Adrien Paris
** Login   <adrien@epitech.net>
** 
** Started on  Sat May 23 12:45:26 2015 Adrien Paris
** Last update Sun May 24 18:20:06 2015 Adrien Paris
*/

#include <stdlib.h>
#include "ui/edit_cmdl.h"

void			ui_send_str_cmdl(t_event e, void *data)
{
  extern t_command_line	g_cmdl;

  (void) e;
  (void) data;
  if (g_cmdl.size > 0)
    g_cmdl.time++;
  g_cmdl.exit = 1;
}
