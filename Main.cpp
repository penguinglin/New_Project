// update main.cpp ok
#include "GameWindow.h"
int main(int argc, char **argv)
{
	Game *game = new Game();
	game->execute();
	delete game;
	return 0;
}
