/*
** ui.c for termcaps in /home/paris_e/Travail/Cprograme/Semestre2/42sh/V2
** 
** Made by Adrien Paris
** Login   <paris_e@epitech.net>
** 
** Started on  Mon Apr 27 10:04:30 2015 Adrien Paris
** Last update Sun May 24 19:06:21 2015 Adrien Paris
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "pubsub.h"
#include "mathematic.h"
#include "my/dictionnary.h"
#include "ui.h"

/*
** @TESTABLE
*/

char			*ui_termcaps_prompt(t_dict *dict_key)
{
  extern t_command_line	g_cmdl;
  struct termios	save_tc;

  if (ui_init_termcaps(&save_tc) == EXIT_FAILURE)
    {
      ui_end_termcaps(&save_tc);
      return (NULL);
    }
  while (g_cmdl.exit == 0)
    {
      vm_trigger_event(UI_DISP_CMDL, NULL);
      ui_get_event_key(dict_key);
    }
  vm_trigger_event(UI_DISP_CMDL, NULL);
  printf("\n");
  ui_end_termcaps(&save_tc);
  return (g_cmdl.str);
}

int			ui(t_dict *dict_key, char **str)
{
  extern t_command_line	g_cmdl;

  ui_reset_command_line();
  (*str) = NULL;
  ui_disp_prompt();
  if (g_cmdl.emergency == true || dict_key == NULL)
    (*str) = emergency_prompt();
  else
    {
      if (((*str) = ui_termcaps_prompt(dict_key)) == NULL)
	return (EXIT_FAILURE);
      if (((*str) = strdup((*str))) == NULL)
	return (EXIT_FAILURE);
    }
  if (g_cmdl.exit != 1)
    {
      free(*str);
      (*str) = NULL;
    }
  return (EXIT_SUCCESS);
}
