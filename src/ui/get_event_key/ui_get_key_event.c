/*
** get_key_event.c for ui in /home/paris_e/Travail/Cprograme/Semestre2/42sh/V2
** 
** Made by Adrien Paris
** Login   <paris_e@epitech.net>
** 
** Started on  Sun Apr 26 22:31:16 2015 Adrien Paris
** Last update Sun May 24 17:05:45 2015 Adrien Paris
*/

#include <stdlib.h>
#include "my/dictionnary.h"
#include "ui/get_key.h"

int			ui_get_event_key(t_dict *dict_key)
{
  unsigned long		code;

  code = ui_get_keycode();
  ui_pub_event(code, dict_key);

  return (EXIT_SUCCESS);
}
