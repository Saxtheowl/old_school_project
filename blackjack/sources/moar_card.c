#include "../my.h"

t_game		xmoar_card(t_game game, int pl, int spl, int cnt)
{
  game = giff_me_card(game, pl, cnt, spl);
  game.cnfg.idx_c++;
  cnt++;
  if (is_ace(game.players[pl][cnt]))
    game = what_if_ace(game, pl, 0);
  game = check_result(game, pl, spl);
  if (game.value_p[pl][4] == 1)
    game.cnfg.moar_c[pl] = 0;
  return (game);
}

t_game		xxmoar_card(t_game game, int pl, int spl, int cnt)
{
  print_i_player(pl);
  my_putstr(" stay with ");
  my_putnbr(game.value_p[pl][spl]);
  my_putchar('\n');
  if (spl == 0)
    game.cnfg.moar_c[pl] = 0;
  return (game);
}

t_game		moar_card(t_game game, int pl, int spl, int cnt)
{
  char		*commands;
  int		nb;

  while (game.cnfg.moar_c[pl] == 1 || game.value_p[pl][6] == 1)
    {
      nb = what_choice(pl);
      if (nb == 1)
	game = xmoar_card(game, pl, spl, cnt);
      else if (nb == 2)
	{
	  game = xxmoar_card(game, pl, spl, cnt);
	  if (spl != 0)
	    {
	      game.value_p[pl][6] = 0;
	      game.cnfg.moar_c[pl] = 1;
	      return (game);
	    }
	}
      else
	nb = what_choice(pl);
    }
  if (spl == 1)
    game.cnfg.moar_c[pl] = 1;
  return (game);
}

t_game		giff_me_card(t_game game, int pl, int cnt, int flag)
{
  int		cntt;
  int		i;

  i = 0;
  cntt = 13;
  if (flag == 2)
    {
      while (i < 2)
	{
	  game.players[pl][cntt] = game.cards[game.cnfg.idx_c];
	  game.value_p[pl][1] = get_value(game, pl, 13, 1);
	  print_i_card(game, pl, cntt, 1);
	  cntt++;
	  game.cnfg.idx_c++;
	  i++;
	}
      game = moar_card(game, pl, 1, 15);
      return (game);
    }
  game.players[pl][cnt] = game.cards[game.cnfg.idx_c];
  game.value_p[pl][flag] = get_value(game, pl, cnt, flag);
  print_i_card(game, pl, cnt, flag);
  if (is_ace(game.players[pl][cnt]))
    game = what_if_ace(game, pl, 0);
  return (game);
}
