/*
** token_semicolon.c for 42sh in /home/brendan/rendu/42sh
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu May 14 20:17:27 2015 Brendan Rius
** Last update Thu May 14 20:17:38 2015 Brendan Rius
*/

#include <assert.h>
#include <check.h>
#include <stdlib.h>
#include <signal.h>
#include "tokenizer/token.h"
#include "tokenizer/tokenizer.h"

START_TEST (test_semicolon_null_string)
{
  struct s_token	t;

  assert(token_init(&t) == 0);
  parse_token_semicolon(NULL, &t);
}
END_TEST

START_TEST (test_semicolon_null_token)
{
  parse_token_semicolon(";", NULL);
}
END_TEST

START_TEST (test_semicolon)
{
  const char		*s = ";";
  struct s_token	t;

  assert(token_init(&t) == 0);

  ck_assert_int_eq(parse_token_semicolon(s, &t), 1);

  ck_assert_str_eq(t.string._string, ";");
  ck_assert_int_eq(t.string.len, 1);
  ck_assert_int_eq(t.type, TT_SEMICOLON);
}
END_TEST

Suite	*token_parser_semicolon_suite()
{
  Suite	*s;
  TCase	*tc_assertions;
  TCase	*tc_core;

  s = suite_create("Token parser semicolon");

  tc_assertions = tcase_create("Assertions");
  tcase_add_test_raise_signal(tc_assertions, test_semicolon_null_string, SIGABRT);
  tcase_add_test_raise_signal(tc_assertions, test_semicolon_null_token, SIGABRT);

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_semicolon);

  suite_add_tcase(s, tc_core);
  suite_add_tcase(s, tc_assertions);

  return (s);
}
