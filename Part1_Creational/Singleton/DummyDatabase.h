//
// Created by 18030 on 2024/7/4.
//

#ifndef SINGLETON_DUMMYDATABASE_H
#define SINGLETON_DUMMYDATABASE_H

#include <map>
#include "Database.h"

class DummyDatabase : public Database
{
    map<string, int> capitals;
public:
    DummyDatabase()
    {
        capitals["alpha"] = 1;
        capitals["beta"] = 2;
        capitals["gamma"] = 3;
    }

    int get_population(const string& name) override
    {
        return capitals[name];
    }
};


#endif //SINGLETON_DUMMYDATABASE_H
