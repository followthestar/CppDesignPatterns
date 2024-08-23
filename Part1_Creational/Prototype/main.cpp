#include <iostream>
#include "EmployeeFactory.h"

int main()
{
    cout << "Prototype Pattern（原型模式）示例" << endl;
    auto john = EmployeeFactory::NewAuxOfficeEmployee("John Doe", 123);
    auto jane = EmployeeFactory::NewAuxOfficeEmployee("Jane Doe", 123);
    return 0;
}
