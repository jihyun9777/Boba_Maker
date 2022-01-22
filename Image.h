#ifndef SFML_PROJECT_IMAGE_H
#define SFML_PROJECT_IMAGE_H
#include <iostream>
#include <SFML/Graphics.hpp>

class Image {
public:
    enum image {FOLDER, FILE, CUP, LESS, REGUL, EXTRA, BOBA, PEARL, ALOE,
                BOBA1, BOBA2, BOBA3, BOBA4, BOBA5, BOBASHOP, TITLE};
    static sf::Texture texture;
    static std::map<image, sf::Texture> images;
    static std::map<image, bool> loaded;
    static void loadImage(image image);
    static std::string getImagePath(image image);
    static sf::Texture& getImage(image image);
};


#endif //SFML_PROJECT_IMAGE_H
