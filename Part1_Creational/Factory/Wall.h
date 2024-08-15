//
// Created by 18030 on 2024/5/5.
//

#ifndef FACTORY_WALL_H
#define FACTORY_WALL_H

#include "Point2D.h"
#include <memory>

enum class Material
{
    brick = 1, aerated_concrete = 2, drywall = 3
};

const char* MaterialToString(Material material);

class Wall
{
    Point2D start, end;
    int elevation, heigth;
public:
    Wall(Point2D start, Point2D end, int elevation, int heigth);

    bool intersects(Wall* wall);

    virtual ~Wall() = default;

private:
    //内部工厂
    class BasicWallFactory
    {
        friend Wall;

        BasicWallFactory() = default;

    public:
        std::shared_ptr<Wall> create(const Point2D start, const Point2D end, const int elevation, const int height)
        {
            Wall* wall = new Wall(start, end, elevation, height);
            return std::shared_ptr<Wall>(wall);
        }
    };

public:
    inline static BasicWallFactory factory;
};


#endif //FACTORY_WALL_H
