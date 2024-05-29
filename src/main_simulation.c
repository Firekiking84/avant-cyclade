/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 27/05/2024 17:51:45 ******************************************************
** keryan.houssin <keryan.houssin@terechkova.efrits.fr>
** - Avant-Cyclade -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"simulation.h"

int			main(void)
{
  t_simulation		*simulation;

  bunny_set_memory_check(true);
  simulation = efnew_simulation(10);
  efrun_cyclade_simulation(simulation, 12, 2);
  efdelete_simulation(simulation);
}
