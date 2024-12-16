#include "GameWindow.h"
#include "global.h"
#include "Utils.h"
#include "shapes/Shape.h"
// include allegro
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
// include scene and following component
#include "scene/sceneManager.h"
#include <stdbool.h>

Game::Game()
{
  // Constructor ok
  printf("Game is iGame()...\n");
  GAME_ASSERT(al_init(), "failed to initialize allegro.");

  // initialize allegro addons ok
  // form TA template
  {
    bool addon_init = true;
    addon_init &= al_init_primitives_addon();
    addon_init &= al_init_font_addon();   // initialize the font addon
    addon_init &= al_init_ttf_addon();    // initialize the ttf (True Type Font) addon
    addon_init &= al_init_image_addon();  // initialize the image addon
    addon_init &= al_init_acodec_addon(); // initialize acodec addon
    GAME_ASSERT(addon_init, "failed to initialize allegro addons.");

    bool event_init = true;
    event_init &= al_install_keyboard();
    event_init &= al_install_mouse();
    event_init &= al_install_audio();
    GAME_ASSERT(event_init, "failed to initialize allegro events.");
  }

  // initialize game body - display, timer, event_queue ok
  {
    // create display(in game window.h)
    GAME_ASSERT(
        display = al_create_display(WIDTH, HEIGHT),
        "failed to create display.");
    // call timer & FPS in global.h
    GAME_ASSERT(
        timer = al_create_timer(1.0 / FPS),
        "failed to create timer.");
    GAME_ASSERT(
        event_queue = al_create_event_queue(),
        "failed to create event queue.");
  }

  // set the title
  title = "Final Project - MeowMeow";

  debug_log("Game initialized.\n");
  game_init();
}

Game::~Game()
{
  // Destructor
  al_destroy_display(display);
  al_destroy_timer(timer);
  al_destroy_event_queue(event_queue);
}

void Game::game_init()
{
  printf("Game Initializing...\n");
  GAME_ASSERT(al_init(), "failed to initialize allegro.");

  // Create first scene
  create_scene(Menu_L);

  // set title
  al_set_window_title(display, title);

  // Register event check ok
  {
    al_register_event_source(event_queue, al_get_display_event_source(display)); // register display event
    al_register_event_source(event_queue, al_get_keyboard_event_source());       // register keyboard event
    al_register_event_source(event_queue, al_get_mouse_event_source());          // register mouse event
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
  }

  // set the game mode
  ModeCondition[0] = true; // default mode

  // start the timer
  al_start_timer(timer);

  // initialize the icon on the display
  ALLEGRO_BITMAP *icon = al_load_bitmap("assets/image/icon.png");
  al_set_display_icon(display, icon);
}

void Game::execute()
{
  // main game loop
  bool run = true;

  // game loop
  while (run && (CloseGame == 0))
  {
    // process all events here
    al_wait_for_event(event_queue, &event);
    switch (event.type)
    {
    case ALLEGRO_EVENT_TIMER:
    {
      run &= game_update();
      game_draw();
      break;
    }
    case ALLEGRO_EVENT_DISPLAY_CLOSE: // stop game
    {
      run = false;
      break;
    }
    case ALLEGRO_EVENT_KEY_DOWN:
    {
      // if press ESC key, close the game
      key_state[event.keyboard.keycode] = true;
      if (key_state[ALLEGRO_KEY_ESCAPE])
      {
        run = false;
      }
      break;
    }
    case ALLEGRO_EVENT_KEY_UP:
    {
      key_state[event.keyboard.keycode] = false;
      break;
    }
    case ALLEGRO_EVENT_MOUSE_AXES:
    {
      mouse.x = event.mouse.x;
      mouse.y = event.mouse.y;
      break;
    }
    case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
    {
      mouse_state[event.mouse.button] = true;
      break;
    }
    case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
    {
      mouse_state[event.mouse.button] = false;
      break;
    }
    default:
      break;
    }
  }
}

bool Game::game_update()
{
  scene->Update(scene);
  if (scene->scene_end)
  {
    scene->Destroy(scene);
    switch (window)
    {
    case 0: // 進入主菜單(在sceneManager.h新增case標籤)->【預設】
      create_scene(Menu_L);
      break;
    case 1: // 進入遊戲主畫面->【主選單】
      create_scene(GameScene_L);
      break;
    case 2: // 進入設定->【主選單】
      create_scene(Set_L);
      break;
    case 3: // 進入說明->【主選單】
      create_scene(Information_L);
      break;
    case 4: // 關閉遊戲 ->【主選單】
      create_scene(Quit_L);
      break;
    case -1:
      return false;
    default:
      break;
    }
  }
  return true;
}

void Game::game_draw()
{
  // Flush the screen first.
  al_clear_to_color(al_map_rgb(0, 0, 0));
  scene->Draw(scene);
  al_flip_display();
}