/*
** token_command.c for 42sh in /home/brendan/rendu/42sh/tests/tokenizer/tokens
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu Apr 23 15:59:28 2015 Brendan Rius
** Last update Sun May 24 18:23:41 2015 Antoine Ouvrans
*/

#include <assert.h>
#include <check.h>
#include <stdlib.h>
#include <signal.h>
#include "tokenizer/token.h"
#include "tokenizer/tokenizer.h"
#include "tests/mocks.h"

START_TEST (test_string_null_string)
{
  struct s_token	t;

  assert(token_init(&t) == 0);
  parse_token_string(NULL, &t);
}
END_TEST

START_TEST (test_string_null_token)
{
  parse_token_string("ech54-o__34", NULL);
}
END_TEST

START_TEST (test_string_empty)
{
  struct s_token	t;

  assert(token_init(&t) == 0);
  ck_assert_int_eq(parse_token_string("", &t), 0);
}
END_TEST

START_TEST (test_string)
{
  const char		*s = "ech54-o__34";
  struct s_token	t;

  assert(token_init(&t) == 0);

  ck_assert_int_eq(parse_token_string(s, &t), 11);
  ck_assert_str_eq(t.string._string, "ech54-o__34");
  ck_assert_int_eq(t.string.len, 11);
  ck_assert_int_eq(t.type, TT_STRING);
}
END_TEST

START_TEST (test_string_dquote)
{
  const char		*s = "\"hello\"";
  struct s_token	t;

  assert(token_init(&t) == 0);
  ck_assert_int_eq(parse_token_string(s, &t), 7);
  ck_assert_str_eq(t.string._string, "hello");
  ck_assert_int_eq(t.string.len, 5);
  ck_assert_int_eq(t.type, TT_STRING);
}
END_TEST

START_TEST (test_string_error_dquote)
{
  const char            *s = "\"hello\"world\"";
  struct s_token        t;

  assert(token_init(&t) == 0);

  ck_assert_int_eq(parse_token_string(s, &t), -1);
}
END_TEST

START_TEST (test_string_error_squote)
{
  const char            *s = "\'hello\'world\'";
  struct s_token        t;

  assert(token_init(&t) == 0);

  ck_assert_int_eq(parse_token_string(s, &t), -1);
}
END_TEST

START_TEST (test_string_easy)
{
  const char            *s = "hello world";
  struct s_token        t;

  assert(token_init(&t) == 0);
  ck_assert_int_eq(parse_token_string(s, &t), 5);
  ck_assert_str_eq(t.string._string, "hello");
  ck_assert_int_eq(t.string.len, 5);
  ck_assert_int_eq(t.type, TT_STRING);
}
END_TEST

START_TEST (test_string_space)
{
  const char            *s = "     hello world";
  struct s_token        t;

  assert(token_init(&t) == 0);
  ck_assert_int_eq(parse_token_string(s, &t), 0);
  ck_assert_str_eq(t.string._string, "");
  ck_assert_int_eq(t.string.len, 0);
  ck_assert_int_eq(t.type, TT_STRING);
}
END_TEST

START_TEST (test_string_tab)
{
  const char            *s = "\t\thello world";
  struct s_token        t;

  assert(token_init(&t) == 0);
  ck_assert_int_eq(parse_token_string(s, &t), 0);
  ck_assert_str_eq(t.string._string, "");
  ck_assert_int_eq(t.string.len, 0);
  ck_assert_int_eq(t.type, TT_STRING);
}
END_TEST

START_TEST (test_string_dqcat)
{
  const char            *s = "he\"llo worl\"d";
  struct s_token        t;

  assert(token_init(&t) == 0);
  ck_assert_int_eq(parse_token_string(s, &t), 13);
  ck_assert_str_eq(t.string._string, "hello world");
  ck_assert_int_eq(t.string.len, 11);
  ck_assert_int_eq(t.type, TT_STRING);
}
END_TEST

START_TEST (test_string_sqcat)
{
  const char            *s = "'he'llo worl'd'";
  struct s_token        t;

  assert(token_init(&t) == 0);
  ck_assert_int_eq(parse_token_string(s, &t), 7);
  ck_assert_str_eq(t.string._string, "hello");
  ck_assert_int_eq(t.string.len, 5);
  ck_assert_int_eq(t.type, TT_STRING);
}
END_TEST

START_TEST (test_string_dqception)
{
  const char            *s = "\"he\"llo worl\"d\"";
  struct s_token        t;

  assert(token_init(&t) == 0);
  ck_assert_int_eq(parse_token_string(s, &t), 7);
  ck_assert_str_eq(t.string._string, "hello");
  ck_assert_int_eq(t.string.len, 5);
  ck_assert_int_eq(t.type, TT_STRING);
}
END_TEST

