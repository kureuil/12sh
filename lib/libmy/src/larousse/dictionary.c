/*
** dictionary.c for libmy in /home/person_l
**
** Made by Louis Person
** Login   <person_l@epitech.eu>
**
** Started on  Sun Dec  28 15:26:31 2014 Louis Person
** Last update Sun Dec  28 15:26:31 2014 Louis Person
*/

#include <stdlib.h>
#include "my.h"

int	dict_new(t_dict **dict)
{
  if ((*dict = malloc(sizeof(t_dict))) == NULL)
    return (-1);
  if (tree_new(&(*dict)->root) != 0)
    return (-1);
  (*dict)->size = 0;
  return (0);
}

int		dict_set(t_dict *dict, char *key, void *data)
{
  t_bucket	*bucket;
  t_tree	*node;

  if (dict == NULL || key == NULL)
    return (-1);
  if ((node = tree_search(dict->root, &dict_buck_keycmp, key)) != NULL)
    ((t_bucket *)node->data)->data = data;
  else
  {
    if ((bucket = malloc(sizeof(t_bucket))) == NULL)
      return (-1);
    bucket->key = my_strdup(key);
    bucket->data = data;
    if (tree_insert(&(dict->root), bucket, &dict_buckcmp, NULL) != 0)
      return (-1);
    dict->size += 1;
  }
  return (0);
}

void		*dict_search(t_dict *dict, char *key)
{
  t_tree	*query;

  if (dict == NULL || key == NULL)
    return (NULL);
  query = tree_search(dict->root, &dict_buck_keycmp, key);
  if (query == NULL)
    return (NULL);
  return (((t_bucket *)query->data)->data);
}

int		dict_delete(t_dict *dict, char *key, void (*free_fn)(void *))
{
  t_tree	*node;

  if (dict == NULL || key == NULL)
    return (-1);
  node = tree_search(dict->root, &dict_buck_keycmp, key);
  if (node == NULL)
    return (0);
  if (free_fn != NULL)
    free_fn(((t_bucket *)node->data)->data);
  free(((t_bucket *)node->data)->key);
  free(node->data);
  if (tree_delete(node) != 0)
    return (-1);
  dict->size--;
  return (0);
}

int	dict_free(t_dict *dict, void (*free_fn)(void *))
{
  if (dict == NULL || free_fn == NULL)
    return (-1);
  dict_free_tree(dict->root, free_fn);
  if (tree_free(dict->root) != 0)
    return (-1);
  free(dict);
  return (0);
}
