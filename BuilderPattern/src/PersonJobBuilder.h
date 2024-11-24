//
// Created by Tunahan Catak on 24/11/2024.
//

#ifndef COMPOSITEBUILDER_PERSONJOBBUILDER_H
#define COMPOSITEBUILDER_PERSONJOBBUILDER_H

#include "PersonBuilderBase.h"

class PersonJobBuilder : public PersonBuilderBase {
typedef PersonJobBuilder self;

public:
    explicit PersonJobBuilder(Person& person) : PersonBuilderBase{person}{}

    self& at(std::string company_name)
    {
        m_person.m_company_name = company_name;
        return *this;
    }

    self& as_a(std::string position)
    {
        m_person.m_position = position;
        return *this;
    }

    self& earning(int income)
    {
        m_person.m_annual_income = income;
        return *this;
    }
};


#endif //COMPOSITEBUILDER_PERSONJOBBUILDER_H
