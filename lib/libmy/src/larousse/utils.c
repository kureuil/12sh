/*
** utils.c for libmy in /home/person_l
**
** Made by Louis Person
** Login   <person_l@epitech.eu>
**
** Started on  Sun Dec  28 23:47:8 2014 Louis Person
** Last update Sun Jan 25 20:25:16 2015 Louis Person
*/

#include <stdlib.h>
#include "my.h"

int	dict_free_tree(t_tree *node, void (*free_fn)(void *))
{
  if (free_fn == NULL)
    return (-1);
  if (node == NULL)
    return (0);
  if (node->left != NULL)
    dict_free_tree(node->left, free_fn);
  free_fn(((t_bucket *)node->data)->data);
  dict_buck_free(node->data);
  if (node->right != NULL)
    dict_free_tree(node->right, free_fn);
  return (0);
}

char		**dict_serialize(t_dict *dict,
				 char *(*serialize_fn)(char *, char *))
{
  t_darray	*storage;
  char		**serialized;
  int		i;

  if ((storage = create_dynamo(NULL)) == NULL)
    return (NULL);
  dict_serialize_bucket(dict->root, storage, serialize_fn);
  if ((serialized = malloc(sizeof(char *) * (dict->size + 1))) == NULL)
    return (NULL);
  i = -1;
  while (++i < dict->size)
    serialized[i] = (char *)(storage->data[i]);
  serialized[i] = NULL;
  return (serialized);
}

void		dict_serialize_bucket(t_tree *node,
				      t_darray *serialized,
				      char *(*serialize_fn)(char *, char *))
{
  t_bucket	*bucket;

  if (node == NULL || serialized == NULL || serialize_fn == NULL)
    return;
  if (node->left != NULL)
    dict_serialize_bucket(node->left, serialized, serialize_fn);
  bucket = (t_bucket *)(node->data);
  serialized->add(serialized, serialize_fn(bucket->key, bucket->data));
  if (node->right != NULL)
    dict_serialize_bucket(node->right, serialized, serialize_fn);
}
