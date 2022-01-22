#include "Cursor.h"

CursorEvents::CursorEvents()
{
    line.setSize({3,25});
    line.setFillColor(sf::Color::Black);
}
//initial position
void CursorEvents::setPosition(sf::Vector2<float> v)
{
    line.setPosition({v.x + 5, v.y + 5});
}

sf::Vector2f CursorEvents::getPosition() const
{
    return line.getPosition();
}
//Move cursor
void CursorEvents::moveCursor (sf::Vector2f v)
{
    line.setPosition(v.x, v.y + 5);
}

void CursorEvents::blinkOn ()
{
    if (isEnabled(BLINKON))
        disableState(BLINKON);
    else if (!isEnabled(BLINKON))
        enableState(BLINKON);
}

void CursorEvents::update()
{
    if (isEnabled(BLINK))
    {
        if (clock.getElapsedTime().asMilliseconds() > 500)
        {
            blinkOn();
            clock.restart();
        }
    }
}

void CursorEvents::draw (sf::RenderTarget& window, sf::RenderStates states) const
{
    if (isEnabled(BLINK))
    {
        if (isEnabled(BLINKON))
            window.draw(line);
    }
}