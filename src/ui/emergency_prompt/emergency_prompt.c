/*
** emergency_prompt.c for 42sh in /home/adrien/Travail/Cprograme/Semestre2/42sh/42sh
**
** Made by Adrien Paris
** Login   <adrien@epitech.net>
**
** Started on  Sat May 23 16:52:24 2015 Adrien Paris
** Last update Sun May 24 16:52:52 2015 Adrien Paris
*/

#include <unistd.h>
#include "ui.h"
#include "my/my.h"

char			*emergency_prompt()
{
  extern t_command_line	g_cmdl;
  char		*str;

  write(g_cmdl.tty, ":>", 2);
  str = get_next_line(0);
  g_cmdl.exit = 1;
  return (str);
}
