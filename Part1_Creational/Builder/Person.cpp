//
// Created by 18030 on 2024/5/3.
//

#include "Person.h"
#include "PersonBuilder.h"

PersonBuilder Person::create()
{
    return { };
}

ostream& operator<<(ostream& os, Person& p)
{
    os << p.street_address << "\t" << p.post_code << "\t" << p.city;
    return os;
}