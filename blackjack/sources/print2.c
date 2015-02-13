#include "../my.h"

void		print_result(t_game game, int flag)
{
  int		i;

  i = 0;
  while (i < game.cnfg.players)
    {
      game.cnfg.t_bet = game.cnfg.t_bet + game.stack[i];
      i++;
    }
  my_putstr("Game is over\n");
  if (game.cnfg.t_bet < 0)
    {
      game.cnfg.t_bet = game.cnfg.t_bet * - 1;
      flag = 1;
    }
  my_putnbr(game.cnfg.t_bet);
  my_putstr(" dollars has been ");
  if (flag == 0)
    my_putstr("added");
  else
    my_putstr("deducted");
  my_putstr(" to your paypal account astek@epitech.net .");
  my_putstr(", thanks for playing ;)\n");
  my_putstr("return to main menu\n\n");
  main_menu();
}

void		print_color(char **type, int color)
{
  my_putstr(" of ");
  if (color == 0)
    my_putstr(type[13]);
  else if (color == 1)
    my_putstr(type[14]);
  else if (color == 2)
    my_putstr(type[15]);
  else if (color == 3)
    my_putstr(type[16]);
}

void		print_card(char **type, int card)
{
  if (card < 13)
    {
      my_putstr(type[card]);
      print_color(type, 0);
    }
  else if (card < 26)
    {
      my_putstr(type[card - 13]);
      print_color(type, 1);
    }
  else if (card < 39)
    {
      my_putstr(type[card - 26]);
      print_color(type, 2);
    }
  else
    {
      my_putstr(type[card - 39]);
      print_color(type, 3);
    }
  my_putstr(". ");
}
