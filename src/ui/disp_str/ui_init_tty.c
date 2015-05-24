/*
** ui_init_tty.c for 42sh in /home/adrien/Travail/Cprograme/Semestre2/42sh/42sh
** 
** Made by Adrien Paris
** Login   <adrien@epitech.net>
** 
** Started on  Sun May 24 14:46:46 2015 Adrien Paris
** Last update Sun May 24 15:04:35 2015 Adrien Paris
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "ui/edit_cmdl.h"

void			ui_init_tty()
{
  extern t_command_line	g_cmdl;
  int			fd;

  if ((fd = open("/dev/tty", O_WRONLY)) != -1)
    g_cmdl.tty = fd;
  else
    g_cmdl.tty = 1;
}
