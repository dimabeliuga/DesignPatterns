#include "RealVideoService.h"
#include <random>

std::string VideoService::randomText(size_t length, const std::string key) const {
    std::hash <std::string> keyToHash;
    auto seed = static_cast<unsigned int>(keyToHash(key));

    std::mt19937 generator(seed);
    const std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    static std::uniform_int_distribution<size_t> distribution(0, characters.size() - 1);

    std::string result;
    result.reserve(length);

    for (size_t i = 0; i < length; ++i) {
        result += characters[distribution(generator)];
    }

    return result;
}

size_t VideoService::getRandomNumber(size_t min, size_t max) const {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<size_t> distribution(min, max);
    return distribution(generator);
}

void VideoService::playVideo(std::string url) const {
    std::cout << "Playing video from URL: " << url << std::endl;
}

std::string VideoService::getVideoName(std::string url) const {
    return randomText(getRandomNumber(10, 30), url);
}

size_t VideoService::getVideoDuration(std::string url) const {
    return getRandomNumber(1, 1000);
}

std::string VideoService::getAuthorInfo(std::string url) const {
    return randomText(getRandomNumber(10, 20), url);
}

std::string VideoService::getVideoDescription(std::string url) const {
    return randomText(getRandomNumber(10, 40), url);
}


