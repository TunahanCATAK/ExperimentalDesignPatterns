//
// Created by Tunahan Catak on 24/11/2024.
//

#ifndef COMPOSITEBUILDER_PERSONBUILDERBASE_H
#define COMPOSITEBUILDER_PERSONBUILDERBASE_H

#include "Person.h"

class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBuilderBase {
protected:
    Person& m_person;
    explicit PersonBuilderBase(Person& person): m_person{person} {}

public:
    operator Person()
    {
        return std::move(m_person);
    }

    //builder facets
    PersonAddressBuilder lives() const;
    PersonJobBuilder works() const;
};


#endif //COMPOSITEBUILDER_PERSONBUILDERBASE_H
