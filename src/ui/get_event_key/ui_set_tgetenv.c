/*
** my_get_env.c for my_select in /home/paris_e/Travail/Cprograme/My_select/Draft
** 
** Made by Adrien Paris
** Login   <paris_e@epitech.net>
** 
** Started on  Sun Jan 11 18:23:07 2015 Adrien Paris
** Last update Sun May 24 22:28:50 2015 Adrien Paris
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <term.h>
#include "env/env.h"

int		ui_set_tgetenv()
{
  char		term_buff[2048];
  char		*str;

  if ((str = my_getenv("TERM")) == NULL)
    return (EXIT_FAILURE);
  if (tgetent(term_buff, str) != 1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
