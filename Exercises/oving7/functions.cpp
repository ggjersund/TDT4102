//
//  functions.cpp
//  Oving7
//
//  Created by Gjert Ingar Gjersund on 27.04.2018.
//  Copyright © 2018 Gjert Ingar Gjersund. All rights reserved.
//

#include "functions.hpp"

void fillInFibonacciNumbers(int result[], int length) {
    for (int i = 0; i < length; ++i) {
        if (i == 0) {
            result[i] = 0;
        } else if (i == 1) {
            result[i] = 1;
        } else {
            result[i] = result[i - 1] + result[i - 2];
        }
    }
}

void printArray(int arr[], int length) {
    for (int i = 0; i < length; ++i) {
        std::cout << arr[i] << std::endl;
    }
}

void createFibonacci() {
    int length;
    std::cout << "Please input the number of Fibonacci numbers you wish to generate:" << std::endl;
    std::cin >> length;
    
    int *fibonacci = new int[length] {};
    
    fillInFibonacciNumbers(fibonacci, length);
    printArray(fibonacci, length);
    
    delete[] fibonacci;
    fibonacci = nullptr;
}
