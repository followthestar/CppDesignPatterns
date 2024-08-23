//
// Created by 18030 on 2024/7/6.
//

#ifndef SINGLETON_PERTHREADSINGLETON_H
#define SINGLETON_PERTHREADSINGLETON_H
#include <thread>

using namespace std;


// 在多线程下的单例模式
class PerThreadSingleton
{
    PerThreadSingleton()
    {
        id = this_thread::get_id();
    }

public:
    thread::id id;

    static PerThreadSingleton& get()
    {
        thread_local PerThreadSingleton instance;
        return instance;
    }
};


#endif //SINGLETON_PERTHREADSINGLETON_H
