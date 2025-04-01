#ifndef REAL_VIDEO_SERVICE_H
#define REAL_VIDEO_SERVICE_H

#include "Video.h"
#include <string>
#include <iostream>

class VideoService : public Video {
    private:
        //* these functions will be immitate the VideoService work. Let's imagine these funcitons sending crypted datas as the responce
        std::string randomText(size_t length, const std::string key) const;
        size_t getRandomNumber(size_t min, size_t max) const;
    public:
        VideoService() = default;
        void playVideo(std::string url) const override;
        std::string getVideoName(std::string url) const override;
        size_t getVideoDuration(std::string url) const override;
        std::string getAuthorInfo(std::string url) const override;
        std::string getVideoDescription(std::string url) const override;
};

#endif // REAL_VIDEO_SERVICE_H