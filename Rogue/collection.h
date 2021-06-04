#ifndef COLLECTION_H
#define COLLECTION_H

#include "item.h"

class Collection
{
protected:
    int MAXITEMS;
    int numItems;
    Item** items;
public:
    Collection(int MAXITEMS);
    virtual ~Collection();
    bool addItem(Item* const item);
    Item* removeItem(const std::string itemName);
    bool isFull() const;
    virtual void printItems() const = 0;
    bool contains(std::string itemName) const;

};

#endif // COLLECTION_H
