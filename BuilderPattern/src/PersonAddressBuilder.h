//
// Created by Tunahan Catak on 24/11/2024.
//

#ifndef COMPOSITEBUILDER_PERSONADDRESSBUILDER_H
#define COMPOSITEBUILDER_PERSONADDRESSBUILDER_H

#include "PersonBuilderBase.h"

class PersonAddressBuilder : public PersonBuilderBase {
typedef PersonAddressBuilder self;

public:
    explicit PersonAddressBuilder(Person& person) : PersonBuilderBase{person}{}

    self& at(std::string street_address)
    {
        m_person.m_street_address = street_address;
        return *this;
    }

    self& with_postcode(std::string post_code)
    {
        m_person.m_post_code = post_code;
        return *this;
    }

    self& in(std::string city)
    {
        m_person.m_city = city;
        return *this;
    }
};


#endif //COMPOSITEBUILDER_PERSONADDRESSBUILDER_H
