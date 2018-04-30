//
//  Sudoku.hpp
//  oving12
//
//  Created by Gjert Ingar Gjersund on 23.04.2018.
//  Copyright © 2018 Gjert Ingar Gjersund. All rights reserved.
//

#ifndef Sudoku_hpp
#define Sudoku_hpp

#include <iostream>
#include <set>
#include <string>
#include <fstream>

class Sudoku {
    
private:
    
    int size;
    int** board;
    std::set<int>* rows;
    std::set<int>* cols;
    std::set<int>** boxes;
    
public:
    
    // Constructor
    Sudoku();
    
    // Destructor
    ~Sudoku();
    
    // Save and Load
    void Save(std::string filename);
    void Load(std::string filename);
    
    // Input
    void Box(int row, int col, int &h, int &v);
    void InsertValue(int x, int y, int number);
    
    // Interact
    void Edit();
    void Play();
    
    // Operator
    friend std::ostream& operator <<(std::ostream& os, const Sudoku& sudoku);
    
};

#endif /* Sudoku_hpp */
