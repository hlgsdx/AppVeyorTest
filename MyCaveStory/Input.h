#pragma once
#ifndef CAVE_INPUT_H
#define CAVE_INPUT_H

#include <map>
#include <SDL/SDL.h>
using std::map;
class Input {
public:
    void beginNewFrame();
    void keyDownEvent(const SDL_Event& event);
    void keyUpEvent(const SDL_Event& event);
    bool wasKeyPressed(SDLKey key);
    bool wasKeyReleased(SDLKey key);
    bool isKeyHeld(SDLKey key);
private:
    map<SDLKey,bool> held_keys_;
    map<SDLKey,bool> pressed_keys_;
    map<SDLKey,bool> released_keys_;

};


#endif //CAVE_INPUT_H
