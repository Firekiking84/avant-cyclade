/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 23/05/2024 16:09:03 ******************************************************
** keryan.houssin <keryan.houssin@jemison.efrits.fr>
** - Queue -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include            "queue.h"

void                *efpop_queue(t_queue            *que)
{
    void            *data;
    t_node	    *tmp;

    if (!que->front)
      return(NULL);
    data = que->front->data;
    tmp = que->front;
    que->nb_node -= 1;
    if (que->nb_node == 0)
      {
	que->front = NULL;
	que->back = NULL;
      }
    else
      que->front = que->front->prev;
    bunny_free(tmp);
    return(data);
}
