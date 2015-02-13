#include "../my.h"

t_game		calc_blackjack(t_game game, int nb1, int nb2, int pl)
{
  if ((nb1 == 1 || nb2 == 1) &&
      ((nb1 >= 11 && nb1 <= 13) ||  (nb2 >= 11 && nb1 <= 13)))
    {
      if (pl < 5)
	{
	  game.value_p[pl][0] = 98;
	  game.cnfg.moar_c[pl] = 0;
	  my_putstr("BLACKJACK SPOTTED !!!\n");
	}
      else if (pl == 5)
	{
	  game.value_d = 98;
	  my_putstr("BLACKJACK SPOTTED ! for Dealer !!\n");
	}
    }
  return (game);
}

t_game		is_blackjack(t_game game, int pl, int flag)
{
  int		nb1;
  int		nb2;

  if (flag == 0)
    {
      nb1 = game.players[pl][0];
      nb2 = game.players[pl][1];
    }
  else if (flag == 1)
    {
      nb1 = game.dealer[0];
      nb2 = game.dealer[1];
    }
  while (nb1 > 13)
    nb1 = nb1 - 13;
  while (nb2 > 13)
    nb2 = nb2 - 13;
  if (flag == 0)
    game = calc_blackjack(game, nb1, nb2, pl);
  else
    game = calc_blackjack(game, nb1, nb2, 5);
  return (game);
}
