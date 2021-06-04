#ifndef EXIT_H
#define EXIT_H

#include "item.h"
#include <string>


class Exit : public Item
{
public:
    Exit(std::string name):Item(name){};
    Exit(const Item& other):Item(other){};
    ~Exit() override { };
    std::string getType() const override { return "exit"; };
};

#endif // EXIT_H
