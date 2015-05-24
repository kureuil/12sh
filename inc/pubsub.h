/*
** pubsub.h for corewar in /home/brendan/rendu/CPE_2014_corewar
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Fri Feb 27 06:32:09 2015 Brendan Rius
** Last update Sun May 24 13:50:40 2015 Adrien Paris
*/

/*
** The pubsub system allows publishers to trigger events and subscribers
** to register to thoses events (via a hook) so they can take actions when
** the event is triggered.
** When an event if triggered, it is triggered on the PUBLISHER'S THREAD,
** so if the subscriber wants to perform long operations, it should use
** create its own process in the hook.
*/
#ifndef PUBSUB_H_
# define PUBSUB_H_

#include <stdlib.h>
#include <sys/types.h>

/*
** Define the maximum number of subscribers the VM can handle
** for every event
*/
# define MAX_SUBSCRIBERS 1024

/*
** Here are the different events that can be thrown
** NOTE: _NB_EVENTS is a special value that store the
** number of events, so IT SHOULD ALWAYS BE AT THE
** END OF THE ENUM.
**/
typedef enum	e_event
  {
    UI_WRITE,
    UI_BACKSPACE,
    UI_DEL,
    UI_INSERT,
    UI_MOVE_LEFT,
    UI_MOVE_RIGHT,
    UI_MOVE_BEGIN,
    UI_MOVE_END,
    UI_JUMP_WORD_LEFT,
    UI_JUMP_WORD_RIGHT,
    UI_SET_SELECT_POS,
    UI_RESET_SELECT_POS,
    UI_CUT,
    UI_CUT_END,
    UI_CUT_BEGIN,
    UI_COPY,
    UI_PASTE,
    UI_SEND_STR,
    UI_EXIT,
    UI_ABORT,
    UI_AUTO_COMPLETION,
    UI_RESEARCH_HISTORY,
    UI_DISP_DEBUG_CMDL,
    UI_DISP_CMDL,
    UI_CLEAR_WIN,
    UI_REC_MACRO,
    UI_PLAY_MACRO,
    _NB_EVENTS
  }		t_event;

/*
** A subscriber is a function taking the publisher that threw the event
** and some additional informations (void *), and returning nothing.
*/
typedef void (*t_subscriber)(enum e_event, void *);

/*
** Define the type for a VM hook (it is basically
** an index in an array, with a special negative value
** -1, see http://stackoverflow.com/questions/19224655/using-ssize-t-vs-int
** for more details).
*/
typedef ssize_t t_vm_hook;

/*
** This function is called to register a hook in the VM for one event.
** It returns the hook id in case of success, -1 otherwise.
*/
t_vm_hook	vm_register_hook(enum e_event pub, t_subscriber sub);

/*
** This function is called to unregister a hook in the VM.
** It takes the id of the hook, and the event from which the hook
** should be removed.
*/
void		vm_unregister_hook(t_event event, t_vm_hook hook_id);

/*
** This function is called to trigger an event. It takes the
** event to trigger and some additional infos
*/
void		vm_trigger_event(t_event event, void *data);

#endif /* !PUBSUB_H_ */
