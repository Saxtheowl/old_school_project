#include "../my.h"

int		is_alive(t_game game, int cnt, int i)
{
  int		f;

  f = 0;
  while (i < game.cnfg.players && cnt == 0)
    {
      print_i_player(i);
      my_putstr(" as ");
      my_putnbr(game.stack[i]);
      my_putstr(" stack left");
      if (game.stack[i] <= 1)
	{
	  my_putstr(" (dead)");
	  game.cnfg.moar_c[i] = 0;
	  f++;
	}
      my_putchar('\n');
      i++;
    }
  i = game.stack[0] * game.cnfg.players;
  if (f == game.cnfg.players)
    print_result(game, 0);
  return (1);
}

int		all_play(t_game game)
{
  int		i;
  int		f;

  i = 0;
  f = 0;
  while (i < game.cnfg.players)
    {
      if (game.cnfg.moar_c[i] == 0)
	{
	  f++;
	  i++;
	}
      else
	i++;
    }
  if (game.cnfg.players == f)
    return (1);
  return (0);
}

int		test_all_bust(t_game game)
{
  int		i;
  int		f;

  i = 0;
  f = 0;
  while (i < game.cnfg.players)
    {
      if (game.value_p[i][0] == 0)
	f++;
      i++;
    }
  if (f == game.cnfg.players)
    return (0);
  return (1);
}
