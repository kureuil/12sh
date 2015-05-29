/*
** ui_disp_prompt.c for 42sh in /home/adrien/Travail/Cprograme/Semestre2/42sh/42sh
** 
** Made by Adrien Paris
** Login   <adrien@epitech.net>
** 
** Started on  Sun May 24 16:31:54 2015 Adrien Paris
** Last update Fri May 29 23:01:21 2015 Louis Person
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <pwd.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "my/my.h"
#include "ui/disp_cmdl.h"
#include "ui/edit_cmdl.h"
#include "shell.h"
#include "env/env.h"

int			ui_prompt_arg(struct s_string *s)
{
  extern t_command_line	g_cmdl;
  struct s_shell	*shell;
  char			nb[11];
  char			*pwd;

  if ((sprintf(nb, "%d", g_cmdl.time)) < 0)
    return (EXIT_FAILURE);
  if ((string_replace_str(s, "\\#", nb)) != 0)
    return (EXIT_FAILURE);
  if ((pwd = getcwd(NULL, 0)) == NULL)
    pwd = strdup("(null)");
  if ((string_replace_str(s, "\\w", pwd)) != 0)
    return (EXIT_FAILURE);
  free(pwd);
  if ((shell = sh_get()) == NULL)
    return (EXIT_FAILURE);
  if ((sprintf(nb, "%d", shell->returnvalue)) < 0)
    return (EXIT_FAILURE);
  if ((string_replace_str(s, "\\$", nb)) != 0)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

char			*ui_convert_prompt(char *prompt)
{
  extern t_command_line	g_cmdl;
  struct s_string	s;
  char			*new;

  if ((string_init_from_bytes(&s, prompt)) != 0)
    return (NULL);
  if ((string_replace_str(&s, "\\[\\e", "\033")) != 0)
    return (NULL);
  if ((string_replace_str(&s, "\\]", "")) != 0)
    return (NULL);
  if ((string_replace_str(&s, "\\h", g_cmdl.hostname)) != 0)
    return (NULL);
  if ((string_replace_str(&s, "\\u", g_cmdl.username)) != 0)
    return (NULL);
  if ((ui_prompt_arg(&s)) == EXIT_FAILURE)
    return (NULL);
  if ((new = strdup(s._string)) == NULL)
    return (NULL);
  if ((string_destroy(&s)) != 0)
    return (NULL);
  return (new);
}

int			ui_disp_prompt()
{
  extern t_command_line	g_cmdl;
  char			*str;

  if (g_cmdl.prompt != NULL)
    {
      if ((str = ui_convert_prompt(g_cmdl.prompt)) == NULL)
      	return (EXIT_FAILURE);
      ui_putstr(str);
      free(str);
      ui_putstr("\n");
    }
  return (EXIT_SUCCESS);
}

int			ui_init_prompt_user()
{
  extern t_command_line	g_cmdl;
  struct passwd		*passwd;
  uid_t			uid;
  char			*str;
  int			fd;

  uid = getuid();
  if ((passwd = getpwuid(uid)) == NULL)
    g_cmdl.username = "(null)";
  else
    g_cmdl.username = passwd->pw_name;
  if ((fd = open("/etc/hostname", O_RDONLY)) == -1)
    g_cmdl.hostname = "(null)";
  else
    if ((str = get_next_line(fd)) == NULL)
      return (EXIT_FAILURE);
    else
      g_cmdl.hostname = str;
  close(fd);
  return (EXIT_SUCCESS);
}

void			ui_init_prompt()
{
  extern t_command_line	g_cmdl;
  char			*str;

  if ((str = my_getenv("PS1")) == NULL)
    str = "\\[\\e[01;31m\\](\\u@\\h)\\[\\e[0m\\]\\[\\e[01;37m\\],"
      "\\[\\e[0m\\]\\[\\e[00;36m\\]\\w\\[\\e[0m\\]\\[\\e[01;37m\\],"
      "\\[\\e[00;33m\\][\\#] \\[\\e[0m\\]\\[\\e[01;32m\\]{\\$}"
      "\\[\\e[0m\\]\\[\\e[00;37m\\] \\[\\e[0m\\]";
  ui_init_prompt_user();
  g_cmdl.prompt = str;
}
