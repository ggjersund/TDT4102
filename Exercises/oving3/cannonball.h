//
//  canonball.h
//  oving3
//
//  Created by Gjert Ingar Gjersund on 30.01.2018.
//  Copyright © 2018 Gjert Ingar Gjersund. All rights reserved.
//

double acclY();

double velY(double initVelocity, double time);

double posX(double initPosition, double initVelocity, double time);
double posY(double initPosition, double initVelocity, double time);

void printTime(double time);

double flightTime(double initVelocity);

void getUserInput(double *theta, double *absVelocity);

double degToRad(double deg);

double getVelocityX(double theta, double absVelocity);
double getVelocityY(double theta, double absVelocity);

void getVelocityVector(double theta, double absVelocity, double *velocityX, double *velocityY);

double getDistanceTraveled(double velocityX, double velocityY);

double targetPractice(double distanceToTarget, double velocityX, double velocityY);

void playTargetPractice();
