#include "Image.h"

sf::Texture Image::texture;

std::map<Image::image, sf::Texture> Image::images;

std::map<Image::image, bool> Image::loaded;

sf::Texture& Image::getImage(image image)
{
    if(!loaded[image])
        loadImage(image);
    return images[image];
}

std::string Image::getImagePath(image image)
{
    switch (image)
    {
        case FOLDER: return "folder.png";
        case FILE: return "empty.png";
        case CUP: return "cup.png";
        case LESS: return "less.png";
        case REGUL: return "regul.png";
        case EXTRA: return "extra.png";
        case BOBA: return "boba.png";
        case PEARL: return "pearl.png";
        case ALOE: return "aloe.png";
        case BOBA1: return "boba1.png";
        case BOBA2: return "boba2.png";
        case BOBA3: return "boba3.png";
        case BOBA4: return "boba4.png";
        case BOBA5: return "boba5.png";
        case BOBASHOP: return "bobashop.png";
        case TITLE: return "title.png";
    }
}

void Image::loadImage(image image)
{
    if(!loaded[image])
    {
        if (!images[image].loadFromFile(getImagePath(image)))
            std::cout << "Image load failed." << std::endl;
        loaded[image] = true;
    }
}