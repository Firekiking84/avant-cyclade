/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 27/05/2024 01:39:09 ******************************************************
** keryan.houssin <keryan.houssin@aldrin.efrits.fr>
** - Avant-Cyclade -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"efstring.h"

#include		<stdlib.h>
#include		<string.h>

int			string_append_string(t_string		*string,
					     const t_string	*other)
{
  if ((string->str_len + other->str_len) > string->size_alloc)
    if (efstring_resize(string, string->str_len + other->str_len + 1) == -1)
      return(-1);
  strcat(string->str, other->str);
  string->str_len += other->str_len;
  return(0);
}
