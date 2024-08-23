//
// Created by 18030 on 2024/6/30.
//

#ifndef PROTOTYPE_EMPLOYEEFACTORY_H
#define PROTOTYPE_EMPLOYEEFACTORY_H
#include "Contact.h"
#include <memory>

class EmployeeFactory
{
    static Contact main;
    static Contact aux;

    static unique_ptr<Contact> NewEmployee(const string& name, int suite, Contact& proto)
    {
        auto result = make_unique<Contact>(proto);
        result->name = name;
        result->address.suite = suite;
        return result;
    }

public:
    static unique_ptr<Contact> NewMainOfficeEmployee(const string& name, int suite)
    {
        return NewEmployee(name, suite, main);
    }

    static unique_ptr<Contact> NewAuxOfficeEmployee(const string& name, int suite)
    {
        return NewEmployee(name, suite, aux);
    }
};


#endif //PROTOTYPE_EMPLOYEEFACTORY_H
