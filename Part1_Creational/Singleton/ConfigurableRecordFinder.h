//
// Created by 18030 on 2024/7/4.
//

#ifndef SINGLETON_CONFIGURABLERECORDFINDER_H
#define SINGLETON_CONFIGURABLERECORDFINDER_H

//这里，我们仅依赖顶层接口
#include "Database.h"

#include <vector>
#include <string>

using namespace std;

struct ConfigurableRecordFinder
{
    explicit ConfigurableRecordFinder(Database& db) : db(db) {}

    int total_population(const vector<string>& names)
    {
        int result = 0;
        for (auto& name : names)
        {
            result += db.get_population(name);
        }
        return result;
    }
    Database& db;
};


#endif //SINGLETON_CONFIGURABLERECORDFINDER_H
