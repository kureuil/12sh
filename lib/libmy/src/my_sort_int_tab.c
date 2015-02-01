/*
** my_sort_int_tab.c for my_sort_int_tab in /home/person_l/rendu/Piscine_C_J09
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Thu Oct  9 18:22:07 2014 Louis Person
** Last update Thu Oct  9 18:22:09 2014 Louis Person
*/

void	my_sort_int_tab(int *tab, int size)
{
  int	cur_pos;
  int	cur_rank;
  int	tmp;

  cur_pos = 1;
  cur_rank = 1;
  while (cur_rank < size)
  {
    while (tab[cur_pos] < tab[cur_pos - 1])
    {
      tmp = tab[cur_pos - 1];
      tab[cur_pos - 1] = tab[cur_pos];
      tab[cur_pos] = tmp;
      cur_pos--;
    }
    cur_rank++;
    cur_pos = cur_rank;
  }
}
