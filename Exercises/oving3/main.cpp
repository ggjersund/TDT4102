//
//  main.cpp
//  oving3
//
//  Created by Gjert Ingar Gjersund on 30.01.2018.
//  Copyright © 2018 Gjert Ingar Gjersund. All rights reserved.
//

#include "cannonball.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(nullptr));
    
    // Oppgave 1, 2, 3
    std::cout << acclY() << std::endl;
    std::cout << velY(25, 2.5) << std::endl;
    std::cout << posY(0, 25, 2.5) << std::endl;
    std::cout << posX(0, 50, 2.5) << std::endl;
    printTime(2.5);
    std::cout << flightTime(25) << std::endl;

    
    // Oppgave 4, 5 6
    playTargetPractice();
    
    return 0;
}
