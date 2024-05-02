//
// Created by 18030 on 2024/5/3.
//

#include "PersonAddressBuilder.h"
#include "Person.h"

PersonAddressBuilder::self& PersonAddressBuilder::at(std::string street_address)
{
    person.street_address = std::move(street_address);
    return *this;
}

PersonAddressBuilder::self& PersonAddressBuilder::with_postcode(std::string post_code)
{
    person.post_code = std::move(post_code);
    return *this;
}

PersonAddressBuilder::self& PersonAddressBuilder::in(std::string city)
{
    person.city = std::move(city);
    return *this;
}