START_TEST (test_string_esaysq)
{
  const char            *s = "Hello' 'World";
  struct s_token        t;

  assert(token_init(&t) == 0);
  ck_assert_int_eq(parse_token_string(s, &t), 13);
  ck_assert_str_eq(t.string._string, "Hello World");
  ck_assert_int_eq(t.string.len, 11);
  ck_assert_int_eq(t.type, TT_STRING);
}
END_TEST

START_TEST (test_string_esaydq)
{
  const char            *s = "Hello\" \"World";
  struct s_token        t;

  assert(token_init(&t) == 0);
  ck_assert_int_eq(parse_token_string(s, &t), 13);
  ck_assert_str_eq(t.string._string, "Hello World");
  ck_assert_int_eq(t.string.len, 11);
  ck_assert_int_eq(t.type, TT_STRING);
}
END_TEST

START_TEST (test_string_sqindq)
{
  const char            *s = "\"Hello' 'World\"";
  struct s_token        t;

  assert(token_init(&t) == 0);
  ck_assert_int_eq(parse_token_string(s, &t), 15);
  ck_assert_str_eq(t.string._string, "Hello' 'World");
  ck_assert_int_eq(t.string.len, 13);
  ck_assert_int_eq(t.type, TT_STRING);
}
END_TEST

START_TEST (test_string_bsinstr)
{
  const char            *s = "\"Hello\\' \\'World\"";
  struct s_token        t;

  assert(token_init(&t) == 0);
  ck_assert_int_eq(parse_token_string(s, &t), 17);
  ck_assert_str_eq(t.string._string, "Hello\\' \\'World");
  ck_assert_int_eq(t.string.len, 15);
  ck_assert_int_eq(t.type, TT_STRING);
}
END_TEST

START_TEST (test_string_bsinstr2)
{
  const char            *s = "\"He\\llo Wor\\ld\"";
  struct s_token        t;

  assert(token_init(&t) == 0);
  ck_assert_int_eq(parse_token_string(s, &t), 15);
  ck_assert_str_eq(t.string._string, "He\\llo Wor\\ld");
  ck_assert_int_eq(t.string.len, 13);
  ck_assert_int_eq(t.type, TT_STRING);
}
END_TEST

START_TEST (test_string_sqindq2)
{
  const char            *s = "\"Hello\\' \\'World\"";
  struct s_token        t;

  assert(token_init(&t) == 0);
  ck_assert_int_eq(parse_token_string(s, &t), 17);
  ck_assert_str_eq(t.string._string, "Hello\\' \\'World");
  ck_assert_int_eq(t.string.len, 15);
  ck_assert_int_eq(t.type, TT_STRING);
}
END_TEST

START_TEST (test_string_sqindq3)
{
  const char            *s = "He\"llo\"\\'worl'd";
  struct s_token        t;

  assert(token_init(&t) == 0);
  ck_assert_int_eq(parse_token_string(s, &t), 15);
  ck_assert_str_eq(t.string._string, "Hello\\world");
  ck_assert_int_eq(t.string.len, 11);
  ck_assert_int_eq(t.type, TT_STRING);
}
END_TEST

START_TEST (test_string_error1)
{
  const char            *s = "\"Hello world\"\"";
  struct s_token        t;

  assert(token_init(&t) == 0);
  ck_assert_int_eq(parse_token_string(s, &t), -1);
}
END_TEST

START_TEST (test_string_error2)
{
  const char            *s = "\'Hello world\'\'";
  struct s_token        t;

  assert(token_init(&t) == 0);
  ck_assert_int_eq(parse_token_string(s, &t), -1);
}
END_TEST

START_TEST (test_string_sq3w)
{
  const char            *s = "\"Hello\\' \\'World\\' \\'FDP\"";
  struct s_token        t;

  assert(token_init(&t) == 0);
  ck_assert_int_eq(parse_token_string(s, &t), 25);
  ck_assert_str_eq(t.string._string, "Hello\\' \\'World\\' \\'FDP");
  ck_assert_int_eq(t.string.len, 23);
  ck_assert_int_eq(t.type, TT_STRING);
}
END_TEST

START_TEST (test_string_dq3w)
{
  const char            *s = "\'Hello\\' \\'World\\' \\'FDP\'";
  struct s_token        t;

  assert(token_init(&t) == 0);
  ck_assert_int_eq(parse_token_string(s, &t), 25);
  ck_assert_str_eq(t.string._string, "Hello\' \'World' \'FDP");
  ck_assert_int_eq(t.string.len, 19);
  ck_assert_int_eq(t.type, TT_STRING);
}
END_TEST

