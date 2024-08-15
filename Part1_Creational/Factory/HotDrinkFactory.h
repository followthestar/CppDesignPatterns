//
// Created by 18030 on 2024/6/30.
//

#ifndef FACTORY_HOTDRINKFACTORY_H
#define FACTORY_HOTDRINKFACTORY_H

#include <memory>
#include "HotDrink.h"


class HotDrinkFactory
{
public:
    virtual unique_ptr<HotDrink> make() const = 0;

    virtual ~HotDrinkFactory() = default;
};


#endif //FACTORY_HOTDRINKFACTORY_H
