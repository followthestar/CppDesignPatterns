//
// Created by 18030 on 2024/5/3.
//

#include "PersonBuilderBase.h"
#include "PersonAddressBuilder.h"

#include "Person.h"

PersonBuilderBase::operator Person()
{
    return std::move(person);
}

PersonAddressBuilder PersonBuilderBase::lives() const
{
    return PersonAddressBuilder(person);
}