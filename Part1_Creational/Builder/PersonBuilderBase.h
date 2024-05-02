//
// Created by 18030 on 2024/5/3.
//

#ifndef BUILDER_PERSONBUILDERBASE_H
#define BUILDER_PERSONBUILDERBASE_H

#include <iostream>

using namespace std;

class PersonAddressBuilder;

class PersonJobBuilder;

class Person;

class PersonBuilderBase
{
protected:
    Person& person;

    explicit PersonBuilderBase(Person& person) : person(person) { }

public:
    operator Person();

    // builder facets
    [[nodiscard]] PersonAddressBuilder lives() const;

    [[nodiscard]] PersonJobBuilder works() const;
};


#endif //BUILDER_PERSONBUILDERBASE_H
