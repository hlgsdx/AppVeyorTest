#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite(Graphics &graphics, const std::string &file_path, int source_x, int source_y, int width, int height, int fps,
                             int num_frames) :
        Sprite(graphics, file_path, source_x, source_y, width, height),
        frame_time_(1000 / fps),
        num_frames_(num_frames),
        current_frame_(0),
        elapsed_time_(0) {

}

void AnimatedSprite::Update(int elapsed_time_ms) {
    elapsed_time_ += elapsed_time_ms;
    if (elapsed_time_ > frame_time_) { //积累经过时间，当其大于每一frame时间时，换下一frame
        ++current_frame_;
        elapsed_time_ = 0;
        if (current_frame_ < num_frames_) {
            source_rect_.x += Game::kTileSize;
        } else {
            source_rect_.x -= Game::kTileSize * (num_frames_ - 1); //还原到第一frame位置
            current_frame_ = 0;
        }
    }
}

