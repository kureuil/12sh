/*
** mathematique.c for termcaps in /home/paris_e/Travail/Cprograme/Semestre2/42sh/V2
** 
** Made by Adrien Paris
** Login   <paris_e@epitech.net>
** 
** Started on  Mon Apr 27 21:48:14 2015 Adrien Paris
** Last update Wed May 13 09:58:26 2015 Adrien Paris
*/

int	math_abs(int nb)
{
  if (nb > 0)
    return (nb);
  return (-nb);
}

int	math_min(int a, int b)
{
  if (a > b)
    return (b);
  return (a);
}

int	math_max(int a, int b)
{
  if (a > b)
    return (a);
  return (b);
}

int	math_is_neg(int nb)
{
  if (nb < 0)
    return (1);
  return (0);
}
