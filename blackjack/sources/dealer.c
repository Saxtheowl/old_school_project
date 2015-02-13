#include "../my.h"

t_game		xplay_dealer(t_game game)
{
  game.dealer[0] = game.cards[game.cnfg.idx_c];
  game.value_d = get_value_de(game, 0);
  print_d(game, 0, 0);
  game.cnfg.idx_c++;
  if (is_ace(game.dealer[0]))
    game = want_insu(game, 0, 0);
  return (game);
}

t_game		play_dealer(t_game game, int flag, int i)
{
  if (flag == 0)
    game = xplay_dealer(game);
  if (flag == 1)
    {
      while (game.value_d < 17 && game.value_d < 21)
	{
	  game.dealer[i] = game.cards[game.cnfg.idx_c];
	  game.value_d = get_value_de(game, 0);
	  print_d(game, i, 0);
	  if (game.value_d > 21)
	    {
	      my_putstr("dealer is busted\n");
	      game.value_d = 0;
	      return (game);
	    }
	  if (i < 2)
	    game = is_blackjack(game, 0, 1);
	  print_d(game, 0, 1);
	  game.cnfg.idx_c++;
	  i++;
	}
    }
  return (game);
}
