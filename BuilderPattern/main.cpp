//
// Created by Tunahan Catak on 24/11/2024.
//

#include <iostream>

#include "src/Person.h"
#include "src/PersonBuilder.h"
#include "src/PersonAddressBuilder.h"
#include "src/PersonJobBuilder.h"

int main()
{

    std::cout << "Composite Builder Example\n";

    Person p = Person::create()
            .lives().at("Kavakli Mah. 101. Sk 16/3").with_postcode("41420").in("Kocaeli")
            .works().at("ICT Group").as_a("SW Designer").earning(70000);

    std::cout << "address = " << p.m_street_address << " "
                << "postal code = " << p.m_post_code << " "
                << "city = " << p.m_city << " "
                << "company name = " << p.m_company_name << " "
                << "position = " << p.m_position << " "
                << "earns = " << p.m_annual_income << " ";


    return 0;
}