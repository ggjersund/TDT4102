//
//  FancySafeArray.hpp
//  oving12
//
//  Created by Gjert Ingar Gjersund on 23.04.2018.
//  Copyright © 2018 Gjert Ingar Gjersund. All rights reserved.
//

#ifndef FancySafeArray_hpp
#define FancySafeArray_hpp

#include <iostream>

#include "SafeArray.hpp"

template<class T>
class FancySafeArray: public SafeArray<T> {

private:

public:
    
    // Constructors
    FancySafeArray() : SafeArray<T>() {}
    FancySafeArray(int length) : SafeArray<T>(length) {}
    FancySafeArray(SafeArray<T> &copy) : SafeArray<T>(copy) {}
    
};

// Output operator
template<class T>
std::ostream &operator<< (std::ostream &os, FancySafeArray<T> &array) {
    os << "[";
    for (int i = 0; i < (array.MaxLength() - 1); i++) {
        os << array[i] << ", ";
    }
    os << array[array.MaxLength() - 1];
    os << "]";
    return os;
}

// Addition operator
template<class T>
FancySafeArray<T> operator+ (const FancySafeArray<T> &a, const FancySafeArray<T> &b) {
    int size = a.Length() + b.Length();
    FancySafeArray<T> new_array(size);
    for (int i = 0; i < a.Length(); i++) {
        new_array[i] = a[i];
    }
    for (int i = a.Length(); i < size; i++) {
        new_array[i] = b[i - a.Length()];
    }
    return new_array;
}

#endif /* FancySafeArray_hpp */
