//
// Created by 18030 on 2024/5/3.
//

#ifndef BUILDER_PERSONADDRESSBUILDER_H
#define BUILDER_PERSONADDRESSBUILDER_H

#include "PersonBuilderBase.h"

class PersonAddressBuilder : public PersonBuilderBase
{
    typedef PersonAddressBuilder self;
public:
    explicit PersonAddressBuilder(Person& person) : PersonBuilderBase(person) { }

    self& at(string street_address);

    self& with_postcode(string post_code);

    self& in(string city);
};


#endif //BUILDER_PERSONADDRESSBUILDER_H
