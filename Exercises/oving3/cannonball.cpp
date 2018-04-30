//
//  cannonball.cpp
//  oving3
//
//  Created by Gjert Ingar Gjersund on 30.01.2018.
//  Copyright © 2018 Gjert Ingar Gjersund. All rights reserved.
//

#include "cannonball.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include "utilities.h"

/*
 Oppgave 1, 2 og 3
 */
double acclY() {
    return -9.81;
}

double velY(double initVelocity, double time) {
    return (initVelocity + (acclY() * time));
}

double posX(double initPosition, double initVelocity, double time) {
    return (initPosition + (initVelocity * time));
}
double posY(double initPosition, double initVelocity, double time) {
    return (initPosition + (initVelocity * time) + ((acclY() * time * time) / 2));
}

void printTime(double time) {
    double hours = 0.0;
    double minutes = 0.0;
    double seconds = 0.0;
    
    hours = (time - (std::fmod(time, 3600))) / 3600;
    minutes = ((std::fmod(time, 3600)) - (std::fmod((std::fmod(time,3600)), 60))) / 60;
    seconds = std::fmod((std::fmod(time, 3600)), 60);
    
    std::cout << "Tid: " << hours << ":" << minutes << ":" << std::setprecision(3) << seconds << std::endl;
}

double flightTime(double initVelocity) {
    return ((-2 * initVelocity) / acclY());
}


/*
 Oppgave 4
 */
void getUserInput(double *theta, double *absVelocity) {
    std::cout << "Vennligst skriv inn vinkel (i grader): " << std::endl;
    std::cin >> *theta;
    std::cout << "Vennligst skriv inn fart (i m/s): " << std::endl;
    std::cin >> *absVelocity;
}

double degToRad(double deg) {
    return (deg * (3.141595 / 180));
}

double getVelocityX(double theta, double absVelocity) {
    return (absVelocity * std::cos(degToRad(theta)));
}
double getVelocityY(double theta, double absVelocity) {
    return (absVelocity * std::sin(degToRad(theta)));
}

void getVelocityVector(double theta, double absVelocity, double *velocityX, double *velocityY) {
    *velocityX = getVelocityX(theta, absVelocity);
    *velocityY = getVelocityY(theta, absVelocity);
}

double getDistanceTraveled(double velocityX, double velocityY) {
    double time = flightTime(velocityY);
    return (time * velocityX);
}

double targetPractice(double distanceToTarget, double velocityX, double velocityY) {
    return (distanceToTarget - getDistanceTraveled(velocityX, velocityY));
}

void playTargetPractice() {
    
    double distanceToTarget = randomWithLimits(100, 1000);
    
    double theta = 0;
    double absVelocity = 0;
    double velocityX = 0;
    double velocityY = 0;
    
    bool winner = false;
    
    for (int i = 0; i < 10; i++) {
        
        getUserInput(&theta, &absVelocity);
        getVelocityVector(theta, absVelocity, &velocityX, &velocityY);
        
        if (targetPractice(distanceToTarget, velocityX, velocityY) > 5) {
            std::cout << "Oisann, det var for kort. Du har " << 9 - i << " forsøk igjen på å treffe.\n" << std::endl;
        } else if (targetPractice(distanceToTarget, velocityX, velocityY) < (-5)) {
            std::cout << "Oisann, det var for langt. Du har " << 9 - i << " forsøk igjen på å treffe.\n" << std::endl;
        } else {
            std::cout << "Gratulerer, du traff!" << std::endl;
            winner = true;
            break;
        }
    }
    
    if (!winner) {
        std::cout << "Beklager, du tapte!" << std::endl;
    }
}
