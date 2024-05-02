//
// Created by 18030 on 2024/5/3.
//

#ifndef BUILDER_PERSON_H
#define BUILDER_PERSON_H

#include <iostream>
#include <string>

using namespace std;

class PersonBuilder;

//记录一个人的某些信息
struct Person
{
    //address
    string street_address, post_code, city;

    //employment
    string company_name, position;
    int annual_income = 0;

    Person() = default;

    static PersonBuilder create();

    friend ostream& operator<<(ostream& os, Person& p);
};


#endif //BUILDER_PERSON_H
