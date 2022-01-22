#include <SFML/Graphics.hpp>
#include "LogIn.h"
#include "DrinkMain.h"
#include "Customer.h"
#include "Option.h"
#include "DrinkTree.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1500, 900, 32), "Test");

    LogIn logIn;
    DrinkMain drinkMain;
    Customer customer;
    Option option;
    DrinkTree tree;

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
            if(logIn.isEnabled(LOGIN))
            {
                option.firstTime(logIn.getName());
                option.addEventHandler(window,event);

                //Create New Boba
                if(option.isEnabled(CREATE))
                {
                    drinkMain.enableState(LOGIN);
                    customer.insertCustomer(logIn.getName(), logIn.getNumber());
                    drinkMain.addEventHandler(window, event);

                    if(drinkMain.isEnabled(FAVORITE))
                    {
                        customer.insertFavorite(logIn.getNumber(), drinkMain.favorite);
                    }

                    if (!drinkMain.isEnabled(LOGIN))
                    {
                        option.disableState(CREATE);
                        logIn.disableState(LOGIN);
                        drinkMain.reset();
                        logIn.reset();
                    }
                }
                //Show my Favorite
                else if(option.isEnabled(FAVORITE))
                {
                    if(customer.findCustomer(logIn.getName(), logIn.getNumber()))
                    {
                        if (customer.findFavorite(logIn.getNumber())) {
                            drinkMain.setFavorite(customer.getFavorite(logIn.getNumber()));
                            drinkMain.enableState(LOGIN);
                            drinkMain.addEventHandler(window, event);
                        }
                    }
                    else
                    {
                        drinkMain.reset();
                        drinkMain.enableState(LOGIN);
                        drinkMain.addEventHandler(window, event);
                    }
                    if (!drinkMain.isEnabled(LOGIN))
                    {
                        option.disableState(FAVORITE);
                        logIn.disableState(LOGIN);
                        drinkMain.reset();
                        logIn.reset();
                    }
                }
                //Show History
                else if(option.isEnabled(HISTORY))
                {
                    if(drinkMain.isEnabled(PAY))
                    {
                        tree.addItem(drinkMain.s, drinkMain.f, drinkMain.t, drinkMain.i);
                        tree.addEventHandler(window, event);
                    }
                }
            }
            if(!logIn.isEnabled(LOGIN))
                logIn.addEventHandler(window, event);
        }

        if(logIn.isEnabled(LOGIN) && drinkMain.isEnabled(LOGIN))
        {
            drinkMain.update();
        }
        else if(logIn.isEnabled(LOGIN))
            option.update();
        else
            logIn.update();
        window.clear(sf::Color::Yellow);

        if(logIn.isEnabled(LOGIN) && drinkMain.isEnabled(LOGIN))
        {
            window.draw(drinkMain);
        }
        else if(logIn.isEnabled(LOGIN))
            window.draw(option);
        else
            window.draw(logIn);
        window.display();
    }

    return 0;
}
