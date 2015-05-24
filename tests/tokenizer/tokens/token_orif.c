/*
** token_orif.c for 42sh in /home/brendan/rendu/42sh
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu May 14 20:16:43 2015 Brendan Rius
** Last update Thu May 14 20:16:53 2015 Brendan Rius
*/

#include <assert.h>
#include <check.h>
#include <stdlib.h>
#include <signal.h>
#include "tokenizer/token.h"
#include "tokenizer/tokenizer.h"

START_TEST (test_orif_null_string)
{
  struct s_token	t;

  assert(token_init(&t) == 0);
  parse_token_orif(NULL, &t);
}
END_TEST

START_TEST (test_orif_null_token)
{
  parse_token_orif("||", NULL);
}
END_TEST

START_TEST (test_orif)
{
  const char		*s = "||";
  struct s_token	t;

  assert(token_init(&t) == 0);

  ck_assert_int_eq(parse_token_orif(s, &t), 2);

  ck_assert_str_eq(t.string._string, "||");
  ck_assert_int_eq(t.string.len, 2);
  ck_assert_int_eq(t.type, TT_ORIF);
}
END_TEST

Suite	*token_parser_orif_suite()
{
  Suite	*s;
  TCase	*tc_assertions;
  TCase	*tc_core;

  s = suite_create("Token parser orif");

  tc_assertions = tcase_create("Assertions");
  tcase_add_test_raise_signal(tc_assertions, test_orif_null_string, SIGABRT);
  tcase_add_test_raise_signal(tc_assertions, test_orif_null_token, SIGABRT);

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_orif);

  suite_add_tcase(s, tc_core);
  suite_add_tcase(s, tc_assertions);

  return (s);
}
