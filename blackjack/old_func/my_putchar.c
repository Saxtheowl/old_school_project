#include "../my.h"

void		my_putchar(char c)
{
  xwrite(1, &c, 1);
}
