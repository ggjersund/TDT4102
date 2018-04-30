//
//  Matrix.cpp
//  Oving7
//
//  Created by Gjert Ingar Gjersund on 27.04.2018.
//  Copyright © 2018 Gjert Ingar Gjersund. All rights reserved.
//

#include "Matrix.hpp"

// Constructors
Matrix::Matrix() : rows(0), columns(0) {
    data = nullptr;
}
Matrix::Matrix(unsigned int n) : Matrix(n, n) {
    for (int i = 0; i < n; ++i) {
        data[i][i] = 1.0;
    }
}
Matrix::Matrix(unsigned int rows, unsigned int columns) : rows(rows), columns(columns) {
    data = new double *[this->rows];
    for (int i = 0; i < this->rows; ++i) {
        data[i] = new double [this->columns];
        for (int j = 0; j < this->columns; ++j) {
            data[i][j] = 0.0;
        }
    }
}
// Destructor
Matrix::~Matrix() {
    for (int i = 0; i < this->rows; ++i) {
        delete[] data[i];
        data[i] = nullptr;
    }
    delete[] data;
    data = nullptr;
}
// Operator overloading
std::ostream &operator<<(std::ostream &os, Matrix &matrix) {
    if (matrix.isValid()) {
        for (int i = 0; i < matrix.rows; ++i) {
            for (int j = 0; j < matrix.columns; ++j) {
                os << matrix.data[i][j] << " ";
            }
            os << std::endl;
        }
    } else {
        os << "Invalid matrix" << std::endl;
    }
    return os;
}
