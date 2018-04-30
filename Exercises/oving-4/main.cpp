//
//  main.cpp
//  oving4
//
//  Created by Gjert Ingar Gjersund on 07.02.2018.
//  Copyright © 2018 Gjert Ingar Gjersund. All rights reserved.
//

#include <iostream>

#include "utilities.hpp"
#include "tests.hpp"
#include "mastermind.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    // Create random seed
    std::srand(std::time(nullptr));
    /*
    // Oppgave 1a)
    std::cout << "Oppgave 1a)" << std::endl;
    std::cout << "v0 = 25\n" << std::endl;
    
    // Oppgave 1c)
    std::cout << "Oppgave 1c)" << std::endl;
    testCallByValue();
    std::cout << "\n";
    
    // Oppgave 1d)
    std::cout << "Oppgave 1d)" << std::endl;
    testCallByPointer();
    std::cout << "\n";
    
    // Oppgave 1e)
    // I choose to use pointers here in order to reduce the amount of memory consumption that happens when
    // generating a new "instance" of each variable inside the swapNumbers function.
    std::cout << "Oppgave 1e)" << std::endl;
    int a = 5;
    int b = 10;
    testSwapNumbers(a, b);
    std::cout << "\n";
    
    // Oppgave 2a-e, 3a-b)
    std::cout << "Oppgave 2a-e)" << std::endl;
    testTablesSorting();
    std::cout << "\n";
    
    // Oppgave 4a)
    std::cout << "Oppgave 4e)" << std::endl;
    testCStrings();
    */
    // Oppgave5)
    playMastermind();
    
    return 0;
}
