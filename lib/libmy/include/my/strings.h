/*
** culotte.h for my in /home/person_l/projets/libmy/include
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Fri Nov 14 14:32:12 2014 Louis Person
** Last update Sat Jan 17 16:00:38 2015 Louis Person
*/

#ifndef MY_STRINGS_H_
# define MY_STRINGS_H_

int	my_putstr(const char *);
int	my_puterr(const char *);
char	*my_revstr(char *);
int	my_char_isprintable(const char);
int	my_showstr(const char *);
char	*my_strcapitalize(char *);
char	*my_strcat(char *, const char *);
int	my_strcmp(const char *, const char *);
char	*my_strcpy(char *, const char *);
int	my_str_isalpha(const char *);
int	my_str_islower(const char *);
int	my_str_isnum(const char *);
int	my_str_isprintable(const char *);
int	my_str_isupper(const char *);
int	my_strlen(const char *);
char	*my_strlowcase(char *);
char	*my_strncat(char *, const char *, int);
int	my_strncmp(const char *, const char *, int);
char	*my_strncpy(char *, const char *, int);
char	*my_strstr(char *, char *);
char	*my_strupcase(char *);
char	*my_strdup(const char *);
char	*my_str_trim(const char *);
int	my_strcount(char *, char *);
int	my_char_iswordsep(const char);
char	*my_strndup(const char *, int n);
char	*my_strsep(char **, const char *);
char	**my_strsplit(char *, char *);

#endif /* !MY_STRINGS_H_ */
