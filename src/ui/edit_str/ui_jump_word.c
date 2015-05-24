/*
** jump_word.c for ui in /home/paris_e/Travail/Cprograme/Semestre2/42sh/V2
** 
** Made by Adrien Paris
** Login   <paris_e@epitech.net>
** 
** Started on  Mon Apr 27 12:32:02 2015 Adrien Paris
** Last update Mon May  4 22:34:23 2015 Adrien Paris
*/

#include "pubsub.h"
#include "ui/edit_cmdl.h"

bool	ui_is_alph_num(char c)
{
  if (c < 'a' || c > 'z')
    if (c < 'A' || c > 'Z')
      if (c < '0' || c > '9')
	return (false);
  return (true);
}

void			ui_jump_word_backward(t_event e, void *data)
{
  extern t_command_line	g_cmdl;

  (void) e;
  (void) data;
  if (g_cmdl.cursor > 0)
    g_cmdl.cursor--;
  while (ui_is_alph_num(g_cmdl.str[g_cmdl.cursor]) == false
	 && g_cmdl.cursor > 0)
    g_cmdl.cursor--;
  while (ui_is_alph_num(g_cmdl.str[g_cmdl.cursor]) == true
	 && g_cmdl.cursor > 0)
    g_cmdl.cursor--;
  if (g_cmdl.cursor != 0)
    g_cmdl.cursor++;
}

void			ui_jump_word_forward(t_event e, void *data)
{
  extern t_command_line	g_cmdl;

  (void) e;
  (void) data;
  if (g_cmdl.cursor < g_cmdl.size)
    g_cmdl.cursor++;
  while (ui_is_alph_num(g_cmdl.str[g_cmdl.cursor]) == false
	 && g_cmdl.cursor < g_cmdl.size)
    g_cmdl.cursor++;
  while (ui_is_alph_num(g_cmdl.str[g_cmdl.cursor]) == true
	 && g_cmdl.cursor < g_cmdl.size)
    g_cmdl.cursor++;
}
