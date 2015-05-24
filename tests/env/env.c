/*
** env.c for 42sh in /home/brendan/rendu/42sh/tests
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Wed Apr 22 17:02:40 2015 Brendan Rius
** Last update Fri May  1 20:06:42 2015 Brendan Rius
*/

#define _BSD_SOURCE

#include <check.h>
#include <stdlib.h>
#include "env/env.h"
#include "tests/mocks.h"

START_TEST (test_init_env)
{
  ck_assert_int_eq(init_env(), 0);
}
END_TEST

START_TEST (test_init_env_strdup_null)
{
  set_mock_strdup(&my_mock_strdup_null);
  ck_assert_int_ne(init_env(), 0);
  set_mock_strdup(&strdup);
}
END_TEST

START_TEST (test_get_env)
{
  setenv("___HELLO___", "WORLD", 0);
  init_env();
  ck_assert_str_eq(my_getenv("___HELLO___"), "WORLD");
}
END_TEST

START_TEST (test_set_env)
{
  init_env();
  my_setenv("___HELLO___", "WORLD");
  ck_assert_str_eq(my_getenv("___HELLO___"), "WORLD");
}
END_TEST

START_TEST (test_set_env_override)
{
  init_env();
  my_setenv("___HELLO___", "WORLD");
  my_setenv("___HELLO___", "world");
  ck_assert_str_eq(my_getenv("___HELLO___"), "world");
}
END_TEST

START_TEST (test_remove_env)
{
  init_env();
  my_setenv("___HELLO___", "WORLD");
  my_setenv("___HELLO___", NULL);
  ck_assert_ptr_eq(my_getenv("___HELLO___"), NULL);
}
END_TEST

/*
** ===================
** SETUP
** ===================
*/
Suite	*env_suite()
{
  Suite	*s;
  TCase	*tc_core;

  s = suite_create("Environment");

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_init_env);
  tcase_add_test(tc_core, test_init_env_strdup_null);
  tcase_add_test(tc_core, test_get_env);
  tcase_add_test(tc_core, test_set_env);
  tcase_add_test(tc_core, test_set_env_override);
  tcase_add_test(tc_core, test_remove_env);

  suite_add_tcase(s, tc_core);

  return (s);
}
