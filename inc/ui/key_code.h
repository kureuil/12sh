/*
** key_code.h for termcaps in /home/paris_e/Travail/Cprograme/Semestre2/42sh/Draft
**
** Made by Adrien Paris
** Login   <paris_e@epitech.net>
**
** Started on  Wed Apr 22 18:30:37 2015 Adrien Paris
** Last update Sun May 24 13:53:04 2015 Adrien Paris
*/

#ifndef _KEY_CODE_
# define _KEY_CODE_

/*
** Number of event who are link withe a key
*/
#define NB_EVENT_PER_KEY	24

/*
** Arrow
*/
# define K_LEFT			0x445B1B
# define K_RIGHT		0x435B1B
# define K_UP			0x415B1B
# define K_DOWN			0x425B1B

/*
** Maj Arrow
*/
# define K_M_LEFT		0x44323B315B1B
# define K_M_RIGHT		0x43323B315B1B

/*
** Control Arrow
*/
# define K_CTRL_LEFT		0x44353B315B1B
# define K_CTRL_RIGHT		0x43353B315B1B
# define K_CTRL_UP		0x41353B315B1B
# define K_CTRL_DOWN		0x42353B315B1B

/*
** Control Meta Arrow
*/
# define K_CTRL_M_LEFT		0x44363B315B1B
# define K_CTRL_M_RIGHT		0x43363B315B1B

/*
** Home end
*/
# define K_HOME			0x485B1B
# define K_END			0x465B1B

/*
** Cut Copy Paste
*/
# define K_CTRL_U		0x15
# define K_CTRL_K		0x0B
# define K_CTRL_W		0x17
# define K_CTRL_Y		0x19
# define K_ALT_W		0x771B

/*
** Aurocompletion and research
*/
# define K_CTRL_R		0x12
# define K_TAB			0x09

# define K_DEL			0x7E335B1B
# define K_BACKSPACE		0x7F

# define K_INSERT		0x7E325B1B
# define K_ENTER		0x0A
# define K_CTRL_C		0x03
# define K_CTRL_D		0x04
# define K_CTRL_L		0x0C

/*
** Macro
*/
# define K_F3			0x524F1B
# define K_F4			0x534F1B

#endif /* _KEY_CODE_ */
