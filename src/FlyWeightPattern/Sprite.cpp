#include "Sprite.h"

Sprite::Sprite(int _X, int _Y, size_t _width, size_t _height, double _angel, std::shared_ptr<Animation> _animation)
    : X(_X), Y(_Y), width(_width), height(_height), angel(_angel), animation(_animation)
{
    animationTime = 0;
}

void Sprite::showSprite()
{
    animation->getFrame(animationTime)->showTexture(X, Y, width, height, angel);
}

void Sprite::updateTime(size_t newTime)
{
    animationTime = newTime;
}

void Sprite::displaySprite(size_t time)
{
    updateTime(time);
    showSprite();
}

void Sprite::setAnimation(std::shared_ptr<Animation> _animation)
{
    if(_animation == nullptr) {
        std::cerr << "Error: Attempted to set a null animation." << std::endl;
        return;
    }

    if(animation == _animation) {
        std::cerr << "Error: Attempted to set the same animation." << std::endl;
        return;
    }
    
    std::cout << "New animation has been set" << std::endl;
    animation = _animation;
}

