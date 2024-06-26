/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 23/05/2024 12:01:10 ******************************************************
** keryan.houssin <keryan.houssin@jemison.efrits.fr>
** - Avant-Cyclade -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#ifndef			__CYCLADE_H__

#define			__CYCLADE_H__

#include		"queue.h"
#include		"string.h"
#include		"data_manager.h"

// a = target, b = index
#define GET_BIT(a, b) ((1 << (b)) & (a))

// a = target, b = index, c = value(bool)
#define EDIT_BIT(a, b, c) (c) ? ((a) = (a) | (1 << (b))) : ((a) = (a) & (~(1 << (b))))

struct s_simulation;

typedef enum		e_pin_output_num
  {
    PO_NONE = -1,
    PO_CHECK_OUT_RIGHT,
    PO_OUT2_RIGHT,
    PO_OUT1_RIGHT,
    PO_CHECK_OUT_LEFT,
    PO_OUT2_LEFT,
    PO_OUT1_LEFT,
    PO_DOWN
  }			t_pin_output_num;

typedef enum		e_pin_input_num
  {
    PI_NONE = -1,
    PI_A_CLOCK,
    PI_A_IN1_LEFT,
    PI_IN2_LEFT = 0,
    PI_CHECK_IN_LEFT,
    PI_IN1_RIGHT,
    PI_IN2_RIGHT,
    PI_CHECK_IN_RIGHT
  }			t_pin_input_num;

typedef enum		e_clock_state
  {
    CS_NONE = false,
    CS_WRITE = false,
    CS_READ = true
  }			t_clock_state;

typedef enum		e_data_stream
  {
    DS_NONE = -1,
    DS_IN_LEFT,
    DS_IN_RIGHT,
    DS_OUT_LEFT,
    DS_OUT_RIGHT,
    DS_NB_NAMES = 4
  }			t_data_stream;

typedef struct		s_cyclade
{
  uint32_t		id;
  bool			simulation;
  uint32_t		*network_ids;
  uint32_t		nb_ids;
  bool			making_entry_left;
  bool			making_entry_right;
  t_bunny_vm110n	*card;
  t_data_manager	*data[4];
  t_queue		*queue[4];
  bool			prev_clock_state;
}			t_cyclade;

t_cyclade		*efopen_cyclade(size_t				id,
					void				*simulation); // simulation = NULL si pas simulation
void			efclose_cyclade(t_cyclade			*cyclade);
t_bunny_vm110n		*new_vm110n_simulation(int			id,
					       void			*simulation);
void			efread_simulation_vm110n(t_bunny_vm110n		*card);
void			efwrite_simulation_vm110n(t_bunny_vm110n	*card);
void			efrefresh_cyclade(t_cyclade			*cyclade);
int			efsend_manager_cyclade(t_cyclade		*cyclade,
					       t_data_manager		*manager);
void			efread_cyclade(t_cyclade			*cyclade);
void			efwrite_cyclade(t_cyclade			*cyclade);
t_data_manager		*efget_rcv_data_cyclade(t_cyclade		*cyclade);
int			efdiscover_cyclade(t_cyclade			*cyclade);
void			efmanage_rcv_data_cyclade(t_cyclade		*cyclade);
void			efmanage_discover_result_cyclade(t_cyclade	*cyclade,
							 t_data		*data);
uint32_t		efhash_djb2_cyclade(char			*str);
void			efready_to_read_cyclade(t_cyclade		*data);

int			efsend_data_cyclade(t_cyclade			*cyclade,
					    uint32_t			target,
					    void			*data,
					    uint32_t			datalen);


#endif	//		__CYCLADE_H__
