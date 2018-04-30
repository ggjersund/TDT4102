//
//  main.cpp
//  oving6
//
//  Created by Gjert Ingar Gjersund on 22.02.2018.
//  Copyright © 2018 Gjert Ingar Gjersund. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Person.hpp"
#include "Car.hpp"

int main() {
    
    // Person with 4 seat car, where 1 is reserved
    Car car1(3);
    car1.reserveFreeSeat();
    Person person1("Ola Nordmann", "ola@nordmann.no", &car1);
    std::cout << person1.getName() << std::endl;
    std::cout << person1.getEmail() << std::endl;
    person1.setEmail("ola@nordmann2.no");
    std::cout << person1.getEmail() << std::endl;
    std::cout << person1.hasAvailableSeats() << std::endl << std::endl;
    std::cout << person1 << std::endl;
    
    // Person without car
    Person person2("John Doe", "john@doe.com");
    std::cout << person2.getName() << std::endl;
    std::cout << person2.getEmail() << std::endl;
    std::cout << person2.hasAvailableSeats() << std::endl;
    
    // Compare the two people
    std::cout << (person1 == person2) << std::endl;
    std::cout << (person2 == person1) << std::endl;
    std::cout << (person1 < person2) << std::endl;
    std::cout << (person2 < person1) << std::endl;
    
    return 0;
}
