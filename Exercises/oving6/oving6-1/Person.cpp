//
//  Person.cpp
//  oving6
//
//  Created by Gjert Ingar Gjersund on 22.02.2018.
//  Copyright © 2018 Gjert Ingar Gjersund. All rights reserved.
//

#include "Person.hpp"

// Main constructor
Person::Person(std::string name, std::string email, Car *car) : car(car), name(name), email(email) {}

// Second constructor
Person::Person(std::string name, std::string email) : Person::Person(name, email, nullptr) {}

std::string Person::getEmail() const {
    return email;
}

std::string Person::getName() const {
    return name;
}

void Person::setEmail(std::string email) {
    this->email = email;
}

bool Person::hasAvailableSeats() const {
    return (car) ? (((*car).hasFreeSeats()) ? true : false) : false;
}

// Operator
std::ostream & operator<<(std::ostream &os, const Person &p) {
    os << "Name of person: " << p.getName() << std::endl;
    os << "Email of person: " << p.getEmail() << std::endl;
    
    return os;
}

// Lexicographicall comparison
bool operator<(const Person &p1, const Person &p2) {
    return (p1.getName() < p2.getName()) ? true : false;
}

// Lexicographicall comparison
bool operator==(const Person &p1, const Person &p2) {
    return (p1.getName() == p2.getName()) ? true : false;
}
