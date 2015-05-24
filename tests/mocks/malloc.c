/*
** malloc.c for 42sh in /home/brendan/rendu/42sh/tests/mocks
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Fri May  1 20:01:15 2015 Brendan Rius
** Last update Fri May  1 20:03:33 2015 Brendan Rius
*/

#include <stdlib.h>

static void	*(*mock_malloc)(size_t) = &malloc;
static int	nb_till_malloc_fail;

void	*my_mock_malloc(size_t n)
{
  return (mock_malloc(n));
}

void	*my_mock_malloc_null(size_t n)
{
  (void) n;
  return (NULL);
}

void	*my_mock_malloc_nb(size_t n)
{
  if (nb_till_malloc_fail <= 0)
    return (NULL);
  --nb_till_malloc_fail;
  return (malloc(n));
}

void	set_mock_malloc(void *(*f)(size_t))
{
  mock_malloc = f;
}

void	set_malloc_fail_at(int n)
{
  nb_till_malloc_fail = n;
}
