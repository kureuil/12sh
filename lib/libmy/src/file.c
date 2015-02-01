/*
** file.c for fabrish in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Sun Feb  1 13:15:30 2015 Louis Person
** Last update Sun Feb  1 13:16:23 2015 Louis Person
*/

#include <unistd.h>
#include "my.h"

t_error	check_existence(char *filename)
{
  if (access(filename, F_OK) == -1)
    return (NOENT);
  else if (access(filename, X_OK) == -1)
    return (NORIGHT);
  return (OK);
}
