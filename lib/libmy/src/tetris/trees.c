/*
** trees.c for libmy in /home/person_l
**
** Made by Louis Person
** Login   <person_l@epitech.eu>
**
** Started on  Sun Dec  28 16:18:31 2014 Louis Person
** Last update Sun Dec  28 16:18:31 2014 Louis Person
*/

#include <stdlib.h>
#include "my.h"

int	tree_new(t_tree **root)
{
  if ((*root = malloc(sizeof(t_tree))) == NULL)
    return (-1);
  (*root)->data = NULL;
  (*root)->parent = NULL;
  (*root)->left = NULL;
  (*root)->right = NULL;
  return (0);
}

int		tree_insert(t_tree **leaf,
			    void *data,
			    int (*compare_fn)(),
			    t_tree *parent)
{
  t_tree	*tmp;

  if (leaf == NULL || compare_fn == NULL)
    return (-1);
  if (*leaf == NULL)
  {

    if ((tmp = malloc(sizeof(t_tree))) == NULL)
      return (-1);
    tmp->data = data;
    tmp->parent = parent;
    tmp->left = tmp->right = NULL;
    *leaf = tmp;
    return (0);
  }
  else if ((*leaf)->data == NULL)
  {
    (*leaf)->data = data;
    return (0);
  }
  if (compare_fn(data, (*leaf)->data) < 0)
    return (tree_insert(&((*leaf)->left), data, compare_fn, *leaf));
  else
    return (tree_insert(&((*leaf)->right), data, compare_fn, *leaf));
}

t_tree	*tree_search(t_tree *root, int (*compare_fn)(), void *query)
{
  int	cmp;

  if (root == NULL || root->data == NULL || compare_fn == NULL || query == NULL)
    return (NULL);
  cmp = compare_fn(root->data, query);
  if (cmp == 0)
    return (root);
  else if (cmp > 0)
    return (tree_search(root->left, compare_fn, query));
  else
    return (tree_search(root->right, compare_fn, query));
}
