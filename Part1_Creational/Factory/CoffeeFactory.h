//
// Created by 18030 on 2024/6/30.
//

#ifndef FACTORY_COFFEEFACTORY_H
#define FACTORY_COFFEEFACTORY_H

#include "HotDrinkFactory.h"
#include "Coffee.h"

class CoffeeFactory : public HotDrinkFactory
{
public:
    unique_ptr<HotDrink> make() const override
    {
        return make_unique<Coffee>();
    }
};


#endif //FACTORY_COFFEEFACTORY_H
