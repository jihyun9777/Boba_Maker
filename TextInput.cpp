#include "TextInput.h"

TextInput::TextInput()
{
    label.setString("First Name: ");
    label.setSize(MultiText::textSize);
    box.setSize({400, float(MultiText::textSize) + 10});
    box.setPosition({5, float(MultiText::textSize) + 10});
    c.setPosition(box.getPosition());
}

void TextInput::reset()
{
    text.reset();
    c.setPosition(box.getPosition());
}

void TextInput::setString(std::string s)
{
    label.setString(s);
}

void TextInput::setPosition(sf::Vector2f v)
{
    label.setPosition(v);
    box.setPosition({v.x, v.y + 35});
    c.setPosition(box.getPosition());
    text.setPosition({box.getPosition().x + 5, box.getPosition().y});
}

std::string TextInput::getString()
{
    return text.getString();
}

bool TextInput::isEmpty() const
{
    return text.isEmpty();
}

void TextInput::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
    //Blinking Cursor, Increment Typing
    sf::FloatRect rect (box.getBound());
    if (MouseEvents<sf::FloatRect>::mouseClicked(rect, window))
    {
        c.enableState(BLINK);
        text.enableState(TYPE);
    }
    else if (MouseEvents<TextBox>::mouseClicked(window, event))
    {
        c.disableState(BLINK);
        text.disableState(TYPE);
    }
    text.addEventHandler(window, event);

    //moving cursor
    if (text.isEnabled(ENTERED))
    {
        c.moveCursor({text.getBound().left + text.getBound().width + 2,text.getBound().top - 5});
        text.disableState(ENTERED);
    }

    //increase box size and move cursor when Enter key is pressed
    if (Shortcuts::isEnter())
    {
        c.moveCursor({10,float((MultiText::newLine + 1) * MultiText::gap)});
        box.setSize({400, float((MultiText::newLine + 1) * MultiText::gap)});
    }
}

void TextInput::update()
{
    c.update();
}

void TextInput::draw (sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(label);
    window.draw(box);
    window.draw(c);
    window.draw(text);
}

