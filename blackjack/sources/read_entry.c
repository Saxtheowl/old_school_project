#include "../my.h"

char		*some_epur(char *commands)
{
  int		i;
  char		*new_str;

  i = 0;
  while (commands[i + 1])
    i++;
  new_str = xmalloc(sizeof(*new_str) * my_strlen(commands));
  my_strncat(new_str, commands, my_strlen(commands) -1);
  commands = my_strdup(new_str);
  return (commands);
}

char		hook_char()
{
  char		*c;

  c = xmalloc(sizeof(c) * 1);
  if ((xread(0, c, 1) == -1))
    return (2);
  if (c[0] == 4)
    return (2);
  return (c[0]);
}

char		*hook_full_instr()
{
  char		*tab;
  int		i;

  i = 0;
  tab = xmalloc(sizeof(tab)* 1);
  while ((tab[i++] = hook_char()) != 10);
  tab = some_epur(tab);
  return (tab);
}
