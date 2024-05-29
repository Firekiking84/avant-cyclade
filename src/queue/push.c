/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 23/05/2024 15:52:46 ******************************************************
** keryan.houssin <keryan.houssin@jemison.efrits.fr>
** - Queue -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include        "queue.h"

bool            efpush_queue(t_queue        *que,
                             void           *elem)
{
  t_node	*new_node;

  new_node = bunny_malloc(sizeof(t_node));
  if (!new_node)
    return(false);
  new_node->data = elem;
  new_node->prev = NULL;
  if (!que->back)
    {
      que->back = new_node;
      que->front = new_node;
    }
  else
    {
      que->back->prev = new_node;
      que->back = new_node;
    }
  que->nb_node += 1;
  return(true);
}
