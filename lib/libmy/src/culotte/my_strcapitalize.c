/*
** my_strcapitalize.c for my_strcapitalize in /home/person_l/rendu/Piscine_C_J06/ex_07
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Mon Oct  6 15:57:20 2014 Louis Person
** Last update Tue Oct  7 15:25:25 2014 Louis Person
*/

#include <stdlib.h>

char	*my_strcapitalize(char *str)
{
  int	c;
  int	prev_char;

  prev_char = ' ';
  c = 0;
  if (str == NULL)
    return (NULL);
  while (str[c] != '\0')
  {
    if (prev_char == ' ' || prev_char == '-' || prev_char == '+')
    {
      if (str[c] >= 'a' && str[c] <= 'z')
        str[c] -= ('a' - 'A');
    }
    else if (str[c] >= 'A' && str[c] <= 'Z')
      str[c] += ('a' - 'A');
    prev_char = str[c];
    c++;
  }
  return (str);
}
