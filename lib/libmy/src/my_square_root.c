/*
** my_square_root.c for my_square_root.c in /home/person_l/rendu/Piscine_C_J05
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Fri Oct  3 10:02:48 2014 Louis Person
** Last update Fri Dec 26 16:52:16 2014 Louis Person
*/

int	my_square_root(int nb)
{
  int	root;

  root = 1;
  while (root * root != nb)
  {
    if (root * root > nb)
      return (0);
    root++;
  }
  return (root);
}
