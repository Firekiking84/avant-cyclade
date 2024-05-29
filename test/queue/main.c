/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 23/05/2024 16:55:24 ******************************************************
** keryan.houssin <keryan.houssin@jemison.efrits.fr>
** - Queue -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"queue.h"

#include		<assert.h>

int			main(void)
{
  t_queue		*queue;
  int			values[100];
  int			i;

  queue = efqueue_new();
  i = 0;
  while (i < 100)
    {
      values[i] = i;
      i += 1;
    }
  i = 0;
  while (i < 100)
    {
      efqueue_push(queue, &values[i]);
      i += 1;
    }
  assert(queue->nb_node == 100);
  i = 0;
  while (i < 100)
    {
      assert(*((int *)efqueue_pop(queue)) == values[i]);
      i += 1;
    }
  assert(queue->nb_node == 0);
  i = 0;
  while (i < 100)
    {
      efqueue_push(queue, &values[i]);
      i += 1;
    }
  assert(queue->nb_node == 100);
  i -= 1;
  while (i >= 0)
    {
      assert(*((int *)efqueue_pop_back(queue))== values[i]);
      i -= 1;
    }
  assert(queue->nb_node == 0);
  i = 0;
  while (i < 100)
    {
      efqueue_push(queue, &values[i]);
      i += 1;
    }
  assert(efqueue_clear(queue) == 100);
  efqueue_delete(queue);
}
