/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 27/05/2024 18:10:47 ******************************************************
** keryan.houssin <keryan.houssin@terechkova.efrits.fr>
** - Avant-Cyclade -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#ifndef			__SIMULATION_HH__

#define			__SIMULATION_HH__

#include		"cyclade.h"

typedef struct		s_simulation
{
  int			nb_card;
  t_cyclade		**cyclades;
  double		last_clock;
  bool			clock_state;
}			t_simulation;

void		efrun_cyclade_simulation(t_simulation		*simulation,
					 int			loop_duration,
					 int			n_turn);
t_simulation	*efnew_simulation(int				nb_card);
void		efdelete_simulation(t_simulation		*simulation);
void		efrefresh_cyclade_simulation(t_simulation	*simulation);

#endif //	__SIMULATION_HH__
