cmake_minimum_required(VERSION 3.27)
project(Prototype)

set(CMAKE_CXX_STANDARD 23)

add_executable(Prototype main.cpp
        Address.h
        Contact.h
        EmployeeFactory.cpp
        EmployeeFactory.h)
