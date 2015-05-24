/*
** token.c for 42sh in /home/brendan/rendu/42sh/tests/tokenizer
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Fri May  1 19:31:10 2015 Brendan Rius
** Last update Fri May  1 20:06:19 2015 Brendan Rius
*/

#include <check.h>
#include <signal.h>
#include <stdlib.h>
#include "tokenizer/token.h"
#include "tests/mocks.h"

/*
** ==============
** START TESTS
** ==============
*/
START_TEST (test_token_new_null_ptr)
{
  token_new(NULL);
}
END_TEST

START_TEST (test_token_free_null_ptr)
{
  token_free(NULL);
}
END_TEST

START_TEST (test_token_new_malloc_fail)
{
  struct s_token	*t;

  set_mock_malloc(&my_mock_malloc_null);
  ck_assert_int_ne(token_new(&t), 0);
  set_mock_malloc(&malloc);
}
END_TEST

START_TEST (test_token_new)
{
  struct s_token	*t;

  ck_assert_int_eq(token_new(&t), 0);
}
END_TEST

/*
** ============
** SETUP
** ============
*/
Suite	*token_suite()
{
  Suite	*s;
  TCase	*tc_assertions;
  TCase	*tc_core;

  s = suite_create("Token");

  tc_assertions = tcase_create("Assertions");
  tcase_add_test_raise_signal(tc_assertions, test_token_new_null_ptr, SIGABRT);
  tcase_add_test_raise_signal(tc_assertions, test_token_free_null_ptr, SIGABRT);

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_token_new_malloc_fail);
  tcase_add_test(tc_core, test_token_new);

  suite_add_tcase(s, tc_assertions);
  suite_add_tcase(s, tc_core);

  return (s);
}
