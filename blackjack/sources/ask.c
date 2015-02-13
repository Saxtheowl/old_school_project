#include "../my.h"

char		*put_prompt()
{
  char		*prompt;
  char		*commands;

  prompt = ">";
  my_putstr(prompt);
  commands = hook_full_instr();
  return (commands);
}

int		what_choice(int pl)
{
  int		nb;
  char		*commands;

  nb = 0;
  while (nb != 1 && nb != 2)
    {
      print_i_player(pl);
      my_putstr(" do u want more card ? 1. Yes, 2. No \n");
      commands = put_prompt();
      nb = my_getnbr(commands);
    }
  return (nb);
}

t_game		ask_special(t_game game, int i)
{
  if (game.stack[i] >= (game.bet[i] * 2) && game.cnfg.moar_c[i] != 0)
    game = double_bet(game, i);
  if (game.value_p[i][4] == 0)
    game = abandon_ship(game, i);
  if (split_spotted(game, i))
    game = ask_split(game, i);
  return (game);
}

t_game		what_bet(t_game game, int i, int nb)
{
  char		*commands;

  i = 0;
  nb = 0;
  while (i <= game.cnfg.players)
    {
      if (game.cnfg.moar_c[i] == 1)
	{
	  while (nb > game.stack[i] || nb <= 0 || !is_even(nb))
	    {
	      print_i_player(i);
	      my_putstr(" How much u wana bet ? (");
	      my_putnbr(game.stack[i]);
	      my_putstr(" left) ");
	      commands = put_prompt();
	      nb = my_getnbr(commands);
	      my_putchar('\n');
	    }
	  game.bet[i] = my_getnbr(commands);
	  nb = 0;
	  i++;
	}
      else
	i++;
    }
}
