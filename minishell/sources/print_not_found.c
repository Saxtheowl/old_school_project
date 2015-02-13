#include <stdio.h>
#include "../my.h"

int		print_not_found(char *str)
{
  int		i;

  i = 0;
  while (str[i] != ' ' && str[i] != '\0')
    {
      printf("%s", str[i]);
      i = i + 1;
    }
}
