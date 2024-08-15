cmake_minimum_required(VERSION 3.27)
project(Factory)

set(CMAKE_CXX_STANDARD 23)

add_executable(Factory main.cpp
        Point2D.cpp
        Point2D.h
        Wall.cpp
        Wall.h
        SolidWall.cpp
        SolidWall.h
        WallFactory.cpp
        WallFactory.h
        HotDrink.h
        Tea.h
        HotDrinkFactory.h
        CoffeeFactory.h
        Coffee.h
        TeaFactory.h
        DrinkFactory.h)
