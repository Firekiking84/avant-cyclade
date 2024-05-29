/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 23/05/2024 18:32:59 ******************************************************
** keryan.houssin <keryan.houssin@jemison.efrits.fr>
** - Avant Cyclade -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"cyclade.h"

#include		<stdlib.h>
#include		<stdio.h>
#include		<time.h>
#include		<fcntl.h>

static void		alternative_id(t_cyclade	*cyclade)
{
  time_t		my_time;

  my_time = time(NULL);
  cyclade->id += efhash_djb2_cyclade(ctime(&my_time));
  printf("New id : %u\n", cyclade->id);
}

static void		short_return(t_cyclade		*cyclade,
				     const char		*err_msg)
{
  perror(err_msg);
  alternative_id(cyclade);
}

static void		set_id(t_cyclade		*cyclade)
{
  int			fd;
  char			content[4096];
  ssize_t		size_read;

  fd = open("user_id.txt", O_RDONLY);
  if (fd == -1)
    {
      system("cat /sys/class/net/*/address > user_id.txt");
      fd = open("user.id.txt", O_RDONLY);
      if (fd == -1)
	return(short_return(cyclade, "Cannot read user_id.txt, set alternative id !"));
    }
  size_read = read(fd, &content, 4095);
  if (size_read == -1)
    return(short_return(cyclade, "Read error, set alternative id !"));
  content[size_read] = '\0';
  cyclade->id += efhash_djb2_cyclade(content);
  printf("New id : %u\n", cyclade->id);
}

t_cyclade		*efopen_cyclade(size_t		id,
					void		*simulation)
{
  t_cyclade		*cyclade;
  int			i;

  cyclade = bunny_malloc(sizeof(t_cyclade));
  if (!cyclade)
    return(NULL);
  if (simulation)
    cyclade->card = new_vm110n_simulation(id, simulation);
  else
    cyclade->card = bunny_new_vm110n(id);
  if (!cyclade->card)
    {
      bunny_free(cyclade);
      return(NULL);
    }
  cyclade->id = id;
  set_id(cyclade);
  cyclade->simulation = (simulation != NULL);
  cyclade->making_entry_right = true;
  cyclade->making_entry_left = true;
  cyclade->network_ids = NULL;
  cyclade->nb_ids = 0;
  i = 0;
  while (i < DS_NB_NAMES)
    {
      if (i == DS_IN_LEFT || i == DS_IN_RIGHT)
	cyclade->data[i] = efnew_data_manager();
      else
	cyclade->data[i] = NULL;
      cyclade->queue[i] = efnew_queue();
      i += 1;
    }
  cyclade->prev_clock_state = CS_WRITE;
  efdiscover_cyclade(cyclade);
  return(cyclade);
}
