//
//  Person.cpp
//  oving11
//
//  Created by Gjert Ingar Gjersund on 13.04.2018.
//  Copyright © 2018 Gjert Ingar Gjersund. All rights reserved.
//

#include "Person.hpp"

// Person class
Person::Person(std::string firstname, std::string lastname) {
    this->firstname = firstname;
    this->lastname = lastname;
}

// Member functions
std::string Person::getFirstname() const {
    return this->firstname;
}
std::string Person::getLastname() const {
    return this->lastname;
}

// Operators
bool operator<(const Person &left, const Person &right) {
    if (left.getFirstname() < right.getFirstname()) {
        return true;
    } else if (left.getFirstname() == right.getFirstname()) {
        return (left.getLastname() < right.getLastname()) ? true : false;
    } else {
        return false;
    }
}
std::ostream & operator<<(std::ostream &os, const Person &p) {
    os << p.getFirstname() << " " << p.getLastname();
    return os;
}

// Linked lists functions
void insertOrdered(std::forward_list<Person> &list, const Person &p) {
    // If list is empty
    if (list.empty()) {
        list.emplace_front(p);
        return;
    }
    for (std::forward_list<Person>::iterator it = list.begin(); it != list.end();) {
        auto current = it;
        
        // Check if person is smaller than current iterator
        if (p < *it) {
            list.insert_after(it, *it);
            *it = p;
            return;
        } else {
            it++;
            
            // Check if end of list
            if (it == list.end()) {
                list.emplace_after(current, p);
                return;
            }
        }
    }
}
void insertOrdered(std::list<Person> &list, const Person &p) {
    // If list is empty
    if (list.empty()) {
        list.emplace_front(p);
        return;
    }
    for (std::list<Person>::iterator it = list.begin(); it != list.end();) {
        auto current = it;
        
        // Check if person is smaller than current iterator
        if (p < *it) {
            //list.insert_after(it, *it);
            *it = p;
            return;
        } else {
            it++;
            
            // Check if end of list
            if (it == list.end()) {
                //list.emplace_after(current, p);
                return;
            }
        }
    }
}
