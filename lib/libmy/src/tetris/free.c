/*
** free.c for libmy in /home/person_l
**
** Made by Louis Person
** Login   <person_l@epitech.eu>
**
** Started on  Sun Dec  28 21:55:20 2014 Louis Person
** Last update Sun Dec  28 21:55:20 2014 Louis Person
*/

#include <stdlib.h>
#include "my.h"

int	tree_free(t_tree *node)
{
  return (tree_free_fn(node, free));
}

int	tree_free_fn(t_tree *node, void (*free_fn)(void *))
{
  if (node == NULL)
    return (-1);
  if (node->left != NULL)
    tree_free_fn(node->left, free_fn);
  if (node->right != NULL)
    tree_free_fn(node->right, free_fn);
  free_fn(node);
  return (0);
}

int	tree_free_item(t_tree *node)
{
  return (tree_free_item_fn(node, free));
}

int	tree_free_item_fn(t_tree *node, void (*free_fn)(void *))
{
  if (node == NULL)
    return (-1);
  free_fn(node);
  return (0);
}
