/*
** error.h for libmy in /home/person_l
**
** Made by Louis Person
** Login   <person_l@epitech.eu>
**
** Started on  Mon Dec  29 17:22:57 2014 Louis Person
** Last update Sun Feb  1 11:25:39 2015 Louis Person
*/

#ifndef MY_ERROR
# define MY_ERROR

typedef enum	e_error
{
  OK,
  COULD_NOT_MALLOC,
  COULD_NOT_OPEN,
  COULD_NOT_READ,
  NULL_POINTER,
  SYS_ERROR,
  QUIT,
  SUBMIT,
  SIZE_TOO_BIG,
  SIZE_TOO_SMALL,
  NOENT,
  PARSE_ERROR,
  NORIGHT,
  MISM_QUOT,
  MISM_BRAK,
  ERRORS
}		t_error;

#endif /* !MY_ERROR */
