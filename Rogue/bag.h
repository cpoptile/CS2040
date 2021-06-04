#ifndef BAG_H
#define BAG_H

class Collection;
#include "collection.h"

#include <string>

class Bag : public Collection
{
public:
    Bag();
    void printItems() const override;
    void printTreasure() const;
    std::string getTeleporterName() const;
    bool hasKey() const;

};

#endif // BAG_H
