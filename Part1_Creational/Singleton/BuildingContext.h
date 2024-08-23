//
// Created by 18030 on 2024/7/6.
//

/** 环境上下文 */

#ifndef SINGLETON_BUILDINGCONTEXT_H
#define SINGLETON_BUILDINGCONTEXT_H

#include <stack>

using namespace std;

#include <iostream>

class BuildingContext final
{
    int height { 0 };

    BuildingContext() = default;

    class Token
    {
    public:
        ~Token()
        {
            std::cout << "出栈1次" << std::endl;
            if (stack.size() > 1)
                stack.pop();
        }
    };

public:
    int get_height() { return height; }

    static stack<BuildingContext> stack;
    //later initialized

    static BuildingContext current()
    {
        return stack.top();
    }

    static Token with_height(int height)
    {
        std::cout << "新高度入栈" << std::endl;
        auto copy = current();
        copy.height = height;
        stack.push(copy);
        return { };
    }
};


#endif //SINGLETON_BUILDINGCONTEXT_H
