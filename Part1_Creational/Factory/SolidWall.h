//
// Created by 18030 on 2024/5/5.
//

#ifndef FACTORY_SOLIDWALL_H
#define FACTORY_SOLIDWALL_H

#include "Wall.h"
#include <ostream>

//对于SolidWall，加入一些现实世界的限制
//1.加气混凝土不能用于地下建筑
//2.墙的最小厚度是120mm
class SolidWall : public Wall
{
    int width;
    Material material;
public:
    SolidWall(Point2D start, Point2D end, int elevation, int heigth, int width, Material material);

    friend std::ostream& operator<<(std::ostream& out, const SolidWall& other)
    {
        out << "Width: " << other.width << "\n" << "Material: " << MaterialToString(other.material) << std::endl;
        return out;
    }

};


//使用工厂方法改进上述问题
class FSolidWall : public Wall
{
    int width;
    Material material;
protected:
    FSolidWall(
            const Point2D start, const Point2D end, const int elevation, const int height, const int width,
            const Material material);

public:
    /// 构建375mm的加气混凝土承重墙
    /// \param start 起始点坐标
    /// \param end 结束点坐标
    /// \param elevation 海拔
    /// \param height 墙高
    /// \return
    static FSolidWall create_main(Point2D start, Point2D end, int elevation, int height);

    /// 构建120mm砖块隔墙
    /// \param start
    /// \param end
    /// \param elevation
    /// \param height
    /// \return
    static std::unique_ptr<FSolidWall> create_partition(Point2D start, Point2D end, int elevation, int height);

    /// 我们不允许将加气混凝土用于地下建筑，重新定义工厂方法
    /// \param start
    /// \param end
    /// \param elevation
    /// \param height
    /// \return
    static std::shared_ptr<FSolidWall> create_main2(Point2D start, Point2D end, int elevation, int height);
};

#endif //FACTORY_SOLIDWALL_H
