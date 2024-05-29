#include		"simulation.h"

void			efdelete_simulation(t_simulation	*simulation)
{
  int			i;

  i = 0;
  while (i < simulation->nb_card)
    {
      efclose_cyclade(simulation->cyclades[i]);
      i += 1;
    }
  bunny_free(simulation->cyclades);
  bunny_free(simulation);
}
