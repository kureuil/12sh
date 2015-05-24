/*
** token_pipe.c for 42sh in /home/brendan/rendu/42sh
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu May 14 20:16:59 2015 Brendan Rius
** Last update Thu May 14 20:17:07 2015 Brendan Rius
*/

#include <assert.h>
#include <check.h>
#include <stdlib.h>
#include <signal.h>
#include "tokenizer/token.h"
#include "tokenizer/tokenizer.h"

START_TEST (test_pipe_null_string)
{
  struct s_token	t;

  assert(token_init(&t) == 0);
  parse_token_pipe(NULL, &t);
}
END_TEST

START_TEST (test_pipe_null_token)
{
  parse_token_pipe("|", NULL);
}
END_TEST

START_TEST (test_pipe)
{
  const char		*s = "|";
  struct s_token	t;

  assert(token_init(&t) == 0);

  ck_assert_int_eq(parse_token_pipe(s, &t), 1);

  ck_assert_str_eq(t.string._string, "|");
  ck_assert_int_eq(t.string.len, 1);
  ck_assert_int_eq(t.type, TT_PIPE);
}
END_TEST

Suite	*token_parser_pipe_suite()
{
  Suite	*s;
  TCase	*tc_assertions;
  TCase	*tc_core;

  s = suite_create("Token parser pipe");

  tc_assertions = tcase_create("Assertions");
  tcase_add_test_raise_signal(tc_assertions, test_pipe_null_string, SIGABRT);
  tcase_add_test_raise_signal(tc_assertions, test_pipe_null_token, SIGABRT);

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_pipe);

  suite_add_tcase(s, tc_core);
  suite_add_tcase(s, tc_assertions);

  return (s);
}
