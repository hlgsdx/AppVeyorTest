#include "Player.h"

namespace {
	const float kSlowdownFactor = 0.8f;
	const float kWalkingAcceleration = 0.0012f;		//pixels/ms/ms
	const float kMaxSpeedX = 0.325f;				//pixels/ms
}
Player::Player(Graphics &graphics, int x, int y):
	x_(x),
	y_(y),
	acceleration_x_(0.0f),
	velocity_x_(0.0f)
{
	sprite_.reset(new AnimatedSprite(graphics, "content/MyChar.bmp", 0, 0, Game::kTileSize, Game::kTileSize, 15, 3));
}

Player::~Player()
{
}

void Player::update(int elapsed_time_ms)
{
	sprite_->Update(elapsed_time_ms);
	x_ += (int)round(velocity_x_ * elapsed_time_ms);
	velocity_x_ += acceleration_x_ * elapsed_time_ms;
	if (acceleration_x_<0.0f)
	{
		velocity_x_ = fmaxf(-kMaxSpeedX, velocity_x_);
	}
	else if (acceleration_x_ > 0.0f) {
		velocity_x_ = fminf(kMaxSpeedX, velocity_x_);
	}
	else {
		velocity_x_ *= kSlowdownFactor;
	}
}

void Player::draw(Graphics &graphics)
{
	sprite_->Draw(graphics, x_, y_);
}
void Player::startMovingLeft() {
	acceleration_x_ = -kWalkingAcceleration;
}
void Player::startMovingRight() {
	acceleration_x_ = kWalkingAcceleration;

}
void Player::stopMoving() {
	acceleration_x_ = 0.0f;
}