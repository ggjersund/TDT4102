//
//  utilities.cpp
//  oving3
//
//  Created by Gjert Ingar Gjersund on 30.01.2018.
//  Copyright © 2018 Gjert Ingar Gjersund. All rights reserved.
//

#include "utilities.h"

int randomWithLimits(int min, int max) {
    
    return (std::rand() % ((max + 1) - min)) + min;
    
    /*
    std::random_device seeder;
    std::mt19937 engine(seeder());
    std::uniform_int_distribution<int> dist(min, max);
    
     return dist(engine);
     */
    
}
