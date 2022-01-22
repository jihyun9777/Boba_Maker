#include "MultiText.h"

int MultiText::newLine = 1;
int MultiText::gap = 35;
int MultiText::textSize = 25;

MultiText::MultiText()
{
    t.setFillColor(sf::Color::White);
    t.setCharacterSize(textSize);
    t.setFont(Fonts::getFonts());
}

void MultiText::addWord (std::string s)
{
    t.setString(s);

    if (list.empty())
        t.setPosition({10,float(gap)});
    else
    {
        DList<sf::Text>::iterator temp = list.last();
        t.setPosition((*temp).getGlobalBounds().left + (*temp).getGlobalBounds().width, gap*newLine);
    }

    if (isEnabled(NEWLINE))
    {
        newLine += 1;
        t.setPosition(10, gap*newLine);
        disableState(NEWLINE);
    }
    list.InsertTail(t);
}

void MultiText::removeWord ()
{
    if (!list.empty())
        list.RemoveTail();
}

void MultiText::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
    std::string s;
    start = list.begin();
    for (last = list.begin(); last != list.end(); ++last)
    {
        if ((*last).getString() == " ")
        {
            if (Shortcuts::isWord(s))
                color.isColorWord(start, last);
            start = last;
            ++start;
            s = "";
        }
        else if (Shortcuts::isOper((*last)))
            color.isColorOper(last);
        else if (Shortcuts::isNum((*last)))
            color.isColorNum(last);
        else
        {
            s += (*last).getString();
            color.isNotColorWord(start, last);
        }
    }

}

void MultiText::draw (sf::RenderTarget& window, sf::RenderStates states) const
{
    DList<sf::Text>::iterator temp;

    for(temp = getBegin(); temp != getEnd(); ++temp)
    {
        window.draw((*temp));
    }
}

typename DList<sf::Text>::iterator MultiText::getBegin() const
{
    return list.begin();
}

typename DList<sf::Text>::iterator MultiText::getEnd() const
{
    return list.end();
}

sf::FloatRect MultiText::getBound()
{
    if (list.empty())
        return {10,0,0, float(gap)};

    DList<sf::Text>::iterator temp = list.last();
    sf::FloatRect bound = (*temp).getGlobalBounds();
    bound.top = float(gap)*newLine;
    return bound;
}