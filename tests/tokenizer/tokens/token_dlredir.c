/*
** token_dlredir.c<2> for 42sh in /home/brendan/rendu/42sh/tests/tokenizer/tokens
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu Apr 23 15:55:54 2015 Brendan Rius
** Last update Thu May 14 20:18:27 2015 Brendan Rius
*/

#include <assert.h>
#include <check.h>
#include <stdlib.h>
#include <signal.h>
#include "tokenizer/token.h"
#include "tokenizer/tokenizer.h"

START_TEST (test_dlredir_null_string)
{
  struct s_token	t;

  assert(token_init(&t) == 0);
  parse_token_dlredir(NULL, &t);
}
END_TEST

START_TEST (test_dlredir_null_token)
{
  parse_token_dlredir("<<", NULL);
}
END_TEST

START_TEST (test_dlredir)
{
  const char		*s = "<<";
  struct s_token	t;

  assert(token_init(&t) == 0);

  ck_assert_int_eq(parse_token_dlredir(s, &t), 2);

  ck_assert_str_eq(t.string._string, "<<");
  ck_assert_int_eq(t.string.len, 2);
  ck_assert_int_eq(t.type, TT_DLREDIR);
}
END_TEST

Suite	*token_parser_dlredir_suite()
{
  Suite	*s;
  TCase	*tc_assertions;
  TCase	*tc_core;

  s = suite_create("Token parser dlredir");

  tc_assertions = tcase_create("Assertions");
  tcase_add_test_raise_signal(tc_assertions, test_dlredir_null_string, SIGABRT);
  tcase_add_test_raise_signal(tc_assertions, test_dlredir_null_token, SIGABRT);

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_dlredir);

  suite_add_tcase(s, tc_core);
  suite_add_tcase(s, tc_assertions);

  return (s);
}
