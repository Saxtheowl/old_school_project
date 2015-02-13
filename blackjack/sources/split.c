#include "../my.h"

int		split_spotted(t_game game, int pl)
{
  int		nb1;
  int		nb2;

  nb1 = game.players[pl][0];
  nb2 = game.players[pl][1];
  while (nb1 > 13)
    nb1 = nb1 - 13;
  while (nb2 > 13)
    nb2 = nb2 - 13;
  if (nb1 == nb2 || (nb1 >= 10 && nb1 <= 13) && (nb2 >= 10 && nb1 <= 13))
    {
      my_putstr("SPLIT SPOTTED\n");
      return (1);
    }
  return (0);
}

t_game		ask_split(t_game game, int pl)
{
  int		nb;
  char		*commands;

  nb = 0;
  while (nb != 1 && nb != 2)
    {
      print_i_player(pl);
      my_putstr(" do u want to split ? 1. Yes 2. No\n");
      commands = put_prompt();
      nb = my_getnbr(commands);
    }
  if (nb == 1 && game.stack[pl] >=
      (game.bet[pl] * 2) && game.value_p[pl][0] > 1)
    {
      print_i_player(pl);
      my_putstr(" started a split");
      my_putstr(")\n");
      game.value_p[pl][6] = 1;
      game.cnfg.moar_c[pl] = 0;
      game = giff_me_card(game, pl, 0, 2);
    }
  return (game);
}
