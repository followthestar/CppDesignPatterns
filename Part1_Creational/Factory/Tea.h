//
// Created by 18030 on 2024/6/30.
//

#ifndef FACTORY_TEA_H
#define FACTORY_TEA_H

#include "HotDrink.h"

struct Tea : HotDrink
{
    void prepare(int volume) override
    {
        cout << "Take tea bag, boil water, pour" << volume << "ml, add some lemon" << endl;
    }
};


#endif //FACTORY_TEA_H
