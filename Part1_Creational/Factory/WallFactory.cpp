//
// Created by 18030 on 2024/5/12.
//

#include "WallFactory.h"

#include <memory>

std::shared_ptr<SolidWall> WallFactory::create_main(Point2D start, Point2D end, int elevation, int height)
{
    if (elevation < 0)
        return { };
    //对于不符合要求的参数，返回std::shared_ptr默认值，其内部指向nullptr
    return std::make_shared<SolidWall>(SolidWall { start, end, elevation, height, 385, Material::aerated_concrete });
}

std::shared_ptr<SolidWall> WallFactory::create_partition(Point2D start, Point2D end, int elevation, int height)
{
    const auto this_wall = new SolidWall { start, end, elevation, height, 120, Material::brick };

    // ensure we don't intersect other walls
    for (const auto& wall : walls)
    {
        if (auto p = wall.lock())
        {
            if (this_wall->intersects(p.get()))
            {
                delete this_wall;
                return { };
            }
        }
    }
    std::shared_ptr<SolidWall> ptr(this_wall);
    walls.push_back(ptr);
    return ptr;
}

std::shared_ptr<Wall> WallFactory::create_wall(WallType type, Point2D start, Point2D end, int elevation, int height)
{
    switch (type)
    {
        case WallType::main:
            return std::make_shared<SolidWall>(start, end, elevation, height, 375, Material::aerated_concrete);
        case WallType::partition:
            return std::make_shared<SolidWall>(start, end, elevation, height, 120, Material::brick);
        case WallType::basic:
            return std::make_shared<Wall>(start, end, elevation, height);
    }
    return { };
}
