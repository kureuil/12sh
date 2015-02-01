#!/bin/sh

if [ -e "tests/tests-$1.c" ]
then
  if [ ! -d "bin" ]
  then
    mkdir bin
  fi
  cc -o "bin/tests-$1" -g -Wall -Wextra -I ./include/ "tests/tests-$1.c" -L ./ -l my
  valgrind --leak-check=full ./bin/tests-$1
else
  echo "Wrong file name. No tests for '$1'."
  exit 1
fi
