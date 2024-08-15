//
// Created by 18030 on 2024/6/30.
//

#ifndef FACTORY_HOTDRINK_H
#define FACTORY_HOTDRINK_H

#include "iostream"

using namespace std;

struct HotDrink
{
    virtual void prepare(int volume) = 0;

    virtual ~HotDrink() = default;
};


#endif //FACTORY_HOTDRINK_H
