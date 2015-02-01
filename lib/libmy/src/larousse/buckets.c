/*
** buckets.c for libmy in /home/person_l
**
** Made by Louis Person
** Login   <person_l@epitech.eu>
**
** Started on  Sun Dec  28 22:32:47 2014 Louis Person
** Last update Sun Dec  28 22:32:47 2014 Louis Person
*/

#include <stdlib.h>
#include "my.h"

int	dict_buckcmp(t_bucket *b1, t_bucket *b2)
{
  return (my_strcmp(b1->key, b2->key));
}

int	dict_buck_keycmp(t_bucket *bucket, char *key)
{
  return (my_strcmp(bucket->key, key));
}

void	dict_buck_free(t_bucket *bucket)
{
  if (bucket == NULL)
    return;
  free(bucket->key);
  free(bucket);
}
