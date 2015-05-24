/*
** switch_inser_mod.c for ui in /home/paris_e/Travail/Cprograme/Semestre2/42sh/V2
** 
** Made by Adrien Paris
** Login   <paris_e@epitech.net>
** 
** Started on  Mon Apr 27 20:46:55 2015 Adrien Paris
** Last update Mon May  4 22:36:48 2015 Adrien Paris
*/

#include <stdlib.h>
#include "pubsub.h"
#include "ui/edit_cmdl.h"

void			ui_switch_insert_mod(t_event e, void *data)
{
  extern t_command_line	g_cmdl;

  (void) e;
  (void) data;
  g_cmdl.insert_mod = !(g_cmdl.insert_mod);
}
