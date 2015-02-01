/*
** my_dputchar.c for libmy in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Mon Nov 17 14:13:33 2014 Louis Person
** Last update Mon Nov 17 14:13:41 2014 Louis Person
*/

#include <unistd.h>

int	my_dputchar(int fd, char c)
{
  return (write(fd, &c, 1));
}
