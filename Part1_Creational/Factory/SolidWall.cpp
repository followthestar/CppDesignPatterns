//
// Created by 18030 on 2024/5/5.
//

#include "SolidWall.h"
#include <iostream>

using namespace std;

//一个可行的办法是对参数不符合要求的调用抛出异常
//但显然，这种方法并不好
SolidWall::SolidWall(Point2D start, Point2D end, int elevation, int heigth, int width, Material material)
        : Wall { start, end, elevation, heigth }, width(width), material(material)
{
    if (elevation < 0 && material == Material::aerated_concrete)
        throw invalid_argument("elevation");
    if (width < 120 && material == Material::brick)
        throw invalid_argument("width");
}


FSolidWall::FSolidWall(
        const Point2D start, const Point2D end, const int elevation, const int height, const int width,
        const Material material)
        : Wall(start, end, elevation, height), width(width), material(material)
{

}

FSolidWall FSolidWall::create_main(Point2D start, Point2D end, int elevation, int height)
{
    return FSolidWall { start, end, elevation, height, 375, Material::aerated_concrete };
}

std::unique_ptr<FSolidWall> FSolidWall::create_partition(Point2D start, Point2D end, int elevation, int height)
{
    return std::make_unique<FSolidWall>(FSolidWall { start, end, elevation, height, 120, Material::brick });
}

std::shared_ptr<FSolidWall> FSolidWall::create_main2(Point2D start, Point2D end, int elevation, int height)
{
    if (elevation < 0)
        return { };
    //对于不符合要求的参数，返回std::shared_ptr默认值，其内部指向nullptr
    return std::make_shared<FSolidWall>(FSolidWall { start, end, elevation, height, 385, Material::aerated_concrete });
}
