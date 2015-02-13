#include "../my.h"

void		what_card(t_game game, int cnt)
{
  int		i;

  i = 0;
  while (i < game.cnfg.players)
    {
      if (game.stack[i] > 0 && game.cnfg.moar_c[i] == 1)
	{
	  print_i_card(game, i, cnt, 0);
	  if (game.players[i][cnt] == 1 || game.players[i][cnt] == 14
	      || game.players[i][cnt] == 27 || game.players[i][cnt] == 40)
	    game = what_if_ace(game, i, 0);
	  game = check_result(game, i, 0);
	  game = is_blackjack(game, i, 0);
	  if (cnt == 1 && game.value_p[i][0] != 98)
	    game = ask_special(game, i);
	  if (cnt > 0 && game.cnfg.moar_c[i] == 1)
	    game = moar_card(game, i, 0, 2);
	  i++;
	}
      else
	i++;
    }
}

int		get_value(t_game game, int pl, int i, int sp)
{
  int		val;

  while (game.players[pl][i])
    {
      val = game.players[pl][i];
      while (val > 13)
	val = val - 13;
      if (val >= 10)
	val = 10;
      val = game.value_p[pl][sp] + val;
      i++;
    }
  return (val);
}

int		get_value_de(t_game game, int i)
{
  int		val;

  i = 0;
  val = 0;
  while (game.dealer[i])
    {
      val = game.dealer[i];
      while (val > 13)
	val = val - 13;
      if (val >= 10)
	val = 10;
      val = game.value_d + val;
      i++;
    }
  return (val);
}

int		is_ace(int card)
{
  if (card == 1 || card == 14 || card == 27 || card == 40)
     return (1);
  return (0);
}
