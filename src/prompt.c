/*
** prompt.c for fabrish in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Thu Jan 29 21:46:37 2015 Louis Person
** Last update Fri Jan 30 11:58:50 2015 Louis Person
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "my.h"
#include "shell.h"
#include "prompt.h"

t_conversion	*get_conversions()
{
  t_conversion	*conversions;
  int		i;

  if ((conversions = malloc(128 * sizeof(t_conversion))) == NULL)
    return (NULL);
  i = -1;
  while (++i < 128)
    conversions[i] = NULL;
  conversions['u'] = &prompt_user;
  conversions['r'] = &prompt_return;
  conversions['\\'] = &prompt_backslash;
  return (conversions);
}

void		prompt_print(t_shell *shell)
{
  int		tty;
  int		i;
  t_conversion	*conversions;
  t_conversion	cb;

  if ((tty = open("/dev/tty", O_WRONLY)) == -1)
    return;
  if ((conversions = get_conversions()) == NULL)
    return;
  i = 0;
  while (shell->prompt[i] != '\0')
    {
      if (shell->prompt[i] == '\\')
	{
	  i++;
	  if ((cb = conversions[(unsigned char)shell->prompt[i]]) != NULL)
	    cb(tty, shell);
	}
      else
	my_dputchar(tty, shell->prompt[i]);
      i++;
    }
  free(conversions);
  close(tty);
}
