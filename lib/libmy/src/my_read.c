/*
** my_read.c for libmy in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Sun Jan 18 18:43:39 2015 Louis Person
** Last update Thu Jan 22 00:04:26 2015 Louis Person
*/

#include <unistd.h>

int	my_read(int fd, char *buffer, int len)
{
  int	count;
  int	tmp;
  
  count = 0;
  while ((tmp = read(fd, buffer + count, len - count)) > 0)
    count += tmp;
  buffer[count] = '\0';
  if (tmp < 0)
    return (tmp);
  return (count);
}

