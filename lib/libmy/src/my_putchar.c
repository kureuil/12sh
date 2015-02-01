/*
** my_putchar.c for my_putchar in /home/person_l/rendu/Piscine_C_J03
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Wed Oct  1 09:14:03 2014 Louis Person
** Last update Mon Nov 17 14:23:15 2014 Louis Person
*/

#include <unistd.h>

int	my_putchar(char c)
{
  return (write(1, &c, 1));
}
