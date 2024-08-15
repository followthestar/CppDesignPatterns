//
// Created by 18030 on 2024/5/12.
//

#ifndef FACTORY_WALLFACTORY_H
#define FACTORY_WALLFACTORY_H

#include "SolidWall.h"
#include <vector>

//墙体类型
enum class WallType
{
    basic, main, partition
};

//引入工厂解决创建墙体避免相交的问题
class WallFactory
{
    inline static std::vector<std::weak_ptr<Wall>> walls;
public:
    static std::shared_ptr<SolidWall> create_main(Point2D start, Point2D end, int elevation, int height);

    static std::shared_ptr<SolidWall> create_partition(Point2D start, Point2D end, int elevation, int height);

    static std::shared_ptr<Wall> create_wall(WallType type, Point2D start, Point2D end, int elevation, int height);
};


#endif //FACTORY_WALLFACTORY_H
