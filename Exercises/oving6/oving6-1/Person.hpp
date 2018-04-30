//
//  Person.hpp
//  oving6
//
//  Created by Gjert Ingar Gjersund on 22.02.2018.
//  Copyright © 2018 Gjert Ingar Gjersund. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp

#include <iostream>
#include <stdio.h>
#include <string>
#include "Car.hpp"

class Person {
    private:
        std::string name;
        std::string email;
        Car *car;
    public:
        Person(std::string name, std::string email, Car *car);
        Person(std::string name, std::string email);
        std::string getEmail() const;
        std::string getName() const;
        void setEmail(std::string email);
        bool hasAvailableSeats() const;
};

std::ostream & operator<<(std::ostream &os, const Person& p);
bool operator<(const Person &p1, const Person &p2);
bool operator==(const Person &p1, const Person &p2);

#endif /* Person_hpp */
