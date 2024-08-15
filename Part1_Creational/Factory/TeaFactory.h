//
// Created by 18030 on 2024/6/30.
//

#ifndef FACTORY_TEAFACTORY_H
#define FACTORY_TEAFACTORY_H

#include "HotDrinkFactory.h"
#include "Tea.h"

class TeaFactory : public HotDrinkFactory
{
public:
    unique_ptr<HotDrink> make() const override
    {
        return make_unique<Tea>();
    }
};


#endif //FACTORY_TEAFACTORY_H
