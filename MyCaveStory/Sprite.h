#pragma once
#ifndef CAVE_SPRITE_H
#define CAVE_SPRITE_H

#include <string>
#include <SDL/SDL.h>
#include "Graphics.h"

class Sprite {
public:
    Sprite(Graphics &graphics,
            const std::string& file_path,
            int source_x, int source_y,
            int width, int height);
    virtual ~Sprite(){}
    virtual void Update(int /*elapsed_time_ms*/){}
    void Draw(Graphics& graphics, int x, int y);
protected:
    SDL_Rect source_rect_;
private:
    SDL_Surface* sprite_sheet_;
};


#endif //CAVE_SPRITE_H
