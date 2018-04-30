//
//  main.cpp
//  Oving7
//
//  Created by Gjert Ingar Gjersund on 27.02.2018.
//  Copyright © 2018 Gjert Ingar Gjersund. All rights reserved.
//

#include <iostream>

#include "functions.hpp"
#include "Matrix.hpp"

int main() {
    
    // Exercise 1
    std::cout << "Exercise 1)" << std::endl << std::endl;
    std::cout << "Welcome to the \"Create Fibonacci series program\"!" << std::endl << std::endl;
    int command = 1;
    
    while (command == 1) {
        createFibonacci();
        std::cout << "Do you want to go again? Type 1 to repeat or 0 quit." << std::endl;
        std::cin >> command;
    }
    std::cout << std::endl;
    
    // Exercise 2
    std::cout << "Exercise 2)" << std::endl << std::endl;
    Matrix matrix_1;
    Matrix matrix_2(5);
    Matrix matrix_3(2, 3);
    
    std::cout << matrix_1 << std::endl;
    std::cout << matrix_2 << std::endl;
    std::cout << matrix_3 << std::endl;
    
    std::cout << "Value at location (1, 1): " << matrix_2.get(1, 1) << std::endl;
    std::cout << "Value at location (0, 1): " << matrix_2.get(0, 1) << std::endl;
    
    matrix_2.set(0, 1, 4.0);
    std::cout << "Value at location (0, 1) after setting 4.0: " << matrix_2.get(0, 1) << std::endl;
    
    std::cout << "Height of the matrix: " << matrix_3.getHeight() << std::endl;
    std::cout << "Width of the matrix: " << matrix_3.getWidth() << std::endl;
    
    // Exercise 3
    
    
    return 0;
}
