#include "FileNode.h"

FileNode::FileNode() {}

FileNode::FileNode(Image::image icon, std::string text, sf::Vector2f size, sf::Vector2f position)
: item(icon, text, size, position) {}

FileNode::FileNode(std::string text, sf::Vector2f size, sf::Vector2f position)
        : item(text, size, position) {}

void FileNode::setItem(const FileItem &data)
{
    FileNode::item = data;
}

void FileNode::setString(const std::string s)
{
    item.setString(s);
}

FileItem& FileNode::getItem()
{
    return item;
}

std::vector<FileNode*>& FileNode::getChildren()
{
    return children;
}

sf::FloatRect FileNode::getBound() const
{
    sf::FloatRect bound = item.getBound();
    if(isEnabled(SHOWCHILD))
    {
        bound.width += 40;
        for(auto iter = children.begin(); iter != children.end(); ++iter)
            bound.height += (*iter)->item.getBound().height;
    }
    return bound;
}

bool FileNode::isLeaf() const
{
    return children.empty();
}

void FileNode::toggleChlidren()
{
    if(!isEnabled(SHOWCHILD))
        enableState(SHOWCHILD);
    else
        disableState(SHOWCHILD);
}

void FileNode::reposition() const
{/*
    sf::FloatRect box = item.getBound();

    for(int i = 0; i < children.size(); i ++)
    {
        children[i]->item.setPosition({box.left + 40, box.top + box.top * i});
    }
*/

    sf::Vector2f pos= item.getPosition();
    pos.x += 40;
    pos.y = item.getBound().height + item.getBound().top;

    auto iter = children.begin();
    for(; iter != children.end(); ++iter)
    {
        (*iter)->item.setPosition(pos);
        pos.y += (*iter)->getBound().height;
    }

}

void FileNode::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    reposition();
    window.draw(item);
    if(isEnabled(SHOWCHILD))
    {
        for(auto iter = children.begin(); iter != children.end(); ++iter)
            (*iter)->draw(window, states);
    }
}

void FileNode::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
    sf::FloatRect bound = item.getBound();
    if(MouseEvents<sf::FloatRect>::mouseClicked(bound, window))
        toggleChlidren();

    item.addEventHandler(window, event);
    /*
    for(auto iter = begin(); iter != end(); ++iter)
        (*iter)->item.addEventHandler(window, event);
    */
}

typename FileNode::iterator FileNode::begin()
{
    return children.begin();
}

typename FileNode::iterator FileNode::end()
{
    return children.end();
}
