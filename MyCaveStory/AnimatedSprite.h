#pragma once
#ifndef CAVE_ANIMATESPRITE_H
#define CAVE_ANIMATESPRITE_H
#include "Game.h"
#include "Sprite.h"
class AnimatedSprite : public Sprite {
public:
    AnimatedSprite(Graphics &graphics, const std::string &file_path,
                  int source_x, int source_y,
                  int width, int height,
                  int fps, int num_frames);
    void Update(int elapsed_time_ms) override;
private:
    const int frame_time_; //每一frame所需时间(1000/fps)
    const int num_frames_; //动画有几frame
    int current_frame_; //当前frame
    int elapsed_time_; //经过时间
};
#endif //CAVE_ANIMATESPRITE_H
