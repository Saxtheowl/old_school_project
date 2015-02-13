#include "../my.h"

int		my_getnbr(char *str)
{
  int		sign;
  unsigned int	nb;
  int		i;

  i = 0;
  sign = 1;
  nb = 0;
  while (str[i] == '+' || str[i] == '-')
    {
      if (str[i] == '-')
	sign = sign * -1;
      i++;
    }
  while (str[i] >= '0' && str[i] <= '9')
    {
      nb = nb * 10 + (str[i] - '0');
      i++;
    }
  return (nb * sign);
}
