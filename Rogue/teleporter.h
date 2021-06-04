#ifndef TELEPORTER_H
#define TELEPORTER_H

#include "item.h"

class Teleporter : public Item
{
public:
    Teleporter(std::string name):Item(name){};
    Teleporter(const Item& other):Item(other){};
    ~Teleporter() override { };
    std::string getType() const override { return "teleporter"; };

};

#endif // TELEPORTER_H
