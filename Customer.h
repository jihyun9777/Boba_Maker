#ifndef SFML_PROJECT_CUSTOMER_H
#define SFML_PROJECT_CUSTOMER_H
#include <iostream>
#include <map>
#include "Favorite.h"

class Customer {
public:
    Customer();
    bool findCustomer(std::string name, std::string number);
    bool findFavorite(std::string number);
    void insertCustomer(std::string name, std::string number);
    void insertFavorite(std::string number, Favorite f);

    Favorite getFavorite(std::string number);

    std::map<std::string, std::string> customers;
    std::map<std::string, Favorite> favorites;
};


#endif //SFML_PROJECT_CUSTOMER_H
