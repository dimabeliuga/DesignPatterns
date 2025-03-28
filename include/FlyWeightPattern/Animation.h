#ifndef ANIMATION_H
#define ANIMATION_H

#include "Texture.h"
#include <vector>
#include <memory>

class Animation
{
    private:
        std::vector<std::shared_ptr<Texture>> frames;
        size_t frameSpeed;
    public:
        Animation() : frameSpeed(1) {};
        explicit Animation(size_t _frameSpeed) : frameSpeed(_frameSpeed) {}

        void addFrame(std::shared_ptr<Texture> texture);
        void setFrameSpeed(size_t speed);
        std::shared_ptr<Texture> getFrame(size_t time) const;
        size_t getSpeed() const;
        ~Animation() = default;
};
#endif // ANIMATION_H