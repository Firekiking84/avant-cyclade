#include		<stdio.h>

int			main(void)
{
  int			id;
  int			dest_id;
  char			msg[4096];

  scanf("%d %d %s", &id, &dest_id, msg);
  printf("%d %d %s", id, dest_id, msg);
}
