//
//  Matrix.hpp
//  Oving7
//
//  Created by Gjert Ingar Gjersund on 27.04.2018.
//  Copyright © 2018 Gjert Ingar Gjersund. All rights reserved.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <iostream>

class Matrix {
    
private:
    double **data;
    unsigned int rows;
    unsigned int columns;
    
public:
    Matrix();
    explicit Matrix(unsigned int n);
    Matrix(unsigned int rows, unsigned int columns);
    ~Matrix();
    
    double get(unsigned int row, unsigned int col) { return data[row][col]; }
    void set(unsigned int row, unsigned int col, double value) { data[row][col] = value; }
    int getHeight() { return rows; }
    int getWidth() { return columns; }
    bool isValid() { return (data) ? true : false; }
    
    friend std::ostream &operator<<(std::ostream &os, Matrix &arr);
};

#endif /* Matrix_hpp */
