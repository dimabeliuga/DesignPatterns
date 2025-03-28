#ifndef TEXTURE_FACTORY_H
#define TEXTURE_FACTORY_H

#include "Texture.h"
#include <unordered_map>
#include <string>
#include <memory>


class TextureFactory
{
    private:
        std::unordered_map<std::string, std::shared_ptr<Texture>> textures;
        //Singleton pattern
        TextureFactory() = default;
    public:

        TextureFactory(const TextureFactory&) = delete;
        TextureFactory& operator=(const TextureFactory&) = delete;
        
        static TextureFactory& getInstance();

        void addTexture(std::string pathToFileWithTexture);
        std::shared_ptr<Texture> getTexture(std::string pathToFileWithTexture) const;
        size_t getTexturesCount() const;

        ~TextureFactory() = default;
        
};

#endif // TEXTURE_FACTORY_H

/* example usage

void addTextures(TextureFactory& textureFactory) {
    textureFactory.addTexture("texture1.png");
    textureFactory.addTexture("texture2.png");
    textureFactory.addTexture("texture3.png");
    textureFactory.addTexture("texture1.png");
    textureFactory.addTexture("texture2.png");
    textureFactory.addTexture("texture3.png");
    textureFactory.addTexture("texture1.png"); // Should not add again
    textureFactory.addTexture("texture2.png"); // Should not add again
    textureFactory.addTexture("texture2.png"); // Should not add again
    textureFactory.addTexture("texture3.png"); // Should not add again
    textureFactory.addTexture("texture3.png"); // Should not add again
    textureFactory.addTexture("texture1.png"); // Should not add again
    textureFactory.addTexture("texture2.png"); // Should not add again
    textureFactory.addTexture("texture3.png"); // Should not add again
}

int main() {
    TextureFactory& textureFactory = TextureFactory::getInstance();
    addTextures(textureFactory);
    std::cout << "Textures count: " << textureFactory.getTexturesCount() << std::endl;

    Animation animation;
    animation.setFrameSpeed(2);
    animation.addFrame(textureFactory.getTexture("texture1.png"));
    animation.addFrame(textureFactory.getTexture("texture2.png"));
    animation.addFrame(textureFactory.getTexture("texture3.png"));
    std::cout << "Frame speed: " << animation.getSpeed() << std::endl;
    animation.setFrameSpeed(4);
    std::cout << "Frame speed: " << animation.getSpeed() << std::endl;
    
    std::shared_ptr<Texture> frame = animation.getFrame(22);

    if (frame) {
        frame->showTexture(10, 20, 100, 200, 45.0);
    } else {
        std::cerr << "Failed to get frame" << std::endl;
    }

    Sprite sprite(10, 20, 100, 200, 45.0, std::make_shared<Animation>(animation));

    sprite.displaySprite(22);

    std::shared_ptr<Animation> newAnimation = std::make_shared<Animation>();
    newAnimation->setFrameSpeed(3);
    newAnimation->addFrame(textureFactory.getTexture("texture1.png"));
    newAnimation->addFrame(textureFactory.getTexture("texture2.png"));
    newAnimation->addFrame(textureFactory.getTexture("texture3.png"));
    textureFactory.addTexture("texture4.png");
    newAnimation->addFrame(textureFactory.getTexture("texture4.png"));
    textureFactory.addTexture("texture5.png");
    newAnimation->addFrame(textureFactory.getTexture("texture5.png"));

    
    sprite.setAnimation(newAnimation);
    sprite.displaySprite(11);
    sprite.displaySprite(66);
    sprite.displaySprite(144);
    sprite.displaySprite(230);

    return 0;
}
*/