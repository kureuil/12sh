/*
** token_command.c for 42sh in /home/brendan/rendu/42sh/tests/tokenizer/tokens
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu Apr 23 15:59:28 2015 Brendan Rius
** Last update Sun May 24 19:49:22 2015 Antoine Ouvrans
*/

#include <assert.h>
#include <check.h>
#include <stdlib.h>
#include <signal.h>
#include "env/env.h"
#include "expand.h"
#include "my/my.h"
#include "tokenizer/token.h"
#include "tokenizer/tokenizer.h"
#include "tests/mocks.h"

START_TEST (simple_expand)
{
  const char            *s = "Bonjour, je suis $USER";
  struct s_string       string;
  size_t		retval;

  setenv("USER", "segpa_m", 1);
  init_env();
  string_init(&string);
  retval = expand(s + 17, &string);
  ck_assert_int_eq(retval, 5);
  ck_assert_str_eq(string._string, "segpa_m");
  unsetenv("USER");
}
END_TEST

START_TEST (simple_expand2)
{
  const char            *s = "Bonjour, je suis $PATH";
  struct s_string       string;
  size_t                retval;

  setenv("PATH", "/home/segpa_m/bin", 1);
  init_env();
  string_init(&string);
  retval = expand(s + 17, &string);
  ck_assert_int_eq(retval, 5);
  ck_assert_str_eq(string._string, "/home/segpa_m/bin");
  unsetenv("PATH");
}
END_TEST

START_TEST (simple_expand3)
{
  const char            *s = "Bonjour, je suis $PWD";
  struct s_string       string;
  size_t                retval;

  setenv("PWD", "/home/segpa_m/photos_famille/mamie/porno", 1);
  init_env();
  string_init(&string);
  retval = expand(s + 17, &string);
  ck_assert_int_eq(retval, 4);
  ck_assert_str_eq(string._string, "/home/segpa_m/photos_famille/mamie/porno");
  unsetenv("PWD");
}
END_TEST

START_TEST (simple_tilde)
{
  const char            *s = "Bonjour, je suis ~";
  struct s_string       string;
  size_t                retval;

  setenv("HOME", "/home/segpa_m", 1);
  init_env();
  string_init(&string);
  retval = tilde(s + 17, &string);
  ck_assert_int_eq(retval, 1);
  ck_assert_str_eq(string._string, "/home/segpa_m");
  unsetenv("HOME");
}
END_TEST

Suite	*expand_suite()
{
  Suite	*s;
  TCase	*tc_assertions;
  TCase	*tc_core;

  s = suite_create("Token parser string");

  tc_assertions = tcase_create("Assertions");

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, simple_expand);
  tcase_add_test(tc_core, simple_expand2);
  tcase_add_test(tc_core, simple_expand3);
  tcase_add_test(tc_core, simple_tilde);

  suite_add_tcase(s, tc_core);
  suite_add_tcase(s, tc_assertions);
  return (s);
}
