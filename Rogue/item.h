#ifndef ITEM_H
#define ITEM_H

#include <string> 

class Item
{
private:
    std::string name;
public:
    Item() {name = "";};
    Item(std::string itemName) {name = itemName;} ;
    Item(const Item& other) {name = other.getName();};
    virtual ~Item() { };
    std::string getName() const { return name; };
    virtual std::string getType() const { return "item"; };
};

#endif // ITEM_H
