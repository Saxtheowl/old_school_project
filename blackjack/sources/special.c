#include "../my.h"

t_game		double_bet(t_game game, int pl)
{
  int		i;
  int		nb;
  char		*commands;

  nb = 0;
  while (nb != 1 && nb != 2)
    {
      my_putstr("Players ");
      my_putnbr(pl);
      my_putstr(" do u want to double ur bet ? 1. Yes, 2. No\n");
      commands = put_prompt();
      nb = my_getnbr(commands);
    }
  if (nb == 1)
    {
      game.bet[pl] = game.bet[pl] * 2;
      game.value_p[pl][4] = 1;
      my_putstr("Player ");
      my_putnbr(pl);
      my_putstr(" double his bet, good luck\n");
    }
  return (game);
}

t_game		abandon_ship(t_game game, int pl)
{
  int		nb;
  char		*commands;

  nb = 0;
  while (nb != 1 && nb != 2)
    {
      print_i_player(pl);
      my_putstr(" do u want to abandon this round ? 1. Yes, 2. No\n");
      commands = put_prompt();
      nb = my_getnbr(commands);
    }
  if (nb == 1)
    {
      game.stack[pl] = game.stack[pl] + ( game.bet[pl] / 2);
      game.cnfg.moar_c[pl] = 0;
      game.value_p[pl][0] = 0;
      print_i_player(pl);
      my_putstr(" leave this round\n");
    }
  return (game);
}

t_game		want_insu(t_game game, int nb, int i)
{
  char		*commands;

  while (i < game.cnfg.players)
    {
      nb = 0;
      while (nb != 1 && nb != 2)
	{
	  print_i_player(i);
	  my_putstr(" dealer just hit an ace, do u want an insurance");
	  my_putstr(" ? 1. Yes, 2. No\n");
	  commands = put_prompt();
	  nb = my_getnbr(commands);
	}
      if (nb == 1)
	{
	  print_i_player(i);
	  my_putstr(" take an insurance\n");
	  game.value_p[i][3] = 1;
	  i++;
	}
      else
	i++;
    }
  return (game);
}

t_game		what_if_ace(t_game game, int players, int cnt)
{
  int		nb;
  char		*commands;

  nb = 0;
  while (nb != 1 && nb != 2)
    {
      print_i_player(players);
      my_putstr(" do u want to change the value of ");
      my_putstr("your ace from 1 to 11 ? 1. Yes, 2. No \n");
      commands = put_prompt();
      nb = my_getnbr(commands);
    }
  if (nb == 1)
    {
      game.value_p[players][cnt] = game.value_p[players][cnt] + 10;
      print_i_player(players);
      my_putstr(" changed his ace (new value: ");
      my_putnbr(game.value_p[players][cnt]);
      my_putstr(")\n");
    }
  return (game);
}
