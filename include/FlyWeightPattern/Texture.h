#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>

class Texture
{
    private:
        std::string pathToFileWithTexture;
    public:
        explicit Texture(const std::string& _pathToFileWithTexture);
        std::string getTextureName();
        // void loadTextureFile(std::string pathToFile);
        void showTexture(int32_t X, int32_t Y, int32_t width, int32_t height, double angel) const;
        ~Texture() = default;
};

#endif // TEXTURE_H