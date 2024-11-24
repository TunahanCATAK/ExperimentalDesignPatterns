//
// Created by Tunahan Catak on 24/11/2024.
//

#ifndef COMPOSITEBUILDER_PERSON_H
#define COMPOSITEBUILDER_PERSON_H

#include <string>

class PersonBuilder;

class Person {

public:
    std::string m_street_address;
    std::string m_post_code;
    std::string m_city;

    std::string m_company_name;
    std::string m_position;
    int m_annual_income = 0;

    static PersonBuilder create();

    Person() = default;
    Person(const Person&) = default;
    Person(Person&&) = default;

    Person& operator=(const Person&) = default;
    Person& operator=(Person&&) = default;

    ~Person() = default;
};


#endif //COMPOSITEBUILDER_PERSON_H
