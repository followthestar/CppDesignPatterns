//
// Created by 18030 on 2024/5/3.
//

#ifndef BUILDER_PERSONBUILDER_H
#define BUILDER_PERSONBUILDER_H

#include "PersonBuilderBase.h"
#include "Person.h"

class PersonBuilder : public PersonBuilderBase
{
    Person p;   // object being built
public:
    PersonBuilder() : PersonBuilderBase(p) { }
};


#endif //BUILDER_PERSONBUILDER_H
