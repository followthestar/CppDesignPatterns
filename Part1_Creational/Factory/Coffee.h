//
// Created by 18030 on 2024/6/30.
//

#ifndef FACTORY_COFFEE_H
#define FACTORY_COFFEE_H

#include "HotDrink.h"

struct Coffee : HotDrink
{
    void prepare(int volume) override
    {
        cout << "Take coffee bag, boil water, pour " << volume << "ml, add some sugar" << endl;
    }
};


#endif //FACTORY_COFFEE_H
