#include "Payment.h"

sf::RenderWindow Payment::payment(sf::VideoMode(500, 500, 32), "Pay");

Payment::Payment()
{
    line.setFillColor(sf::Color::Black);
    line.setSize({400, 2});
    line.setPosition({5, 170});

    size.setPosition({5, 0});
    flavor.setPosition({5, 40});
    topping.setPosition({5,80});
    ice.setPosition({5, 120});
    total.setPosition({5, 180});
    total.setString("TOTAL: ");

    sizeCost.setPosition({200, 0});
    flavorCost.setPosition({200, 40});
    toppingCost.setPosition({200,80});
    totalCost.setPosition({200, 180});

    pay.setString("Pay");
    pay.setPosition({380, 380});
    pay.setStringPosition({400, 385});
    pay.setSize({100, 40});

    exit.setString("Exit");
    exit.setPosition({380, 440});
    exit.setStringPosition({400, 445});
    exit.setSize({100, 40});
}

void Payment::setItem(std::string s, std::string f, std::string t, std::string i)
{
    size.setString(s);
    flavor.setString(f);
    topping.setString(t);
    ice.setString(i);
}

void Payment::setCost(std::string s, std::string f, std::string t, std::string tot)
{
    sizeCost.setString("$ " + s);
    flavorCost.setString("$ " + f);
    toppingCost.setString("$ " + t);
    totalCost.setString("$ " + tot);
}

void Payment::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
    while(payment.isOpen())
    {
        sf::Event event;
        while (payment.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                payment.close();
            pay.addEventHandler(payment, event);
            exit.addEventHandler(payment, event);

            if(pay.isEnabled(BUTTON))
            {
                enableState(PAY);
                payment.close();
            }
            if(exit.isEnabled(BUTTON))
                payment.close();
        }

        pay.update();
        exit.update();
        payment.clear(sf::Color::White);

        payment.draw(size);
        payment.draw(flavor);
        payment.draw(topping);
        payment.draw(ice);
        payment.draw(line);
        payment.draw(total);

        payment.draw(sizeCost);
        payment.draw(flavorCost);
        payment.draw(toppingCost);
        payment.draw(totalCost);

        payment.draw(pay);
        payment.draw(exit);
        payment.display();
    }
}
