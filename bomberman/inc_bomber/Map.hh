
#ifndef _MAP_HH_
# define _MAP_HH_

#include <vector>
#include <iostream>

#include "enum.hh"
#include "Case.hh"
#include "Wall.hh"
#include "Block.hh"
#include "Floor.hh"
#include "Bomb.hh"
#include "Bonus.hh"
#include "Player.hh"

class Bomb;

class Map
{
private:
  std::vector <Case*> matrix;
  std::vector <int> pos_P;
  int x_map;
  int y_map;
  bool player1;
  bool player2;
  bool put_a_bomb;

  void get_size_map(std::string &dat_name);
  void fill_map(std::string &dat_name);
  void load_cases();
public:
  Map(std::string dat_name);
  ~Map();
  std::vector<Bomb*> vec_bomb;
  Case *getCase(int x, int y) const;
  Case *getCase(int i) const;
  int  getx_Map() const;
  int  gety_Map() const;
  bool getPlayer1() const;
  bool getPlayer2() const;
  void setPlayer1(bool alive);
  void setPlayer2(bool alive);
  std::vector <Case*> getMatrix() const;
  int  get_pos_P(int nb_P);
  void set_pos_P(int nb_P, int posi_P);
  int  fix_Pos(int x, int y) const;
  void put_player(int player);
  void put_bot(int bot);
  void addCasePlayer(int x, int y, int nb, Dir direction, int index,
		     int force, int nb_b, int indt, bool speed);
  void addCaseFloor(int x, int y);
  void addCaseFloor(int i, bool up);
  void addCaseBonus(int i);
  bool move_up(int i);
  bool move_left(int i);
  bool move_down(int i);
  bool move_right(int i);
  void pos_bomb(int i);
  bool botAlive();
};

#endif