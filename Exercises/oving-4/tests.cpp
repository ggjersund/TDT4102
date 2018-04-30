//
//  tests.cpp
//  oving4
//
//  Created by Gjert Ingar Gjersund on 07.02.2018.
//  Copyright © 2018 Gjert Ingar Gjersund. All rights reserved.
//

#include "tests.hpp"


void testCallByValue() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    std::cout << "v0: " << v0 << " increment: " << increment << " iterations: " << iterations
    << " result: " << result << std::endl;
}

void testCallByPointer() {
    int v0 = 5;
    int v0_result = 5;
    int increment = 2;
    int iterations = 10;
    incrementByValueNumTimes2(&v0_result, increment, iterations);
    std::cout << "v0: " << v0 << " increment: " << increment << " iterations: " << iterations
    << " result: " << v0_result << std::endl;
}

void testSwapNumbers(int a, int b) {
    int tempA = a;
    int tempB = b;
    swapNumbers(&a, &b);
    std::cout << tempA << " is swapped for " << a << " and " << tempB << " is swapped for " << b << std::endl;
}

void testTablesSorting() {
    const int ARRAY_SIZE = 4;
    
    int percentages[ARRAY_SIZE] = {};
    
    std::cout << "Array before fill:" << std::endl;
    randomizeArray(percentages, ARRAY_SIZE);
    std::cout << "\n";
    
    std::cout << "Array before swap:" << std::endl;
    printArray(percentages, ARRAY_SIZE);
    std::cout << "\n";
    
    swapNumbers(&percentages[0], &percentages[1]);
    
    std::cout << "Array after swap:" << std::endl;
    printArray(percentages, ARRAY_SIZE);
    std::cout << "\n";
    
    sortArray(percentages, ARRAY_SIZE);
    
    std::cout << "Array after sort:" << std::endl;
    printArray(percentages, ARRAY_SIZE);
    std::cout << "\n";
    
    double median = medianOfArray(percentages, ARRAY_SIZE);
    std::cout << "Median of the array:" << std::endl;
    std::cout << median << "\n";
    
}

void testCStrings() {
    // REMEMBER TO ADD +1 FOR THE \0
    const int GRADES_LENGTH = 41;
    char grades1[GRADES_LENGTH] = {};
    char upperLimit = 'F';
    char lowerLimit = 'A';
    
    randomizeCString(grades1, GRADES_LENGTH, lowerLimit, upperLimit);
    std::cout << grades1 << std::endl;
    
    char grades2[GRADES_LENGTH] = {};
    readInputToCString(grades2, GRADES_LENGTH, lowerLimit, upperLimit);
    
    std::cout << grades2 << std::endl;
    
    int numberOfSymbol = countOccurencesOfCharacter(grades2, GRADES_LENGTH, 'A');
    
    std::cout << "Number of symbols: " << numberOfSymbol << std::endl;
    
    char gradesCount[7] = {};
    
    for (int i = 0; i < 6; i++) {
        gradesCount[i] = countOccurencesOfCharacter(grades2, GRADES_LENGTH, 'A' + i);
    }
    
    int sumAll = 0;
    int count = 0;
    for (int i = 0; i < 6; i++) {
        int current = 'A' + i;
        sumAll += gradesCount[i] * current;
        count += gradesCount[i];
    }
    std::cout << "Average grade is: " << char (sumAll / count) << std::endl;
    
}
