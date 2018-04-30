//
//  main.cpp
//  oving11
//
//  Created by Gjert Ingar Gjersund on 12.04.2018.
//  Copyright © 2018 Gjert Ingar Gjersund. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cstdlib>
#include <ctime>
#include <forward_list>

#include "functions.hpp"
#include "Person.hpp"
#include "LinkedList.hpp"
#include "SimpleSet.hpp"

// Template function for shuffling
template<class T>
void shuffle(T list[], int length) {
    std::srand(std::time(nullptr));
    for (int i = 0; i < length; i++) {
        T temp;
        int random = (std::rand() % length);
        temp = list[i];
        list[i] = list[random];
        list[random] = temp;
    }
}

// Template function for returning maximum
template<class T>
T maximum(T a, T b) {
    return ((a > b) ? a : b);
}

int main() {
    
    // Oppgave 1
    std::cout << "Oppgave 1" << std::endl;
    std::vector<std::string> strings = {"Lorem", "Ipsum", "Dolor", "Sit", "Amet", "Consectetur"};
    
    // Deloppgave 1a
    // Variant 1
    for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++) {
        std::cout << *it << std::endl;
    }
    std::cout << std::endl;
    // Variant 2
    for (auto it = strings.begin(); it != strings.end(); it++) {
        std::cout << *it << std::endl;
    }
    std::cout << std::endl;
    
    // Deloppgave 1b
    for (std::vector<std::string>::reverse_iterator it = strings.rbegin(); it != strings.rend(); it++) {
        std::cout << *it << std::endl;
    }
    std::cout << std::endl;
    
    // Deloppgave 1c
    replace(strings, "Lorem", "Ipsum");
    for (auto it = strings.begin(); it != strings.end(); it++) {
        std::cout << *it << std::endl;
    }
    std::cout << std::endl;
    
    // Oppgave 2
    std::cout << "Oppgave 2" << std::endl;
    std::set<int> integers;
    
    // Deloppgave 2a
    for (int i = 0; i <= 100; i++) {
        integers.insert(i);
    }
    for (int i = 0; i <= 100; i++) {
        integers.insert(i);
    }
    for (auto it = integers.begin(); it != integers.end(); it++) {
        std::cout << *it << std::endl;
    }
    std::cout << std::endl;
    
    // Deloppgave 2b
    for (auto it = integers.begin(); it != integers.end(); it++) {
        if ((*it % 2 == 0) && (*it != 2)) {
            it = integers.erase(it);
        }
    }
    for (auto it = integers.begin(); it != integers.end(); it++) {
        std::cout << *it << std::endl;
    }
    std::cout << std::endl;
    
    // Deloppgave 2c
    for (int i = 0; i <= 100; i++) {
        integers.insert(i);
    }
    for (int i = 2; i <= 50; i++) {
        for (auto it = integers.begin(); it != integers.end(); it++) {
            if (((*it % i) == 0) && (*it != i)) {
                integers.erase(it);
                it--;
            }
        }
    }
    for (auto it = integers.begin(); it != integers.end(); it++) {
        std::cout << *it << std::endl;
    }
    std::cout << std::endl;
    
    // Deloppgave 2d
    SimpleSet integers2;
    
    // Deloppgave 2e (a)
    for (int i = 0; i <= 100; i++) {
        integers2.insert(i);
    }
    for (int i = 0; i <= 100; i++) {
        integers2.insert(i);
    }
    std::cout << "Deloppgave 2e (a)" << integers2 << std::endl;
    std::cout << std::endl;
    
    // Deloppgave 2e (b)
    
    // Deloppgave 2e (c)
    
    // Oppgave 3
    std::cout << "Oppgave 3" << std::endl;
    // Deloppgave 3a
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    shuffle(a, 7);
    for (int i = 0; i < 7; i++) {
        std::cout << a[i] << std::endl;
    }
    std::cout << std::endl;
    double b[] = {1.2, 2.2, 3.2, 4.2};
    shuffle(b, 4);
    for (int i = 0; i < 4; i++) {
        std::cout << b[i] << std::endl;
    }
    std::cout << std::endl;
    std::string c[] = {"One", "Two", "Three", "Four"};
    shuffle(c, 4);
    for (int i = 0; i < 4; i++) {
        std::cout << c[i] << std::endl;
    }
    std::cout << std::endl;
    
    // Deloppgave 3b
    // Funker ikke for egen definert type pga. manglende overlagring av sammenlignings operatorer.
    // Solution: Fix it!
    int x = 1;
    int y = 2;
    int z = maximum(x, y);
    std::cout << z << std::endl << std::endl;
    
    double q = 1.1;
    double v = 1.2;
    double r = maximum(q, v);
    std::cout << r << std::endl << std::endl;
    
    // Oppgave 4
    
    
    // Oppgave 5
    std::cout << "Oppgave 5" << std::endl;
    
    // Deloppgave 5a
    Person person1("Ola", "Nordmann");
    std::cout << person1 << std::endl;
    Person person2("John", "Doe");
    std::cout << person2 << std::endl;
    Person person3("Åge", "Pettersen");
    std::cout << person3 << std::endl;
    std::cout << std::endl;
    // Deloppgave 5b
    // Spørsmål: Hvorfor må jeg bruke return i insertOrdered?
    std::forward_list<Person> personList;
    insertOrdered(personList, person3);
    insertOrdered(personList, person1);
    insertOrdered(personList, person2);
    
    for (auto it = personList.begin(); it != personList.end(); it++) {
        std::cout << *it << std::endl;
    }
    std::cout << std::endl;
    
    // Deloppgave 5c
    // Hvordan implementere den forskjellige fra forward_list uten insert_after
    
    // Oppgave 6
    std::cout << "Oppgave 6" << std::endl;
    
    // Deloppgave 6a
    
    LinkedList homeMadeLinkedList;
    homeMadeLinkedList.insert(homeMadeLinkedList.begin(), "Element 1");
    std::cout << homeMadeLinkedList << std::endl;
    /*
    // Deloppgave 6b
     
     T& operator[](int index) - O(1)
     iterator insert(iterator pos, T value) - O(N)
     iterator erase(iterator pos) - O(N)
     void push_back(T value) - O(1)
     void pop_back() - O(1)
     iterator find(T value) - O(N
     
     std::list:
     iterator insert(iterator pos, T value) - O(1)
     iterator erase(iterator pos) - O(1)
     void push_back(T value) - O(1)
     void pop_back() - O(1)
     void push_front(T value) - O(1)
     void pop_front() - O(1)
     iterator find(T value) - O(N)
     
     Stack:
        Last in - First out (legger til og fjerner noder fra slutten av listen)
     Queue:
        First in - First out ("Dytter" nodene ut)
     */
    
    return 0;
}
