#include "Animation.h"
#include <iostream>
#include <cassert>
void Animation::addFrame(std::shared_ptr<Texture> texture)
{
    if(texture == nullptr) {
        std::cerr << "Error: Attempted to add a null texture to the animation." << std::endl;
        return;
    }
    frames.push_back(texture);
}

void Animation::setFrameSpeed(size_t speed)
{
    frameSpeed = speed;
}

std::shared_ptr<Texture> Animation::getFrame(size_t time) const
{
    assert((frames.size() != 0) && "No frames in the animation");
    assert((frameSpeed > 0) && "Frame speed is 0");

    int32_t frameIndex = (time * frameSpeed) % frames.size();
    std::cout << "Frame index: " << frameIndex << std::endl;
    return frames.at(frameIndex);
}

size_t Animation::getSpeed() const
{
    return frameSpeed;
}
