/*
** utils.c for libmy in /home/person_l
**
** Made by Louis Person
** Login   <person_l@epitech.eu>
**
** Started on  Sun Dec  28 16:34:19 2014 Louis Person
** Last update Sun Dec  28 16:34:19 2014 Louis Person
*/

#include <stdlib.h>
#include "my.h"

t_tree		*tree_find_min(t_tree *root)
{
  t_tree	*min;

  if (root == NULL)
    return (NULL);
  min = root;
  while (min->left != NULL)
    min = min->left;
  return (min);
}

t_tree		*tree_find_max(t_tree *root)
{
  t_tree	*max;

  if (root == NULL)
    return (NULL);
  max = root;
  while (max->right != NULL)
    max = max->right;
  return (max);
}

t_tree	**tree_parent_ptr(t_tree *node)
{
  if (node == NULL || node->parent == NULL)
    return (NULL);
  if (node->parent->left == node)
    return (&(node->parent->left));
  return (&(node->parent->right));
}

int	tree_map(t_tree *node, void (*map_fn)(void *))
{
  if (map_fn == NULL)
    return (-1);
  if (node == NULL)
    return (0);
  if (node->left != NULL)
    tree_map(node->left, map_fn);
  map_fn(node->data);
  if (node->right != NULL)
    tree_map(node->right, map_fn);
  return (0);
}
