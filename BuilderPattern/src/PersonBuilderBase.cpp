//
// Created by Tunahan Catak on 24/11/2024.
//

#include "PersonBuilderBase.h"
#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"

PersonAddressBuilder PersonBuilderBase::lives() const {
    return PersonAddressBuilder(m_person);
}

PersonJobBuilder PersonBuilderBase::works() const {
    return PersonJobBuilder(m_person);
}