/*
** my_dputnbr_base.c for libmy in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Mon Nov 17 14:14:10 2014 Louis Person
** Last update Tue Nov 18 11:37:57 2014 Louis Person
*/

#include "my.h"

int	my_dputnbr_base(int fd, int n, char *base)
{
  int	bl;
  int	written;

  bl = my_strlen(base);
  written = 0;
  if (n < 0)
    written += my_putchar('-');
  if (n > (bl - 1) || n < -(bl - 1))
    written += my_dputnbr_base(fd, (n / bl < 0 ? - (n / bl) : n / bl), base);
  return (my_dputchar(fd, base[n % bl < 0 ? - (n % bl) : n % bl]));
}

int	my_dput_ulnbr(int fd, unsigned long n)
{
  int	written;

  written = 0;
  if (n > 9UL)
    written += my_dput_ulnbr(fd, n / 10UL);
  return (my_dputchar(fd, '0' + n % 10UL));
}
