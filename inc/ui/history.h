/*
** history.h for 42sh in /home/paris_e/Travail/Cprograme/Semestre2/42sh/V2
** 
** Made by Adrien Paris
** Login   <paris_e@epitech.net>
** 
** Started on  Mon May  4 16:38:11 2015 Adrien Paris
** Last update Mon May  4 16:40:34 2015 Adrien Paris
*/

#ifndef _UI_HISTORY_
# define _UI_HISTORY_

# define SIZE_HIST	5

typedef struct          s_history
{
  char                  tab[SIZE_HIST][SIZE_CMDL];
  size_t                current;
  size_t                size;
}			t_history;

#endif	/* _UI_HISTORY_ */
