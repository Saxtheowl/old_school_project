#include "../my.h"

void		putnbr_rec(unsigned int nb)
{
  if (nb > 9)
    putnbr_rec(nb / 10);
  my_putchar(nb % 10 + '0');
}

void		my_putnbr(int nb)
{
  unsigned int	inb;

  if (nb < 0)
    {
      my_putchar('-');
      inb = nb * -1;
    }
  else
    inb = nb;
  putnbr_rec(inb);
}
