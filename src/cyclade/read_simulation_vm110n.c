#include		"simulation.h"

#include		<stdio.h>

static void		read_left_simulation_vm110n(t_simulation	*simulation,
						    t_bunny_vm110n	*card,
						    t_bunny_vm110n	*left_card)
{
  bool			*digital_inputs;
  double		*analog_inputs;

  digital_inputs = (bool *)card->digital_inputs;
  analog_inputs = (double *)card->analog_inputs;
  analog_inputs[PI_A_CLOCK] = simulation->clock_state;
  analog_inputs[PI_A_IN1_LEFT] = left_card->digital_outputs[PO_OUT1_RIGHT];
  digital_inputs[PI_IN2_LEFT] = left_card->digital_outputs[PO_OUT2_RIGHT];
  digital_inputs[PI_CHECK_IN_LEFT] = left_card->digital_outputs[PO_CHECK_OUT_RIGHT];
}

static void		read_right_simulation_vm110n(t_bunny_vm110n	*card,
						     t_bunny_vm110n	*right_card)
{
  bool			*digital_inputs;

  digital_inputs = (bool *)card->digital_inputs;
  digital_inputs[PI_IN1_RIGHT] = right_card->digital_outputs[PO_OUT1_LEFT];
  digital_inputs[PI_IN2_RIGHT] = right_card->digital_outputs[PO_OUT2_LEFT];
  digital_inputs[PI_CHECK_IN_RIGHT] = right_card->digital_outputs[PO_CHECK_OUT_LEFT];
}

void			efread_simulation_vm110n(t_bunny_vm110n		*card)
{
  t_simulation		*simulation;
  t_bunny_vm110n	*left_card;
  t_bunny_vm110n	*right_card;

  //  printf("Card %d is reading...\n", card->id);
  simulation = (t_simulation *)card->_private;
  if (card->id == 0)
    left_card = simulation->cyclades[simulation->nb_card - 1]->card;
  else
    left_card = simulation->cyclades[card->id - 1]->card;
  if (card->id == (simulation->nb_card - 1))
    right_card = simulation->cyclades[0]->card;
  else
    right_card = simulation->cyclades[card->id + 1]->card;
  read_left_simulation_vm110n(simulation, card, left_card);
  read_right_simulation_vm110n(card, right_card);
}
