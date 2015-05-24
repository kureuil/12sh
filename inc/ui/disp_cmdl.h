/*
** disp_cmdl.c for termcaps in /home/paris_e/Travail/Cprograme/Semestre2/42sh/V2
** 
** Made by Adrien Paris
** Login   <paris_e@epitech.net>
** 
** Started on  Sun Apr 26 17:38:47 2015 Adrien Paris
** Last update Sun May 24 19:33:39 2015 Adrien Paris
*/

#ifndef _DISP_CMDL_
# define _DISP_CMDL_

# include "pubsub.h"

/*
** This function suscribe the display fonction to some event with
** the pubsub mecanic.
*/
int	ui_init_disp_cmdl();

/*
** This function use the function tgestr, so make sure the termcaps
** is available before use it. It took a string of two letter that
** corespond to the termcaps.
*/
int	ui_modul_str(char param[2]);

/*
** Simple putstr, mainly for debug, should probably removed later.
*/
void	ui_putstr(char *str);

/*
** Function used with the pubsub systeme, and initialized with
** init_disp_cmdl() function. it will display the global cmdl struct.
*/
void	ui_debug_disp_cmdl_struct(t_event e, void *data);

/*
** Should be the final version of the display of the command line.
** with all the termcaps etc. But still work in progress.
** it use the pubsub mecanic too, and it initialized by init_disp_cmdl()
** function.
*/
void	ui_disp_cmdl(t_event e, void *data);

int	ui_disp_prompt();

void	ui_init_prompt();

int	ui_get_cursor_line();

void	ui_set_cursor(int x, int y);

void	ui_disp_wo_select();

void	ui_disp_w_select();

void	ui_color_cursor();

void	ui_color_reset();

void	ui_clear_window(t_event e, void *data);

void	ui_init_tty();

#endif	/* _DISP_CMDL_ */
