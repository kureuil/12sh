/*
** ui_macro_init.c for 42sh in /home/paris_e/Travail/Cprograme/Semestre2/42sh/V2
** 
** Made by Adrien Paris
** Login   <paris_e@epitech.net>
** 
** Started on  Wed May  6 12:11:11 2015 Adrien Paris
** Last update Sat May 23 19:04:59 2015 Adrien Paris
*/

#include <stdbool.h>
#include "pubsub.h"
#include "mathematic.h"
#include "ui/edit_cmdl.h"
#include "ui/macro.h"

static t_macro		g_macro;

void			ui_init_g_macro()
{
  extern t_macro	g_macro;

  g_macro.value = 0;
  g_macro.size = 0;
  g_macro.rec = false;
  g_macro.play = false;
}

int	ui_init_macro_sub()
{
  int	i;
  int	ret;

  ui_init_g_macro();
  i = 0;
  ret = 0;
  while (i < _NB_EVENTS)
    {
      if (i != UI_PLAY_MACRO && i != UI_DISP_CMDL)
	ret += math_is_neg(vm_register_hook(i, &ui_macro_record));
      i++;
    }
  ret += math_is_neg(vm_register_hook(UI_PLAY_MACRO, &ui_macro_play));
  return (-ret);
}

void			ui_macro_play(t_event e, void *data)
{
  extern t_macro	g_macro;
  int			i;

  (void) e;
  (void) data;
  if (g_macro.rec == true)
    g_macro.rec = false;
  else
    {
      g_macro.play = true;
      i = 0;
      while (i < g_macro.size)
	{
	  if (g_macro.tab[i][0] == UI_REC_MACRO)
	    {
	      ui_write_number(g_macro.value);
	      g_macro.value++;
	    }
	  else
	    vm_trigger_event(g_macro.tab[i][0], &(g_macro.tab[i][1]));
	  i++;
	}
      g_macro.play = false;
    }
}

void			ui_macro_record_event(void *data, t_event e)
{
  extern t_macro	g_macro;
  int			*c;

  c = data;
  if (e == UI_WRITE)
    g_macro.tab[g_macro.size][1] = *c;
  else
    g_macro.tab[g_macro.size][1] = '\0';
  g_macro.tab[g_macro.size][0] = e;
  g_macro.size++;
  if (e == UI_REC_MACRO)
    {
      ui_write_number(g_macro.value);
      g_macro.value++;
    }
}

void			ui_macro_record(t_event e, void *data)
{
  extern t_macro	g_macro;

  if (g_macro.play == false && g_macro.size < REC_SIZE)
    {
      if (g_macro.rec == true)
	ui_macro_record_event(data, e);
      else if (e == UI_REC_MACRO)
	{
	  ui_init_g_macro();
	  g_macro.rec = true;
	}
    }
}
