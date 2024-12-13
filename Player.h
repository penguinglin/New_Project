#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

class Player
{
public:
	Player();
	void init();
	void update();
	// void draw(int x, int y);
	int precounter = 180;
	int HP;
	int coin;
	int timer;
	int hungry;
	bool KILLmonster = false;
	bool GetMoreTime = false;
	bool GetFood = false;
	bool Fix_boat = false;
	bool Get_fire = false;

private:
	int x, y;
	int coin_freq;
	int coin_increase;
	int coin_counter;

	// ADD Timer
	int Time_counter;
	int Time_freq;
	int Time_increase;

	// ADD Humgry Counter
	int Hungry_counter;
	int Hungry_freq;
	int Hungry_decrease;
};

#endif