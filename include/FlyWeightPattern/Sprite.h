#ifndef SPRITE_H
#define SPRITE_H

#include "Animation.h"
#include <iostream>
#include <memory>

class Sprite {
    private:
        int X;
        int Y;
        size_t width;
        size_t height;
        double angel;
        size_t animationTime;
        std::shared_ptr<Animation> animation;
    public:
        Sprite(int _X, int _Y, size_t _width, size_t _height, double _angel, std::shared_ptr<Animation> _animation);
        void showSprite();
        void updateTime(size_t newTime);
        void displaySprite(size_t time);
        void setAnimation(std::shared_ptr<Animation> _animation);
};

#endif // SPRITE_H