START_TEST (test_string_mult)
{
  const char            *s = "\"lol\" && \"hello\"";
  struct s_token        t;

  assert(token_init(&t) == 0);
  ck_assert_int_eq(parse_token_string(s, &t), 5);
  ck_assert_str_eq(t.string._string, "lol");
  ck_assert_int_eq(t.string.len, 3);
  ck_assert_int_eq(t.type, TT_STRING);
}
END_TEST

START_TEST (test_string_semicol)
{
  const char            *s = "yes';'echo lol";
  struct s_token        t;

  assert(token_init(&t) == 0);
  ck_assert_int_eq(parse_token_string(s, &t), 10);
  ck_assert_str_eq(t.string._string, "yes;echo");
  ck_assert_int_eq(t.string.len, 8);
  ck_assert_int_eq(t.type, TT_STRING);
}
END_TEST

START_TEST (test_string_pipe)
{
  const char            *s = "yes'|'echo lol";
  struct s_token        t;

  assert(token_init(&t) == 0);
  ck_assert_int_eq(parse_token_string(s, &t), 10);
  ck_assert_str_eq(t.string._string, "yes|echo");
  ck_assert_int_eq(t.string.len, 8);
  ck_assert_int_eq(t.type, TT_STRING);
}
END_TEST

START_TEST (test_string_redirl)
{
  const char            *s = "yes'<'echo lol";
  struct s_token        t;

  assert(token_init(&t) == 0);
  ck_assert_int_eq(parse_token_string(s, &t), 10);
  ck_assert_str_eq(t.string._string, "yes<echo");
  ck_assert_int_eq(t.string.len, 8);
  ck_assert_int_eq(t.type, TT_STRING);
}
END_TEST

START_TEST (test_string_redirr)
{
  const char            *s = "yes'>'echo lol";
  struct s_token        t;

  assert(token_init(&t) == 0);
  ck_assert_int_eq(parse_token_string(s, &t), 10);
  ck_assert_str_eq(t.string._string, "yes>echo");
  ck_assert_int_eq(t.string.len, 8);
  ck_assert_int_eq(t.type, TT_STRING);
}
END_TEST

START_TEST (test_string_and)
{
  const char            *s = "yes'&&'echo lol";
  struct s_token        t;

  assert(token_init(&t) == 0);
  ck_assert_int_eq(parse_token_string(s, &t), 11);
  ck_assert_str_eq(t.string._string, "yes&&echo");
  ck_assert_int_eq(t.string.len, 9);
  ck_assert_int_eq(t.type, TT_STRING);
}
END_TEST

Suite	*token_parser_string_suite()
{
  Suite	*s;
  TCase	*tc_assertions;
  TCase	*tc_core;

  s = suite_create("Token parser string");

  tc_assertions = tcase_create("Assertions");
  tcase_add_test_raise_signal(tc_assertions, test_string_null_string, SIGABRT);
  tcase_add_test_raise_signal(tc_assertions, test_string_null_token, SIGABRT);

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_string);
  tcase_add_test(tc_core, test_string_empty);
  tcase_add_test(tc_core, test_string_dquote);
  tcase_add_test(tc_core, test_string_error_dquote);
  tcase_add_test(tc_core, test_string_error_squote);
  tcase_add_test(tc_core, test_string_easy);
  tcase_add_test(tc_core, test_string_space);
  tcase_add_test(tc_core, test_string_tab);
  tcase_add_test(tc_core, test_string_dqcat);
  tcase_add_test(tc_core, test_string_sqcat);
  tcase_add_test(tc_core, test_string_dqception);
  tcase_add_test(tc_core, test_string_esaysq);
  tcase_add_test(tc_core, test_string_esaydq);
  tcase_add_test(tc_core, test_string_sqindq);
  tcase_add_test(tc_core, test_string_bsinstr);
  tcase_add_test(tc_core, test_string_bsinstr2);
  tcase_add_test(tc_core, test_string_sqindq2);
  tcase_add_test(tc_core, test_string_sqindq3);
  tcase_add_test(tc_core, test_string_error1);
  tcase_add_test(tc_core, test_string_error2);
  tcase_add_test(tc_core, test_string_sq3w);
  tcase_add_test(tc_core, test_string_dq3w);
  tcase_add_test(tc_core, test_string_mult);
  tcase_add_test(tc_core, test_string_semicol);
  tcase_add_test(tc_core, test_string_and);
  tcase_add_test(tc_core, test_string_pipe);
  tcase_add_test(tc_core, test_string_redirr);
  tcase_add_test(tc_core, test_string_redirl);

  suite_add_tcase(s, tc_core);
  suite_add_tcase(s, tc_assertions);
  return (s);
}
