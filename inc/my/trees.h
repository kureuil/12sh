/*
** trees.h for libmy in /home/person_l
**
** Made by Louis Person
** Login   <person_l@epitech.eu>
**
** Started on  Sun Dec  28 15:51:28 2014 Louis Person
** Last update Sun Dec  28 15:51:28 2014 Louis Person
*/

#ifndef MY_TREES_H_
# define MY_TREES_H_

typedef struct	s_tree
{
  void		*data;
  struct s_tree	*parent;
  struct s_tree	*left;
  struct s_tree	*right;
}		t_tree;

int	tree_new(t_tree **);
int	tree_insert(t_tree **, void *, int (*)(), t_tree *);
t_tree	*tree_search(t_tree *, int (*)(), void *);
t_tree	*tree_find_min(t_tree *);
t_tree	*tree_find_max(t_tree *);
t_tree	**tree_parent_ptr(t_tree *);
int	tree_map(t_tree *, void (*)(void *));
int	tree_delete(t_tree *);
int	tree_delete_leaf(t_tree *);
int	tree_delete_unary(t_tree *, char);
int	tree_delete_parent(t_tree *);
int	tree_free(t_tree *);
int	tree_free_fn(t_tree *, void (*)(void *));
int	tree_free_item(t_tree *);
int	tree_free_item_fn(t_tree *, void (*)(void *));

#endif /* !MY_TREES_H_ */
