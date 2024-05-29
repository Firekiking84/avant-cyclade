/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 27/05/2024 01:36:14 ******************************************************
** keryan.houssin <keryan.houssin@aldrin.efrits.fr>
** - Avant-Cyclade -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include			"efstring.h"

int				efstring_resize(t_string	*string,
						int		new_size)
{
  char				*new_array;
  int				i;

  string->size_alloc = new_size;
  if (string->size_alloc < string->str_len)
    string->str_len = string->size_alloc - 1;
  new_array = bunny_malloc(sizeof(char) * string->size_alloc);
  if (!new_array)
    {
      bunny_perror("Bunny_malloc new_array string_resize");
      string->size_alloc = 0;
      string->str_len = 0;
      return(-1);
    }
  i = 0;
  while (i < string->str_len)
    {
      new_array[i] = string->str[i];
      i += 1;
    }
  new_array[i] = '\0';
  bunny_free(string->str);
  string->str = new_array;
  return(0);
}
