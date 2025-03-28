#include "TextureFactory.h"
#include <iostream>


TextureFactory &TextureFactory::getInstance()
{
    static TextureFactory instance;
    return instance;
}

void TextureFactory::addTexture(std::string pathToFileWithTexture)
{
    auto texture = textures.find(pathToFileWithTexture);
    if (texture == textures.end())
    {
        std::shared_ptr<Texture> newTexture = std::make_shared<Texture>(pathToFileWithTexture);
        textures[pathToFileWithTexture] = newTexture;
        std::cout << "The texture was added successfully" << std::endl;
    }
    else
    {
        std::cerr << "The texture already exists" << std::endl;
    }
}

std::shared_ptr<Texture> TextureFactory::getTexture(std::string pathToFileWithTexture) const
{
    auto texture = textures.find(pathToFileWithTexture);
    if (texture == textures.end())
    {
        std::cerr << "The texture was not found" << std::endl;
        // throw std::runtime_error("The texture was not found");
        return nullptr;
    }
    return texture->second;
}

size_t TextureFactory::getTexturesCount() const
{
    return textures.size();
}