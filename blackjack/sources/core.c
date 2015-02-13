#include "../my.h"

t_game		delivery(t_game game, int cnt)
{
  int		i;

  i = 0;
  while (i < game.cnfg.players)
    {
      if (game.cnfg.moar_c[i] == 1)
	{
	  game.players[i][cnt] = game.cards[game.cnfg.idx_c];
	  game.value_p[i][0] = get_value(game, i, 0, 0);
	  i++;
	  game.cnfg.idx_c++;
	}
      else
	i++;
    }
  if (cnt == 0)
    game = play_dealer(game, 0, 1);
  i = 0;
  what_card(game, cnt);
  return (game);
}

void		launch_game(t_game game, int cnt)
{
  while (is_alive(game, cnt, 0))
    {
      if (cnt == 0)
	{
	  game = what_bet(game, 0, 0);
	  game = delivery(game, cnt);
	  cnt++;
	}
      else
	{
	  game = delivery(game, cnt);
	  cnt++;
	}
      if (all_play(game) && cnt > 0)
	{
	  if (test_all_bust(game))
	    game = play_dealer(game, 1, 1);
	  game = get_result(game);
	  game = get_result_s(game);
	  game = reset_all(game);
	  game = generate_all_cards(game);
	  cnt = 0;
	  print_round(game);
	}
    }
}

void		start_game(int flag)
{
  t_game	game;

  if (flag == 1)
    {
      game = get_cnfg_game(game);
      game = init_all(game, 0);
    }
  else
    my_putstr("new round begin now !\n");
  launch_game(game, 0);
}
