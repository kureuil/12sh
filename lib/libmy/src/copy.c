/*
** copy.c for libmy in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Sat Jan 31 10:12:51 2015 Louis Person
** Last update Sat Jan 31 10:13:08 2015 Louis Person
*/

#include <unistd.h>
#include "my.h"

int	copy(int src, int dest)
{
  int	readb;
  char	buffer[4096];
  int	written;
  
  written = 0;
  while ((readb = my_read(src, buffer, 4096)))
    written += write(dest, buffer, readb);
  return (written);
}
