//
//  SafeArray.hpp
//  oving12
//
//  Created by Gjert Ingar Gjersund on 13.04.2018.
//  Copyright © 2018 Gjert Ingar Gjersund. All rights reserved.
//

#ifndef SafeArray_hpp
#define SafeArray_hpp

#include <iostream>
#include <algorithm>
#include <exception>

template<class T>
class SafeArray {
    
protected:
    
    int data_length;
    int data_max_length;
    T *data;
    
public:
    
    // Constructor
    SafeArray() {
        data_length = 0;
        data_max_length = 0;
    }
    
    // Constructor with specified length
    SafeArray(int length) {
        data = new T[length] {};
        data_length = length;
        data_max_length = length;
    }
    
    // Deep copy constructor
    SafeArray(const SafeArray &copy) {
        data_length = copy.Length();
        data_max_length = copy.MaxLength();
        data = new T[data_max_length];
        for (int i = 0; i < data_max_length; i++) {
            data[i] = copy.data[i];
        }
    }
    
    // Destructor
    ~SafeArray() {
        delete[] data;
    }
    
    // Insert element method
    bool Insert(T value) {
        if (data_length == data_max_length) {
            Resize(data_length + 1);
        }
        data[data_length] = value;
        data_length++;
        return true;
    }
    
    // Occupied data length method
    int Length() const {
        return data_length;
    }
    
    // Max data length method
    int MaxLength() const {
        return data_max_length;
    }
    
    // Resize method
    void Resize(int length) {
        try {
            if (length < 0) {
                throw std::domain_error("Array size cant be negative.");
            } else {
                T *new_data = new T[length] {};
                if (length < data_length) {
                    data_length = length;
                    for (int i = 0; i < length; i++) {
                        new_data[i] = data[i];
                    }
                } else {
                    for (int i = 0; i < data_length; i++) {
                        new_data[i] = data[i];
                    }
                }
                delete[] data;
                data = new_data;
                data_max_length = length;
            }
        } catch (std::domain_error &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }
    
    // Index operator
    T &operator[](int index) const {
        try {
            if (index > data_max_length) {
                throw std::out_of_range("Array index out of range.");
            }
        } catch (std::out_of_range &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
        return data[index];
    }
    
    // Assignment operator
    SafeArray &operator=(SafeArray<T> copy) {
        std::swap(data, copy.data);
        std::swap(data_length, copy.data_length);
        std::swap(data_max_length, copy.data_max_length);
        return *this;
    }
};

#endif /* SafeArray_hpp */
