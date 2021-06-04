#ifndef TREASURE_H
#define TREASURE_H

#include "item.h"

#include <string> 

class Treasure : public Item
{
public:
    Treasure(std::string name):Item(name){};
    Treasure(const Item& other):Item(other){};
    ~Treasure() override { };
    std::string getType() const override { return "treasure"; };
};

#endif // TREASURE_H
