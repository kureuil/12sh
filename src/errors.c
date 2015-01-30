/*
** errors.c for fabrish in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Thu Jan 29 21:42:41 2015 Louis Person
** Last update Thu Jan 29 21:42:49 2015 Louis Person
*/

#include "my.h"

void	error_no_file(char *filename)
{
  my_puterr("fabrish: ");
  my_puterr(filename);
  my_puterr(": file not found.\n");  
}

void	error_no_right(char *filename)
{
  my_puterr("fabrish: ");
  my_puterr(filename);
  my_puterr(": permission denied.\n");
}
