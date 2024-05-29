/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 27/05/2024 01:38:48 ******************************************************
** keryan.houssin <keryan.houssin@aldrin.efrits.fr>
** - Avant-Cyclade -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"efstring.h"

#include		<stdlib.h>

t_string		*efstring_new()
{
  t_string		*new_string;

  new_string = bunny_malloc(sizeof(*new_string));
  if (!new_string)
    return(NULL);
  new_string->str = NULL;
  new_string->size_alloc = 0;
  new_string->str_len = 0;
  return(new_string);
}
