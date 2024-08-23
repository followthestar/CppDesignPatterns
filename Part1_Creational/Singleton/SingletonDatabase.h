//
// Created by 18030 on 2024/7/1.
//

#ifndef SINGLETON_SINGLETONDATABASE_H
#define SINGLETON_SINGLETONDATABASE_H
#include "Database.h"
#include <map>

class SingletonDatabase : public Database
{
    SingletonDatabase()
    {

    }

    map<string, int> capitals;
public:
    SingletonDatabase(const SingletonDatabase&) = delete;
    void operator=(const SingletonDatabase&) = delete;

    static SingletonDatabase& get()
    {
        static SingletonDatabase db;
        return db;
    }

    int get_population(const string& name) override
    {
        return capitals[name];
    }

};




#endif //SINGLETON_SINGLETONDATABASE_H
