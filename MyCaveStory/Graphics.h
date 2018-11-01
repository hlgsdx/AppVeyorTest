#pragma once
#ifndef CAVE_GRAPHICS_H
#define CAVE_GRAPHICS_H


#include <SDL/SDL.h>
#include <map>
#include <string>
class Graphics {
public:
	typedef SDL_Surface* SurfaceID;
    Graphics();
    ~Graphics();
    void blitSurface(SurfaceID source,
                     SDL_Rect* source_rectangle,
                     SDL_Rect* destination_rectangle);
    void flip();
	void clear();
	SurfaceID loadImage(const std::string& file_path);
private:
    typedef std::map<std::string, SurfaceID> SpriteMap;
    SDL_Surface* screen_;
    SpriteMap sprite_sheets_;
};


#endif //CAVE_GRAPHICS_H
