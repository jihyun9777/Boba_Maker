#include "DrinkTree.h"

sf::RenderWindow DrinkTree::treeWindow(sf::VideoMode(500, 500, 32), "Tree");

DrinkTree::DrinkTree()
{
    tree.push("Drink", "Size");
    tree.push("Drink", "Flavor");
    tree.push("Drink", "Topping");
    tree.push("Drink", "Ice");

    exit.setString("Exit");
    exit.setPosition({380, 440});
    exit.setStringPosition({400, 445});
    exit.setSize({100, 40});
}

void DrinkTree::addItem(std::string s, std::string f, std::string t, std::string i)
{
    tree.push("Size", s);
    tree.push("Flavor", f);
    tree.push("Topping", t);
    tree.push("Ice", i);
}

void DrinkTree::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
    while(treeWindow.isOpen())
    {
        sf::Event event;
        while (treeWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                treeWindow.close();
            tree.addEventHandler(treeWindow, event);
            exit.addEventHandler(treeWindow, event);

            if(exit.isEnabled(BUTTON))
                treeWindow.close();
        }

        exit.update();
        treeWindow.clear(sf::Color::White);

        treeWindow.draw(exit);
        treeWindow.draw(tree);
        treeWindow.display();
    }
}