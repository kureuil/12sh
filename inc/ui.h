/*
** termcaps.h for termcaps in /home/paris_e/Travail/Cprograme/Semestre2/42sh/V2
** 
** Made by Adrien Paris
** Login   <paris_e@epitech.net>
** 
** Started on  Sun Apr 26 17:11:27 2015 Adrien Paris
** Last update Sun May 24 16:30:36 2015 Adrien Paris
*/

#ifndef _TERMCAPS__
# define _TERMCAPS__

# include "ui/disp_cmdl.h"
# include "ui/edit_cmdl.h"
# include "ui/get_key.h"

/*
** YOU HAVE TO USE THIS ONE!!!
** This function will init the dict_key and prepare the termcaps
** It will return an EXIT_FAILURE if the termcaps can't be initialized
** or if you are not in a tty.
*/
int	ui_init(t_dict **dict_key);

/*
** This function must have the dictionary. It will launch the readline
** (or a get next line, if the ui_init failed) and will set the string.
** You have to free the str.
** It return EXIT_FAILURE if it faied
*/
int	ui(t_dict *dict_key, char **str);

/*
** Will free the data struct
*/
void	ui_destroy(t_dict *dict_key);

#endif	/* _TERMCAPS__ */
