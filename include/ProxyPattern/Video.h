#ifndef VIDEO_H
#define VIDEO_H

#include <string>

//* Abstract class for main Video player and Proxy Video Player
class Video {
    public:
        virtual void playVideo(std::string url) const = 0;
        virtual std::string getVideoName(std::string url) const = 0;
        virtual size_t getVideoDuration(std::string url) const = 0;
        virtual std::string getAuthorInfo(std::string url) const = 0;
        virtual std::string getVideoDescription(std::string url) const = 0;
        virtual ~Video() = default;
};

#endif // VIDEO_H