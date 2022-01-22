#include "Typing.h"

Typing::Typing()
{
    s = "";
    text.setFillColor(sf::Color::Black);
    text.setCharacterSize(25);
    text.setFont(Fonts::getFonts());
}

void Typing::reset()
{
    s = "";
    text.setString(s);
}

void Typing::setPosition(sf::Vector2f v)
{
    text.setPosition(v);
}

sf::FloatRect Typing::getBound()
{
    //return word.getBound();
    return text.getGlobalBounds();
}

std::string Typing::getString()
{
    return s;
}

bool Typing::isEmpty() const
{
    return s.empty();
}

void Typing::addEventHandler (sf::RenderWindow& window, sf::Event event)
{
    if (isEnabled(TYPE) && event.type == sf::Event::TextEntered)
    {
        if (Shortcuts::isUndo() || Shortcuts::isDelete())
        {
            //snap = History::topHistory();
            //History::popHistory();
            s = s.substr(0,s.length() - 1);
            text.setString(s);
            //word.removeWord();
        }
        else if (Shortcuts::isEnter())
        {
            //word.enableState(NEWLINE);
        }
        else
        {
            //snap.addSnap(s);
            sf::String c = event.text.unicode;
            //History::pushHistory(snap);
            s += c;
            text.setString(s);
            //word.addWord(c);
        }
        enableState(ENTERED);
        //word.addEventHandler(window,event);
    }
}

void Typing::draw (sf::RenderTarget& window, sf::RenderStates states) const
{
    //window.draw(word);
    window.draw(text);
}

Snapshot& Typing::getSnapshot()
{
    return snap;
}
