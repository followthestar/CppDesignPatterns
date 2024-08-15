//
// Created by 18030 on 2024/6/30.
//

#ifndef FACTORY_DRINKFACTORY_H
#define FACTORY_DRINKFACTORY_H

#include "TeaFactory.h"
#include "CoffeeFactory.h"
#include <map>
#include <string>
#include <functional>

class DrinkFactory
{
    map<string, unique_ptr<HotDrinkFactory>> hot_factories;
public:
    DrinkFactory()
    {
        hot_factories["coffee"] = make_unique<CoffeeFactory>();
        hot_factories["tea"] = make_unique<TeaFactory>();
    }

    unique_ptr<HotDrink> make_drink(const string& name)
    {
        auto drink = hot_factories[name]->make();
        drink->prepare(200);
        return drink;
    }
};

//函数式工厂 - 将对产品的附加操作打包进函数存放在工厂中
class DrinkWithVolumeFactory
{
    //值类型为“直接返回最终产品”的函数
    map<string, function<unique_ptr<HotDrink>()>> factories;
public:
    DrinkWithVolumeFactory()
    {
        factories["tea"] = []
        {
            auto tea = make_unique<Tea>();
            tea->prepare(200);
            return tea;
        };

        factories["coffee"] = []
        {
            auto tea = make_unique<Coffee>();
            tea->prepare(200);
            return tea;
        };
    }

    inline unique_ptr<HotDrink> make_drink(const string& name)
    {
        return factories[name]();
    }
};


#endif //FACTORY_DRINKFACTORY_H
