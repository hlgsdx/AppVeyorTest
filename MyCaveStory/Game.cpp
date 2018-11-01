#include "Game.h"

namespace {
    const int kFps = 60;
}
//static
int Game::kTileSize = 32;

Game::Game() {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_ShowCursor(SDL_DISABLE);
    eventLoop();

}

Game::~Game() {
    SDL_Quit();

}

void Game::eventLoop() {
    SDL_Event event;
    Graphics graphics;
    Input input;
    player_.reset(new Player(graphics, 320, 240));
    bool running = true;
    int last_update_time = SDL_GetTicks();
    while (running) {
        const int start_time_ms = SDL_GetTicks();
        input.beginNewFrame();
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_KEYDOWN:
                    input.keyDownEvent(event);
//                    if (event.key.keysym.sym == SDLK_ESCAPE)
//                        running = false;
                    break;
                case SDL_KEYUP:
                    input.keyUpEvent(event);
                    break;
                default:
                    break;
            }
        }
        if (input.wasKeyPressed(SDLK_ESCAPE))
            running = false;
		if (input.isKeyHeld(SDLK_LEFT)&&input.isKeyHeld(SDLK_RIGHT))
		{
			player_->stopMoving();
		}
		else if (input.isKeyHeld(SDLK_LEFT)) {
			player_->startMovingLeft();
			//std::cout << "Moving left..." << std::endl;

		}
		else if (input.isKeyHeld(SDLK_RIGHT)) {
			player_->startMovingRight();
			//std::cout << "Moving right..." << std::endl;

		}
		else {
			player_->stopMoving();
		}
        const int current_time_ms = SDL_GetTicks();
        update(current_time_ms - last_update_time);
        last_update_time = current_time_ms;
        draw(graphics);
        const int end_time_ms = SDL_GetTicks();
        const int elapsed_time_ms = end_time_ms - start_time_ms;

        if (elapsed_time_ms > (1000 / kFps)) continue;
        SDL_Delay(1000/*ms*/ / kFps /*fps*/ - elapsed_time_ms /*ms*/);
// 		const float seconds_per_frame = (SDL_GetTicks() - start_time_ms) / 1000.0;
// 		const float fps = 1 / seconds_per_frame;
// 		printf("fps=%f\n", fps);
    }
}

void Game::update(int elapsed_time_ms) {
    player_->update(elapsed_time_ms);
}

void Game::draw(Graphics &graphics) {
	graphics.clear();
    player_->draw(graphics);
    graphics.flip();
}
