/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 23/05/2024 16:25:25 ******************************************************
** keryan.houssin <keryan.houssin@jemison.efrits.fr>
** - Queue -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include        "queue.h"

void            *efpop_back_queue(t_queue	*que)
{
  void		*data;
  t_node	*tmp;

  if (!que->back)
    return(NULL);
  data = que->back->data;
  tmp = que->front;
  if (que->front != que->back)
    {
      while (tmp->prev != que->back)
	tmp = tmp->prev;
      tmp->prev = NULL;
    }
  bunny_free(que->back);
  que->back = tmp;
  que->nb_node -= 1;
  if (que->nb_node == 0)
    {
      que->back = NULL;
      que->front = NULL;
    }
  return(data);
}
