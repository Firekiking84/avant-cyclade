#include		"simulation.h"

static void		*short_return(const char		*err_msg,
				      void			**pointers,
				      int			nb_pointers)
{
  int			i;

  bunny_perror(err_msg);
  i = 0;
  while (i < nb_pointers)
    {
      bunny_free(pointers[i]);
      i += 1;
    }
  return(NULL);
}


static void		*manage_open_cards_error(t_simulation	*simulation,
						 int		nb_success_card)
{
  int			i;
  void			*pointers[2];

  i = 0;
  while (i < nb_success_card)
    {
      efclose_cyclade(simulation->cyclades[i]);
      i += 1;
    }
  pointers[0] = simulation;
  pointers[1] = simulation->cyclades;
  return(short_return("Cannot allocate all cards !", pointers, 2));
}

t_simulation		*efnew_simulation(int			nb_card)
{
  t_simulation		*simulation;
  int			i;

  simulation = bunny_malloc(sizeof(t_simulation));
  if (!simulation)
    return(short_return("Error while allocation of simulation !", NULL, 0));
  simulation->nb_card = nb_card;
  simulation->cyclades = bunny_malloc(sizeof(t_cyclade *) * nb_card);
  if (!simulation->cyclades)
    return(short_return("Error while allocating simulations cards !", (void **)&simulation, 1));
  i = 0;
  while (i < nb_card)
    {
      simulation->cyclades[i] = efopen_cyclade(i, simulation);
      if (!simulation->cyclades[i])
	manage_open_cards_error(simulation, i);
      i += 1;
    }
  return(simulation);
}
