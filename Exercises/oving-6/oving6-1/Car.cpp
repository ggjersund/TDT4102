//
//  Car.cpp
//  oving6
//
//  Created by Gjert Ingar Gjersund on 22.02.2018.
//  Copyright © 2018 Gjert Ingar Gjersund. All rights reserved.
//

#include "Car.hpp"


Car::Car(int seats) {
    freeSeats = seats;
}

bool Car::hasFreeSeats() const {
    return (freeSeats != 0) ? (true) : (false);
}

void Car::reserveFreeSeat() {
    --freeSeats;
}
