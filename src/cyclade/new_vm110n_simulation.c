#include		"cyclade.h"

static void		init_inputs(t_bunny_vm110n	*card)
{
  int			i;
  bool			*digital_inputs;
  double		*analog_inputs;

  digital_inputs = (bool *)card->digital_inputs;
  i = 0;
  while (i < 5)
    {
      digital_inputs[i] = false;
      i += 1;
    }
  analog_inputs = (double *)card->analog_inputs;
  analog_inputs[0] = 0;
  analog_inputs[1] = 0;
}

static void		init_outputs(t_bunny_vm110n	*card)
{
  int			i;

  i = 0;
  while (i < 8)
    {
      card->digital_outputs[i] = false;
      i += 1;
    }
  card->analog_outputs[0] = 0;
  card->analog_outputs[1] = 0;
}

t_bunny_vm110n		*new_vm110n_simulation(int		id,
					       void		*simulation)
{
  t_bunny_vm110n	*card;
  int			*card_id;
  void			**private;

  card = bunny_malloc(sizeof(t_bunny_vm110n));
  if (!card)
    return(NULL);
  private = (void **)&card->_private;
  *private = simulation;
  card_id = (int *)&card->id;
  *card_id = id;
  init_inputs(card);
  init_outputs(card);
  return(card);
}

