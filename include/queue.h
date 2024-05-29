/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 23/05/2024 15:57:44 ******************************************************
** keryan.houssin <keryan.houssin@jemison.efrits.fr>
** - Queue -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#ifndef		__QUEUE_H__

#define		__QUEUE_H__

#include	<stdlib.h>
#include	<stdbool.h>
#include	<lapin.h>

typedef struct	s_node
{
  void		*data;
  struct s_node	*prev;
}		t_node;

typedef struct	s_queue
{
  t_node	*front;
  t_node	*back;
  int		nb_node;
}		t_queue;

t_queue		*efnew_queue();
void		efdelete_queue(t_queue		*que);
bool		efpush_queue(t_queue		*que,
			     void		*elem);
size_t		efclear_queue(t_queue		*que);
void		*efpop_queue(t_queue		*que);
void		*efpop_back_queue(t_queue	*que);

#endif	//	__QUEUE_H__
