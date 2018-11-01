#pragma once
#ifndef CAVE_GAME_H
#define CAVE_GAME_H
#include <iostream>
#include <SDL/SDL.h>
#include <boost/scoped_ptr.hpp>
#include "Player.h"
#include "Graphics.h"
#include "AnimatedSprite.h"
#include "Input.h"

class Player;

class Game {
public:
    Game();

    ~Game();

    static int kTileSize;

private:
    void eventLoop();

    void draw(Graphics &graphics);

    void update(int elapsed_time_ms);

	boost::scoped_ptr<Player> player_;

};


#endif //CAVE_GAME_H
