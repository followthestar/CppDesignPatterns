//
// Created by 18030 on 2024/7/1.
//

#ifndef SINGLETON_DATABASE_H
#define SINGLETON_DATABASE_H

#include <string>

using namespace std;

/// 需要确保数据库仅有一个实例在整个程序运行过程中
class Database
{
public:
    virtual int get_population(const string& name) = 0;
};


#endif //SINGLETON_DATABASE_H
