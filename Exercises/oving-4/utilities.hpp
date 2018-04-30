//
//  utilities.hpp
//  oving4
//
//  Created by Gjert Ingar Gjersund on 07.02.2018.
//  Copyright © 2018 Gjert Ingar Gjersund. All rights reserved.
//

#ifndef utilities_hpp
#define utilities_hpp

#include <iostream>
#include <cctype>

int incrementByValueNumTimes(int startValue, int increment, int numTimes);
void incrementByValueNumTimes2(int *startValue, int increment, int numTimes);
void swapNumbers(int *valueA, int *valueB);
void printArray(int array[], int size);
int randomWithLimits(int min, int max);
void randomizeArray(int array[], int size);
void sortArray(int array[], int size);
double medianOfArray(int array[], int size);
void randomizeCString(char grades[], int gradesLength, char lowerLimit, char upperLimit);
void readInputToCString(char grades[], int gradesLength, char lowerLimit, char upperLimit);
int countOccurencesOfCharacter(char grades[], int gradesLength, char symbol);

#endif /* utilities_hpp */
