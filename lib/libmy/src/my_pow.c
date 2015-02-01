/*
** my_power_rec.c for my_power_rec in /home/person_l/rendu/Piscine_C_J05
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Fri Oct  3 09:35:14 2014 Louis Person
** Last update Mon Oct  6 23:25:02 2014 Louis Person
*/

int	my_pow(int nb, int power)
{
  int	res;
  int	c;

  if (power < 0)
    return (0);
  if (power == 0)
    return (1);
  c = 0;
  res = 1;
  while (c < power)
  {
    res *= nb;
    c++;
  }
  return (res);
}
