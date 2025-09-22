
#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item{
    public:
        std::string name;
        std::string type;
        int value;

        Item(std::string n, std::string t, int v);
       
};

#endif