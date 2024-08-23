cmake_minimum_required(VERSION 3.27)
project(Singleton)

set(CMAKE_CXX_STANDARD 23)

add_executable(Singleton main.cpp
        Database.h
        SingletonDatabase.h
        SingletonRecordFinder.h
        ConfigurableRecordFinder.h
        DummyDatabase.h
        PerThreadSingleton.cpp
        PerThreadSingleton.h
        BuildingContext.cpp
        BuildingContext.h
)

