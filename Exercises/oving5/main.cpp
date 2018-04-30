//
//  main.cpp
//  oving5
//
//  Created by Gjert Ingar Gjersund on 10.02.2018.
//  Copyright © 2018 Gjert Ingar Gjersund. All rights reserved.
//

#include <iostream>
#include <ctime>
#include "Blackjack.hpp"

int main() {
    std::srand(std::time(nullptr));
    
    while (true) {
        Blackjack::Blackjack();
    }
    
    return 0;
}
