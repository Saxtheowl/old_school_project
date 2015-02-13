#include "../my.h"

int		print_rules()
{
  my_putstr("max player 4\n");
  my_putstr("bet max 100000\n");
  my_putstr("u can only bet pair number (2, 4, 6, 3000...)\n");
  my_putstr("if u got only 1 chip left on ur stack u dead\n");
  main_menu();
}

void		print_i_player(int pl)
{
  my_putstr("Player ");
  my_putnbr(pl);
}

void		print_i_card(t_game game, int pl, int sl, int sp)
{
  print_i_player(pl);
  my_putstr(" got a ");
  print_card(game.type, game.players[pl][sl] - 1);
  my_putstr(" (total value ");
  my_putnbr(game.value_p[pl][sp]);
  my_putstr(")\n");
}

int		print_d(t_game game, int cnt, int flag)
{
  if (flag == 1)
    {
      return (0);
    }
  else
    {
      my_putstr("dealer got a ");
      print_card(game.type, game.dealer[cnt] - 1);
      my_putstr("total: ");
      my_putnbr(game.value_d);
      my_putchar('\n');
    }
}

void		print_round(t_game game)
{
  int		nb;
  char		*commands;

  nb = 0;
  while (nb != 1 && nb != 2)
    {
      my_putstr("new round start now, do u want to continue ? ");
      my_putstr("1. Yes, 2. No\n");
      commands = put_prompt();
      nb = my_getnbr(commands);
    }
  if (nb == 2)
    print_result(game, 0);
  my_putstr("\33[2J\33[H");
}
