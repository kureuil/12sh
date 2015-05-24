/*
** special_char_filter.c for 42sh in /home/brendan/rendu/42sh
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Sun May  3 15:10:42 2015 Brendan Rius
** Last update Sun May  3 15:19:20 2015 Brendan Rius
*/

#include <assert.h>
#include "my/my.h"

int	special_char_filter(struct s_string *s)
{
  assert(s != NULL);
  if (string_replace_str(s, "\\\\", "\\") == -1)
    return (-1);
  if (string_replace_str(s, "\\0", "") == -1)
    return (-1);
  if (string_replace_str(s, "\\a", "\a") == -1)
    return (-1);
  if (string_replace_str(s, "\\b", "\b") == -1)
    return (-1);
  if (string_replace_str(s, "\\t", "\t") == -1)
    return (-1);
  if (string_replace_str(s, "\\n", "\n") == -1)
    return (-1);
  if (string_replace_str(s, "\\v", "\v") == -1)
    return (-1);
  if (string_replace_str(s, "\\f", "\f") == -1)
    return (-1);
  if (string_replace_str(s, "\\r", "\r") == -1)
    return (-1);
  return (0);
}
