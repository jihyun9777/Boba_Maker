#include "FileTree.h"

sf::FloatRect FileTree::rootBound = {0,0,200,45};

FileTree::FileTree()
{
    root = nullptr;
}

void FileTree::push(std::string parent, std::string item)
{
    push(root, parent, item);
}

sf::FloatRect FileTree::getBound()
{
    sf::FloatRect bound = rootBound;
    if(isEnabled(ROOTCLICK))
    {
        auto iter = root->begin();
        for (; iter != root->end(); ++iter) {
            bound.height += (*iter)->getBound().height;
        }
    }
    return bound;
}

void FileTree::toggle()
{
    if(!isEnabled(ROOTCLICK))
        enableState(ROOTCLICK);
    else
        disableState(ROOTCLICK);
}

void FileTree::setIcon()
{
    auto iter = root->getChildren().begin();
    (*iter)->getItem().setIcon(Image::FILE);
}

void FileTree::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
    traverse(root, window, event);

    if(MouseEvents<sf::FloatRect>::mouseClicked(rootBound, window))
        toggle();
}

void FileTree::push(FileNode*& root, std::string parent, std::string item)
{
    if(root == nullptr)
    {
        root = new FileNode(Image::FILE, parent, FileItem::boxSize, {0,0});
        sf::Vector2f pos = {root->getItem().getBound().left + 40,
                            root->getItem().getBound().top + root->getItem().getBound().height};
        FileNode* n = new FileNode(Image::FILE, item, FileItem::boxSize, pos);
        root->getChildren().push_back(n);
        return;
    }
    if(root->getItem().getString() == parent)
    {
        root->getItem().setIcon(Image::FILE);
        sf::Vector2f pos = {root->getItem().getBound().left + 40,
                            root->getItem().getBound().top + root->getItem().getBound().height};
        FileNode* n = new FileNode(Image::FILE, item, {360,45}, pos);
        root->getChildren().push_back(n);
        return;
    }
    if(root->getChildren().size() > 0)
    {
        auto iter = root->getChildren().begin();
        for (; iter != root->getChildren().end(); ++iter) {
            push(*iter, parent, item);
        }
    }
}

void FileTree::traverse(FileNode* &root, sf::RenderWindow& window, sf::Event event)
{
    if(root == nullptr)
        return;
    root->addEventHandler(window, event);
    auto iter = root->begin();
    for(; iter != root->end(); ++iter)
        traverse(*iter, window, event);
}

void FileTree::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    if(root != nullptr)
        window.draw(*root);
}