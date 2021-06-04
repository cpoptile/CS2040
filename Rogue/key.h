#ifndef KEY_H
#define KEY_H

#include "item.h"
#include <string>

//inherits from Item
class Key : public Item
{
public:
    //inline methods
    Key(std::string name):Item(name){};
    Key(const Item& other):Item(other){};
    ~Key() override {};
    //override from Item
    std::string getType() const override { return "key"; };
};

#endif // KEY_H
