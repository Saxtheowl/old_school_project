#include <stdlib.h>
#include "../my.h"

int		check_size(int nb)
{
  if (is_even(nb) && nb >= 10 && nb < 100000)
     return (1);
  else
    {
      my_putstr("function check size wrong\n");
      return (0);
    }
}

t_game		get_cnfg_game(t_game game)
{
  char		*commands;
  int		nb;

  nb = 0;
  while (nb <= 0 || nb > 100000 || !is_even(nb))
    {
      my_putstr("how much stack u want ?\n");
      commands = put_prompt();
      nb = my_getnbr(commands);
    }
  game.cnfg.stack = nb;
  nb = 0;
  while (nb <= 0 || nb >= 5)
    {
      my_putstr("how many players u want ?\n");
      commands = put_prompt();
      nb = my_getnbr(commands);
    }
  game.cnfg.players = nb;
  game.cnfg.t_bet = game.cnfg.stack * game.cnfg.players * - 1;
  return (game);
}

t_game		init_all(t_game game, int i)
{
  game.stack = xmalloc(sizeof(*game.stack) * game.cnfg.players);
  game.cards = xmalloc(sizeof(game.cards) * 52 + 1);
  game.type = xmalloc(sizeof(*game.type) * 17 + 1);
  game.players = xmalloc(sizeof(*game.players) * 2);
  game.dealer = xmalloc(sizeof(*game.dealer) * 20);
  game.value_p = xmalloc(sizeof(*game.value_p) * game.cnfg.players);
  game.bet = xmalloc(sizeof(*game.bet) * game.cnfg.players);
  game.cnfg.moar_c = xmalloc(sizeof(*game.cnfg.moar_c) * game.cnfg.players);
  while (i < game.cnfg.players)
    {
      game.players[i] = xmalloc(sizeof(**game.players) * 20);
      game.value_p[i] = xmalloc(sizeof(**game.value_p) * 10);
      game.cnfg.moar_c[i] = 1;
      game.stack[i] = game.cnfg.stack;
      i++;
    }
  game = generate_all_cards(game);
  game.cnfg.idx_c = 0;
  game = get_all_type(game);
  game.value_d = 0;
  game.dealer = put_zero(game.dealer);
  return (game);
}

t_game		reset_all(t_game game)
{
  int		i;
  int		f;

  i = 0;
  f = 0;
  game.cards = put_zero(game.cards);
  game.dealer = put_zero(game.dealer);
  while (i < game.cnfg.players)
    {
      game.cnfg.moar_c[i] = 1;
      game.bet[i] = 0;
      game.players[i] = put_zero(game.players[i]);
      while (f < 10)
	{
	  game.value_p[i][f] = 0;
	  f++;
	}
      f = 0;
      i++;
    }
  game.cnfg.idx_c = 0;
  game.value_d = 0;
  game.players[i] = NULL;
  return (game);
}
