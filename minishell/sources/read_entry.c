#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "../my_list.h"
#include "../my.h"

char		hook_char()
{
  char		*c;

  c = xmalloc(sizeof(c) * 1);
  if((xread(0, c, 1) == -1))
    my_exit();
  return (c[0]);
}

char		*hook_full_instr()
{
  char		*tab;
  int		i;

  i = 0;
  tab = xmalloc(sizeof(tab)* 1);
  while ((tab[i++] = hook_char()) != 10);
  return (tab);
}
