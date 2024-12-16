#ifndef GAMEWINDOW_H_INCLUDED
#define GAMEWINDOW_H_INCLUDED
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <stdbool.h>
#include <string>

class Game
{
public:
  // Constructor and Destructor
  Game();  // game_init
  ~Game(); // game_destroy

  // Core Methods
  void execute(); // game_execute
  void game_init();
  bool game_update(); // game_update
  void game_draw();   // game_draw

private:
  const char *title;
  ALLEGRO_DISPLAY *display;
  ALLEGRO_EVENT_QUEUE *event_queue = NULL;
  ALLEGRO_EVENT event;
  ALLEGRO_TIMER *timer = NULL;
};

#endif // GAMEWINDOW_H_INCLUDED
