//
// Created by 18030 on 2024/5/5.
//

#include "Wall.h"

const char* MaterialToString(Material material)
{
    switch (material)
    {
        case Material::brick:
            return "brick";
        case Material::aerated_concrete:
            return "aerated_concrete";
        case Material::drywall:
            return "drywall";
    }
    //return "";
}

Wall::Wall(Point2D start, Point2D end, int elevation, int heigth)
        : start(start), end(end), elevation(elevation), heigth(heigth)
{

}

bool Wall::intersects(Wall* wall)
{
    return false;
}

