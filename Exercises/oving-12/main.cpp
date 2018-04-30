//
//  main.cpp
//  oving12
//
//  Created by Gjert Ingar Gjersund on 13.04.2018.
//  Copyright © 2018 Gjert Ingar Gjersund. All rights reserved.
//

#include <iostream>
#include <string>

#include "SafeArray.hpp"
#include "FancySafeArray.hpp"
#include "Sudoku.hpp"

int main() {
    
    /*
     Exercise 1g)
     */
    // Testing with integers
    std::cout << "Exercise 1g) with integers" << std::endl;
    SafeArray<int> safe_array_1(5);
    for (int i = 0; i < safe_array_1.MaxLength(); i++) {
        safe_array_1[i] = i + 1;
    }
    for (int i = 0; i < safe_array_1.MaxLength(); i++) {
        std::cout << safe_array_1[i] << std::endl;
    }
    std::cout << std::endl;
    
    // Testing with strings
    std::cout << "Exercise 1g) with strings" << std::endl;
    SafeArray<std::string> safe_array_2(10);
    for (int i = 0; i < safe_array_2.MaxLength(); i++) {
        safe_array_2[i] = "Hei";
    }
    safe_array_2[9] = "Hade";
    for (int i = 0; i < safe_array_2.MaxLength(); i++) {
        std::cout << safe_array_2[i] << std::endl;
    }
    std::cout << std::endl;
    
    // Testing with doubles
    std::cout << "Exercise 1g) with doubles" << std::endl;
    SafeArray<double> safe_array_3(3);
    for (int i = 0; i < safe_array_3.MaxLength(); i++) {
        safe_array_3[i] = double (i * 1.1);
    }
    safe_array_3[0] = 0.123;
    for (int i = 0; i < safe_array_3.MaxLength(); i++) {
        std::cout << safe_array_3[i] << std::endl;
    }
    std::cout << std::endl;
    
    /*
     Exercise 1h)
     */
    std::cout << "Exercise 1h) with integers" << std::endl;
    std::cout << "Output with 3 elements" << std::endl;
    SafeArray<int> safe_array_4(3);
    for (int i = 0; i < safe_array_4.MaxLength(); i++) {
        safe_array_4[i] = i + 1;
    }
    for (int i = 0; i < safe_array_4.MaxLength(); i++) {
        std::cout << safe_array_4[i] << std::endl;
    }
    std::cout << "Output with 1 element" << std::endl;
    safe_array_4.Resize(1);
    for (int i = 0; i < safe_array_4.MaxLength(); i++) {
        std::cout << safe_array_4[i] << std::endl;
    }
    std::cout << "Output with 3 elements again" << std::endl;
    safe_array_4.Resize(3);
    for (int i = 0; i < safe_array_4.MaxLength(); i++) {
        std::cout << safe_array_4[i] << std::endl;
    }
    std::cout << std::endl;
    
    /*
     Exercise 1i)
     */
    std::cout << "Exercise 1i)" << std::endl;
    
    SafeArray<int> safe_array_5(10);
    
    for (int i = 0; i < 10; i++) {
        safe_array_5[i] = i;
    }
    
    for (int i = 0; i < 10; i++) {
        safe_array_5[i] = (safe_array_5[i] * safe_array_5[i]);
    }
    
    for (int i = 0; i < 10; i++) {
        std::cout << safe_array_5[i] << std::endl;
    }
    std::cout << std::endl;
    
    SafeArray<int> safe_array_6 = safe_array_5;
    
    safe_array_6.Resize(5);
    
    for (int i = 0; i < 5; i++) {
        safe_array_6[i] = safe_array_6[i] + 5;
    }
    
    safe_array_6.Resize(10);
    
    for (int i = 0; i < 10; i++) {
        std::cout << safe_array_5[i] << std::endl;
    }
    std::cout << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << safe_array_6[i] << std::endl;
    }
    std::cout << std::endl;
    
    /*
     Exercise 2
     */
    // Exercise 2b)
    /*
     By using the << operator on the FancySafeArray one is limited to datatypes that have << for ostream defined.
     Therefor there are slightly less possible types of data for this subclass.
     */
    
    // Exercise 2c)
    std::cout << "Exercise 2c)" << std::endl;
    
    FancySafeArray<int> fancy_safe_array_1(5);
    for (int i = 0; i < 5; i++) {
        fancy_safe_array_1[i] = i;
    }
    FancySafeArray<int> fancy_safe_array_2(5);
    for (int i = 0; i < 5; i++) {
        fancy_safe_array_2[i] = i;
    }
    std::cout << fancy_safe_array_1 << std::endl;
    std::cout << fancy_safe_array_2 << std::endl;
    
    FancySafeArray<int> fancy_safe_array_3;
    fancy_safe_array_3 = (fancy_safe_array_1 + fancy_safe_array_2);
    
    std::cout << fancy_safe_array_3 << std::endl;
    
    std::cout << std::endl;
    
    /*
     Exercise 3
     */
    
    // Exercise 3a)
    std::cout << "Exercise 3a)" << std::endl;
    fancy_safe_array_3[100];
    std::cout << std::endl;
    
    // Exercise 3b)
    std::cout << "Exercise 3b)" << std::endl;
    fancy_safe_array_3.Resize(-10);
    std::cout << std::endl;
    
    /*
     Exercise 4
     */
    
    // Exercise 4a)
    std::cout << "Exercise 4" << std::endl;
    Sudoku sudoku;
    sudoku.Play();
    
    // End program
    return 0;
}
