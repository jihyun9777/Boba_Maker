#include "FileItem.h"

sf::Vector2f FileItem::boxSize = {200, 45};

FileItem::FileItem()
{
    icon.setTexture(Image::getImage(Image::FILE));
    box.setPosition({0, 0});
    title.setString("Example");
    box.setSize(boxSize);
    iconInit();
}

FileItem::FileItem(Image::image i, std::string text, sf::Vector2f size, sf::Vector2f position)
{
    setIcon(i);
    s = text;
    title.setString(s);
    box.setSize(size);
    iconInit();
    setPosition(position);
}

FileItem::FileItem(std::string text, sf::Vector2f size, sf::Vector2f position)
{
    s = text;
    title.setString(s);
    box.setSize(size);
    box.setPosition(position);
    title.setPosition({position.x + 10, position.y + 10});
}

void FileItem::setPosition(sf::Vector2f v)
{
    icon.setPosition(v);
    box.setPosition(v);
    //setting the title right next to icon
    sf::FloatRect box = icon.getGlobalBounds();
    title.setPosition({box.left + box.width,box.top + 10});
}
//Initialize Icon scale;
void FileItem::iconInit()
{
    float scale = box.getBound().height/icon.getGlobalBounds().height;
    icon.setScale(scale, scale);
}

void FileItem::setIcon(Image::image i)
{
    icon.setTexture(Image::getImage(i));
}

void FileItem::setString(std::string s)
{
    title.setString(s);
}

sf::FloatRect FileItem::getBound() const
{
    return box.getBound();
}

sf::Vector2f FileItem::getPosition() const
{
    return box.getPosition();
}

std::string FileItem::getString() const
{
    return s;
}

void FileItem::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
    sf::FloatRect rect = box.getBound();
    if (MouseEvents<sf::FloatRect>::mouseClicked(rect, window))
        box.setColor(sf::Color::Green);
    else if (MouseEvents<RectBox>::mouseClicked(window, event))
        box.setColor(sf::Color::White);
/*
    if(isEnabled(CLICK))
        box.setColor(sf::Color::Green);
    else
        box.setColor(sf::Color::Black);
*/
}

void FileItem::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(box);
    window.draw(icon);
    window.draw(title);
}
