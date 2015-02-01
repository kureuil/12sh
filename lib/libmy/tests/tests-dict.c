/*
** tests-dict.c for libmy in /home/person_l
**
** Made by Louis Person
** Login   <person_l@epitech.eu>
**
** Started on  Sun Dec  28 22:22:46 2014 Louis Person
** Last update Sun Dec  28 22:22:46 2014 Louis Person
*/

#include <stdlib.h>
#include "my.h"

void	test_deletion(t_dict *dict, char *key)
{
  if (dict_delete(dict, key, &free) != 0)
    chalk_red("KO: dict_delete\n");
  else
    chalk_green("OK: dict_delete\n");
}

void	test_retrieval(t_dict *dict, char *key, char *expected)
{
  void	*data;

  data = dict_search(dict, key);
  if (data == NULL || my_strcmp(data, expected) != 0)
  {
    chalk_red("KO: dict_search\n");
    my_putstr("\tExpected '");
    my_putstr(expected);
    my_putstr("' and got '");
    my_putstr(data);
    my_putstr("' instead.\n");
  }
  else
  {
    chalk_green("OK: tree_search\n");
  }
}

void	test_insertion(t_dict *dict, char *key, char *value)
{
  if (dict_set(dict, key, my_strdup(value)) != 0)
    chalk_red("KO: dict_insert\n");
  else
    chalk_green("OK: dict_insert\n");
}

int		main()
{
  t_dict	*map;

  if (dict_new(&map) != 0)
    chalk_red("KO: dict_new\n");
  else
    chalk_green("OK: dict_new\n");
  test_insertion(map, "person_l", "Louis Person");
  test_insertion(map, "rius_b", "Brendan Rius");
  test_insertion(map, "vaugie_g", "Garance Vaugier");
  test_insertion(map, "paris_e", "Adrien Paris");
  test_insertion(map, "ouvran_a", "Antoine Ouvrans");
  test_insertion(map, "thomas_1", "Pierre-Yves Thomas");
  test_insertion(map, "kurta_v", "Vincent Kurta");
  test_retrieval(map, "vaugie_g", "Garance Vaugier");
  test_insertion(map, "thomas_1", "(pi)Y");
  test_retrieval(map, "thomas_1", "(pi)Y");
  test_deletion(map, "kurta_v");
  if (dict_free(map, &free) != 0)
    chalk_red("KO: dict_free\n");
  else
    chalk_green("OK: dict_free\n");
  return (0);
}
