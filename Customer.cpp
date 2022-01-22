#include "Customer.h"

Customer::Customer()
{}

bool Customer::findCustomer(std::string name, std::string number)
{
    std::map<std::string, std::string>::iterator iter;
    iter = customers.find(number);
    if(iter != customers.end())
        return true;
    return false;
}

void Customer::insertCustomer(std::string name, std::string number)
{
    if(!findCustomer(name, number))
        customers[number] = name;
}


bool Customer::findFavorite(std::string number)
{
    std::map<std::string, Favorite>::iterator iter;
    iter = favorites.find(number);
    if(iter->second.isEmpty())
        return false;
    return true;
}

void Customer::insertFavorite(std::string number, Favorite f)
{
    favorites[number] = f;
}

Favorite Customer::getFavorite(std::string number)
{
    return favorites.find(number)->second;
}