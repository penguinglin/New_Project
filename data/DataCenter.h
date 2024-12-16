// #ifndef DATACENTER_H_INCLUDED
// #define DATACENTER_H_INCLUDED

// #include <map>
// #include <vector>
// #include <allegro5/keycodes.h>
// #include <allegro5/mouse.h>
// #include "../shapes/Point.h"

// class Player;
// class Level;
// class Monster;
// class Tower;
// class Bullet;
// class PlayerControl;
// // class MENU;

// class DataCenter
// {
// public:
// 	static DataCenter *get_instance()
// 	{
// 		static DataCenter DC;
// 		return &DC;
// 	}
// 	~DataCenter();

// public:
// 	double FPS;
// 	int window_width, window_height;

// 	int game_field_length;
// 	int game_field_height;

// 	bool key_state[ALLEGRO_KEY_MAX];

// 	bool prev_key_state[ALLEGRO_KEY_MAX];

// 	Point mouse;

// 	bool mouse_state[ALLEGRO_MOUSE_MAX_EXTRA_AXES];

// 	bool prev_mouse_state[ALLEGRO_MOUSE_MAX_EXTRA_AXES];

// public:
// 	Player *player;
// 	PlayerControl *playerControl;
// 	// MENU *menu;
// 	Level *level;

// 	std::vector<Monster *> monsters;

// 	std::vector<Tower *> towers;

// 	std::vector<Bullet *> towerBullets;

// private:
// 	DataCenter();
// };

// #endif
