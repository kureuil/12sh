/*
** macro.h for termcaps in /home/paris_e/Travail/Cprograme/Semestre2/42sh/V2
** 
** Made by Adrien Paris
** Login   <paris_e@epitech.net>
** 
** Started on  Wed Apr 29 13:20:02 2015 Adrien Paris
** Last update Fri May 22 19:34:53 2015 Adrien Paris
*/

#ifndef _MACRO__
# define _MACRO__

# define REC_SIZE	1000

typedef struct	s_macro
{
  int		tab[REC_SIZE][2];
  int		size;
  int		value;
  bool		rec;
  bool		play;
}		t_macro;

/*
** This function will associate all the evenement to the
** 'ui_macro_record' function, so it can record all the event.
** it will also associate the 'ui_macro_play' function to
** the 'UI_PLAY_MACOR' event.
** I forget to say it will init the global 'g_macro'.
** Actually it will call the 'ui_init_g_macro' function.
*/
int	ui_init_macro_sub();

/*
** It will just initialized the global 'g_global'
*/
void	ui_init_g_macro();

/*
** This function is like a spy. When an event is publish, it
** will record him. But it's a nice spy, because it will record
** only when the 'UI_REC_MACRO' event is call, and stop to record when
** the 'UI_PLAY_MACRO' event is publish (using the 'ui_macro_play' function).
** If you send an other 'UI_RECORD_PLAY'
*/
void	ui_macro_record(t_event e, void *data);

/*
**
*/
void	ui_macro_play(t_event e, void *data);

#endif	/* _MACRO__ */
