#include		"simulation.h"

#include		<lapin.h>
#include		<stdio.h>
#include		<string.h>

static void		loop(t_simulation				*simulation,
			     int					loop_duration)
{
  double		time;
  double		start;

  start = bunny_get_current_time();
  time = start;
  while (time - start < loop_duration)
    {
      if ((time - simulation->last_clock) > 0.004)
	{
	  simulation->last_clock = time;
	  simulation->clock_state = !simulation->clock_state;
	}
      efrefresh_cyclade_simulation(simulation);
      time = bunny_get_current_time();
    }
}

void			efrun_cyclade_simulation(t_simulation		*simulation,
						 int			loop_duration,
						 int			n_turn)
{
  int			i;
  int			n_card;
  uint32_t		dest_id;
  char			msg[4096];

  i = 0;
  while (i < n_turn)
    {
      if (i > 0)
	{
	  printf("You can now send a message by this format : [n_card] [dest_id] [msg without spaces]\n");
	  scanf("%d %u %s", &n_card, &dest_id, msg);
	  efsend_data_cyclade(simulation->cyclades[n_card], dest_id, msg, strlen(msg));
	  loop(simulation, loop_duration);
	}
      else
	loop(simulation, 10);
      i += 1;
    }
}
