#include <string.h>
#include "../my.h"

void		my_putstr(char *str)
{
  xwrite(1, str, strlen(str));
}
