//
//  utilities.cpp
//  oving4
//
//  Created by Gjert Ingar Gjersund on 07.02.2018.
//  Copyright © 2018 Gjert Ingar Gjersund. All rights reserved.
//

#include "utilities.hpp"


int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
    return startValue;
}

void incrementByValueNumTimes2(int *startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        *startValue += increment;
    }
}

void swapNumbers(int *valueA, int *valueB) {
    int temp = *valueA;
    *valueA = *valueB;
    *valueB = temp;
}

void printArray(int array[], int size) {
    std::cout << "Array: ";
    for (int i = 0; i < size; i++) {
        std::cout << array[i];
        if (i != (size - 1)) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

int randomWithLimits(int min, int max) {
    return (std::rand() % ((max + 1) - min)) + min;
}

void randomizeArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] = randomWithLimits(0, 100);
    }
}

void sortArray(int array[], int size) {
    // Insertion sort
    int j, temp;
    
    for (int i = 0; i < size; i++) {
        j = i;
        
        while (j > 0 && array[j] < array[j - 1]) {
            temp = array[j];
            array[j] = array[j - 1];
            array[j - 1] = temp;
            j--;
        }
    }
}

double medianOfArray(int array[], int size) {
    double median = 0;
    
    if ((size % 2) == 1) {
        median = array[(size - 1) / 2];
    } else {
        int firstValue = (size / 2) - 1;
        int secondValue = size / 2;
        median = ((array[firstValue]) + (array[secondValue])) / 2;
    }
    return median;
}

void randomizeCString(char grades[], int gradesLength, char lowerLimit, char upperLimit) {
    int lowerLimitInt = lowerLimit;
    int upperLimitInt = upperLimit;
    
    for (int i = 0; i < (gradesLength - 1); i++) {
        char randomSymbol = randomWithLimits(lowerLimitInt, upperLimitInt);
        grades[i] = randomSymbol;
    }
}

void readInputToCString(char grades[], int gradesLength, char lowerLimit, char upperLimit) {
    int numberOfSymbols = NULL;
    
    while (!numberOfSymbols || (numberOfSymbols > gradesLength - 1)) {
        std::cout << "How many symbols do you wish to enter? Max amount is " << (gradesLength - 1) << std::endl;
        std::cin >> numberOfSymbols;
        
        if ((numberOfSymbols == 0) || (numberOfSymbols > gradesLength - 1)) {
            std::cout << "Invalid input, try again!\n" << std::endl;
        }
    }
    
    for (int i = 0; i < numberOfSymbols; i++) {
        char symbol = NULL;
        
        while (!symbol || symbol > upperLimit || symbol < lowerLimit) {
            std::cout << "Please input symbol #" << i + 1 << " ranging from " << upperLimit<< " to " << lowerLimit << std::endl;
            std::cin >> symbol;
            symbol = std::toupper(symbol);
            
            if (!symbol || symbol > upperLimit || symbol < lowerLimit) {
                std::cout << "Invalid input, please try again!" << std::endl;
            }
        }
        grades[i] = symbol;
    }
}

int countOccurencesOfCharacter(char grades[], int gradesLength, char symbol) {
    int count = 0;
    for (int i = 0; i < (gradesLength - 1); i++) {
        if (grades[i] == symbol) { count++; }
    }
    return count;
}
