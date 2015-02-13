#include <stdlib.h>
#include "../my.h"

int		not_on_the_deck(int *deck, int nb)
{
  int		i;

  i = 0;
  while (deck[i])
    {
      if (nb == deck[i])
	return (0);
      i++;
    }
  return (1);
}

t_game		generate_all_cards(t_game game)
{
  int		rd;
  int		i;
  int		f;

  i = 0;
  f = 0;
  while (i < 52)
    {
      rd = dat_rand(52);
      f++;
      if (not_on_the_deck(game.cards, rd))
	{
	  game.cards[i] = rd;
	  i++;
	}
    }
  i = 0;
}

t_game		get_all_type(t_game game)
{
  int		i;

  i = 0;
  game.type[0] = "ace";
  game.type[1] = "two";
  game.type[2] = "three";
  game.type[3] = "four";
  game.type[4] = "five";
  game.type[5] = "six";
  game.type[6] = "seven";
  game.type[7] = "eight";
  game.type[8] = "nine";
  game.type[9] = "ten";
  game.type[10] = "jack";
  game.type[11] = "queen";
  game.type[12] = "king";
  game.type[13] = "spades";
  game.type[14] = "hearts";
  game.type[15] = "diamonds";
  game.type[16] = "clubs";
  game.type[17] = NULL;
  return (game);
}
