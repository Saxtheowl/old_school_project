#include "../my.h"

t_game		check_result(t_game game, int pl, int spl)
{
  if (game.value_p[pl][spl] > 21)
    {
      my_putstr("players ");
      my_putnbr(pl);
      if (spl == 1)
	{
	  my_putstr("split");
	  my_putstr(" is busted \n");
	  game.value_p[pl][6] = 2;
	  game.stack[pl] = game.stack[pl] - game.bet[pl];
	  return (game);
	}
      else
      my_putstr(" is busted \n");
      game.cnfg.moar_c[pl] = 0;
      game.value_p[pl][spl] = 0;
    }
  return (game);
}

t_game		xget_result_s(t_game game, int flag, int i)
{
  if (flag == 0)
    {
      print_i_player(i);
      my_putstr(" lost his split \n");
    }
  else
    {
      print_i_player(i);
      my_putstr(" win his split \n");
      game.stack[i] = game.stack[i] + game.bet[i];
    }
  return (game);
}

t_game		get_result_s(t_game game)
{
  int		i;

  i = 0;
  while (i < game.cnfg.players)
    {
      if (game.value_p[i][1] == game.value_d &&
	 game.value_p[i][6] != 2 && game.value_p[i][1] > 0)
	{
	  print_i_player(i);
	  my_putstr("split is draw\n");
	  game.stack[i] = game.stack[i] + (game.bet[i] / 2);
	  return (game);
	}
      if (game.value_p[i][1] < game.value_d && game.value_p[i][1] != 0)
	game = xget_result_s(game, 0, i);
      else if (game.value_p[i][1] > game.value_d && game.value_p[i][6] != 2)
	game = xget_result_s(game, 1, i);
      i++;
    }
  return (game);
}

t_game		xget_result(t_game game, int flag, int i)
{
  if (flag == 0)
    {
      print_i_player(i);
      if (game.value_p[i][0] == 98 && game.value_d == 21)
	game.stack[i] = game.stack[i] + game.bet[i] / 2;
      my_putstr(" round is draw\n");
    }
  else if (flag == 1)
    {
      print_i_player(i);
      my_putstr(" win the round ");
      game.stack[i] = game.stack[i] + game.bet[i];
      my_putstr("new stack ");
      my_putnbr(game.stack[i]);
      my_putchar('\n');
    }
  return (game);
}

t_game		get_result(t_game game)
{
  int		i;

  i = 0;
  while (i < game.cnfg.players)
    {
      if (game.value_p[i][0] == game.value_d)
	game = xget_result(game, 0, i);
      else if (game.value_p[i][0] > game.value_d &&
	      game.cnfg.moar_c[i] == 0)
	game = xget_result(game, 1, i);
      else
	{
	  print_i_player(i);
	  my_putstr(" lost the round \n");
	  game.stack[i] = game.stack[i] - game.bet[i];
	}
      if (game.value_p[i][3] == 1 && game.value_d == 98)
	game.stack[i] = game.stack[i] + (game.bet[i] / 2);
      my_putchar('\n');
      i++;
    }
  return (game);
}
