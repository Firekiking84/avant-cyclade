#ifndef		__EF_STRING_H__

#define		__EF_STRING_H__

#include        <lapin.h>

typedef struct	s_string
{
  char		*str;
  int		size_alloc;
  int		str_len;
}		t_string;

t_string	*efstring_new();
t_string	*string_new_string(const t_string	*other);
t_string	*string_new_str(const char		*str);
void		string_delete(t_string			*string);
int		string_push_back(t_string		*string,
				 char			c);
int		string_pop_back(t_string		*string);
int		string_erase(t_string			*string,
			     int			index);
int		string_append_string(t_string		*string,
				     const t_string	*other);
int		string_append_str(t_string		*string,
				  const char		*str);
int		string_clear(t_string			*string);
int		string_shrink_to_fit(t_string		*string);
char		string_get_char(t_string		*string,
				int			index);
const char	*string_get_content(t_string		*string);
int		string_get_len(t_string			*string);
int		string_compare(const t_string		*string,
			       const t_string		*other);
int		string_compare_str(const t_string	*string,
				   const char		*str);
int		string_insert(t_string			*string,
			      int			index,
			      char			c);
int		efstring_resize(t_string		*string,
				int			new_size);
char		*efstrdup(const char			*str);

#endif //	__EF_STRING_H__
