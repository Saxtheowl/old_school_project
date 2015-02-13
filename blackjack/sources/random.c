#include <time.h>
#include "../my.h"
#include "../my_list.h"

int		dat_rand(int limit)
{
  static unsigned int dat_seed = 1;
  static unsigned int init = 1;

  if (init)
    {
      dat_seed = time(0);
      init = 0;
    }
  dat_seed = (dat_seed * 32719 + 3) % 32749;
  return (dat_seed % limit) + 1;
}
