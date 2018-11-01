#pragma once
#ifndef Player_h__
#define Player_h__
#include <boost/scoped_ptr.hpp>
#include <cmath>
#include "Game.h"
#include "Graphics.h"
#include "Sprite.h"

class Player
{
public:
    Player(Graphics &graphics, int x, int y);
	~Player();
	void update(int elapsed_time_ms);
	void draw(Graphics &graphics);
	void startMovingLeft();
	void startMovingRight();
	void stopMoving();

private:
	int x_, y_;
	float acceleration_x_;
	float velocity_x_;

	boost::scoped_ptr<Sprite> sprite_;
};


#endif // Player_h__

