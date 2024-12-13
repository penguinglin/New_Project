
#include "Game.h"
#include <iostream>
Game *game = new Game();
int main(int argc, char **argv)
{
  game->execute();
  delete game;
  return 0;
}
