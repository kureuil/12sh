/*
** tests-bst.c for libmy in /home/person_l
**
** Made by Louis Person
** Login   <person_l@epitech.eu>
**
** Started on  Sun Dec  28 16:49:39 2014 Louis Person
** Last update Sun Dec  28 16:49:39 2014 Louis Person
*/

#include <stdlib.h>
#include "my.h"

void		test_deletion(t_tree *node)
{
  if (tree_delete(node) != 0)
  {
    chalk_red("KO: tree_delete\n");
  }
  else
    chalk_green("OK: tree_delete\n");
}

t_tree		*test_search(t_tree *root, char *query)
{
  t_tree	*result;

  result = tree_search(root, &my_strcmp, query);
  if (result == NULL || my_strcmp(result->data, query) != 0)
  {
    chalk_red("KO: tree_search\n");
    my_putstr("Expected '");
    my_putstr(query);
    my_putstr("' and got '");
    if (result == NULL)
      my_putstr("(NULL)[result]");
    else if (result->data == NULL)
      my_putstr("(NULL)[result->data]");
    else
      my_putstr((char *)(result->data));
    my_putstr("' instead.\n");
  }
  else
    chalk_green("OK: tree_search\n");
  return (result);
}

void	test_insertion(t_tree *root, char *str)
{
  if (tree_insert(&root, str, &my_strcmp, NULL) == 0)
    chalk_green("OK: tree_insert\n");
  else
    chalk_red("KO: tree_insert\n");
}

int		main()
{
  t_tree	*root;
  t_tree	*node;

  if (tree_new(&root) == 0)
    chalk_green("OK: tree_new\n");
  else
    chalk_red("KO: tree_new\n");
  test_insertion(root, "Hello World!");
  test_insertion(root, "How are you?");
  test_insertion(root, "Holy shit.");
  test_insertion(root, "Warlord");
  test_insertion(root, "Tortank");
  test_insertion(root, "Unary");
  test_insertion(root, "Zag");
  node = test_search(root, "How are you?");
  test_deletion(node);
  if (tree_free(root) == 0)
    chalk_green("OK: tree_free\n");
  else
    chalk_red("KO: tree_free\n");
  return (0);
}
