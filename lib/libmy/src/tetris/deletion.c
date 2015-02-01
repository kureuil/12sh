/*
** deletion.c for libmy in /home/person_l
**
** Made by Louis Person
** Login   <person_l@epitech.eu>
**
** Started on  Sun Dec  28 16:30:7 2014 Louis Person
** Last update Sun Dec  28 16:30:7 2014 Louis Person
*/

#include <stdlib.h>
#include "my.h"

int	tree_delete(t_tree *node)
{
  if (node == NULL)
    return (-1);
  if (node->left == NULL && node->right == NULL)
  {
    return (tree_delete_leaf(node));
  }
  else if (node->left == NULL)
  {
    return (tree_delete_unary(node, 'r'));
  }
  else if (node->right == NULL)
  {
    return (tree_delete_unary(node, 'l'));
  }
  else
  {
    return (tree_delete_parent(node));
  }
}

int		tree_delete_leaf(t_tree *node)
{
  t_tree	**ptr;

  if (node == NULL)
    return (-1);
  ptr = tree_parent_ptr(node);
  if (ptr != NULL)
    *ptr = NULL;
  free(node);
  return (0);
}

int		tree_delete_unary(t_tree *node, char side)
{
  t_tree	*child;
  t_tree	**ptr;

  if (node == NULL)
    return (-1);
  if (side == 'r')
    child = node->right;
  else
    child = node->left;
  ptr = tree_parent_ptr(node);
  *ptr = child;
  child->parent = *ptr;
  free(node);
  return (0);
}

int		tree_delete_parent(t_tree *node)
{
  t_tree	*min;
  t_tree	**ptr;

  if (node == NULL || node->left == NULL || node->right == NULL)
    return (-1);
  if ((min = tree_find_min(node->right)) == NULL)
    return (-1);
  ptr = tree_parent_ptr(min);
  if (min->right != NULL)
  {
    min->right->parent = *ptr;
    *ptr = min->right;
  }
  min->parent = node->parent;
  min->left = node->left;
  min->right = node->right;
  node->right->parent = min;
  node->left->parent = min;
  if (node->parent != NULL)
  {
    ptr = tree_parent_ptr(node);
    *ptr = min;
  }
  free(node);
  return (0);
}
