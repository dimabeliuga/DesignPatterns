#include "Texture.h"
#include <iostream>

Texture::Texture(const std::string& _pathToFileWithTexture)
    : pathToFileWithTexture (_pathToFileWithTexture)
{
    std::cout << "The texture was loaded successfully" << std::endl;
}

std::string Texture::getTextureName()
{
    std::cout << "The texture name is: " << pathToFileWithTexture << std::endl;
    return pathToFileWithTexture;
}
/* 
void Texture::loadTextureFile(std::string pathToFile)
{
    std::cout << "The texture file was loaded successfully" << std::endl;
    pathToFileWithTexture = pathToFile;
} */

void Texture::showTexture(int32_t X, int32_t Y, int32_t width, int32_t height, double angel) const
{
    std::cout << "The texture was shown at X: " << X << " Y: " << Y << " width: " << width << " height: " << height << " angel: " << angel << std::endl;
}