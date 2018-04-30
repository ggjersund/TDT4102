//
//  Person.hpp
//  oving11
//
//  Created by Gjert Ingar Gjersund on 13.04.2018.
//  Copyright © 2018 Gjert Ingar Gjersund. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp

#include <string>
#include <iostream>
#include <forward_list>
#include <list>

// Class
class Person {
private:
    std::string firstname;
    std::string lastname;
public:
    Person(std::string firstname, std::string lastname);
    std::string getFirstname() const;
    std::string getLastname() const;
};

// Operators
std::ostream & operator<<(std::ostream &os, const Person &p);
bool operator<(const Person &left, const Person &right);

// Linked lists functions
void insertOrdered(std::forward_list<Person> &list, const Person &p);
void insertOrdered(std::list<Person> &list, const Person &p);

#endif /* Person_hpp */
