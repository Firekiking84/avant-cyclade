/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 27/05/2024 01:38:46 ******************************************************
** keryan.houssin <keryan.houssin@aldrin.efrits.fr>
** - Avant-Cyclade -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"efstring.h"

#include		<string.h>
#include		<stdlib.h>


t_string		*string_new_str(const char	*str)
{
  t_string		*new_string;

  new_string = bunny_malloc(sizeof(*new_string));
  if (!new_string)
    return(NULL);
  new_string->str_len = strlen(str);
  new_string->size_alloc = new_string->str_len + 1;
  new_string->str = bunny_malloc(sizeof(char) * new_string->size_alloc);
  strcpy(new_string->str, str);
  return(new_string);
}
