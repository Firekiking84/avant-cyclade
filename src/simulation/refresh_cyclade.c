#include		"simulation.h"

void			efrefresh_cyclade_simulation(t_simulation	*simulation)
{
  int			i;

  i = 0;
  while (i < simulation->nb_card)
    {
      efrefresh_cyclade(simulation->cyclades[i]);
      i += 1;
    }
}
