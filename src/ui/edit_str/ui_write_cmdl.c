/*
** write_cmdl.c for ui in /home/paris_e/Travail/Cprograme/Semestre2/42sh/V2
** 
** Made by Adrien Paris
** Login   <paris_e@epitech.net>
** 
** Started on  Sun Apr 26 18:15:09 2015 Adrien Paris
** Last update Mon May  4 22:37:04 2015 Adrien Paris
*/

#include <string.h>
#include "pubsub.h"
#include "ui/edit_cmdl.h"

int	ui_insert_char_to_str(const char c, const int pos, char *str)
{
  int	size;

  size = strlen(str);
  if (size >= SIZE_CMDL - 1)
    return (EXIT_FAILURE);
  str[size + 1] = '\0';
  while (size > pos)
    {
      str[size] = str[size - 1];
      size--;
    }
  str[size] = c;
  return (EXIT_SUCCESS);
}

void				ui_write_cmdl(t_event e, void *data)
{
  extern t_command_line		g_cmdl;
  char				*c;

  (void) e;
  c = data;
  if (g_cmdl.insert_mod == true || g_cmdl.cursor == g_cmdl.size)
    {
      if (ui_insert_char_to_str(*c, g_cmdl.cursor, g_cmdl.str) == EXIT_SUCCESS)
	{
	  g_cmdl.cursor++;
	  g_cmdl.size++;
	}
    }
  else
    {
      g_cmdl.str[g_cmdl.cursor] = *c;
      g_cmdl.cursor++;
    }
}
