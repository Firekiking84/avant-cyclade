/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 27/05/2024 01:38:44 ******************************************************
** keryan.houssin <keryan.houssin@aldrin.efrits.fr>
** - Avant-Cyclade -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"efstring.h"

#include		<string.h>
#include		<stdlib.h>

t_string		*string_new_string(const t_string	*other)
{
  t_string		*new_string;

  new_string =  bunny_malloc(sizeof(*new_string));
  if (!new_string)
    return(NULL);
  new_string->str_len = other->str_len;
  new_string->size_alloc = other->str_len + 1;
  new_string->str =  bunny_malloc(sizeof(char) * new_string->size_alloc);
  strcpy(new_string->str, other->str);
  return(new_string);
}
