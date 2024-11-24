//
// Created by Tunahan Catak on 24/11/2024.
//

#ifndef COMPOSITEBUILDER_PERSONBUILDER_H
#define COMPOSITEBUILDER_PERSONBUILDER_H

#include "PersonBuilderBase.h"

class PersonBuilder : public PersonBuilderBase {
    Person m_person;
public:
    PersonBuilder() : PersonBuilderBase{m_person}
    {}
};


#endif //COMPOSITEBUILDER_PERSONBUILDER_H
