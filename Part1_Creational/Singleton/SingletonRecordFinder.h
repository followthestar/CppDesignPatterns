//
// Created by 18030 on 2024/7/4.
//

#ifndef SINGLETON_SINGLETONRECORDFINDER_H
#define SINGLETON_SINGLETONRECORDFINDER_H
#include "SingletonDatabase.h"
#include <vector>
#include <string>

using namespace std;

// 这样设计导致的问题就是SingletonRecordFinder会直接地
// 依赖SingletonDatabase，不利于单元测试，还且繁访问活动数据库
struct SingletonRecordFinder
{
    int total_population(vector<string> names)
    {
        int result;
        for (auto& name : names)
        {
            result += SingletonDatabase::get().get_population(name);
        }
        return result;
    }
};


#endif //SINGLETON_SINGLETONRECORDFINDER_H
