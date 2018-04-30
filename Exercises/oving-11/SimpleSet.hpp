//
//  LinkedList.cpp
//  oving11
//
//  Created by Gjert Ingar Gjersund on 13.04.2018.
//  Copyright © 2018 Gjert Ingar Gjersund. All rights reserved.
//

#ifndef SimpleSet_hpp
#define SimpleSet_hpp

#include <ostream>

class SimpleSet{
    public:
    /** Construct empty set **/
    SimpleSet() {
        currentSize = 0;
        maxSize = 0;
    }
    
    /** Destructor */
    ~SimpleSet() {
        delete[] data;
    }
    
    /** Insert i into set, return true if the element was inserted, else false **/
    bool insert(int i) {
        if (!exists(i)) {
            if (currentSize == maxSize) {
                resize(currentSize + 1);
            }
            data[currentSize] = i;
            currentSize++;
            return true;
        } else {
            return false;
        }
    }
    
    /** Returns true if i is in the set **/
    bool exists(int i) {
        for (int j = 0; j < currentSize; j++) {
            return (data[j] == i) ? true: false;
        }
        return false;
    }
    
    /** Removes i from the set, return true if an element was removed **/
    bool remove(int i) {
        int k, pos;
        
        for (k = 0; k < currentSize; ++k) {
            if (data[k] == i) {
                pos = k;
                
                int * newData = new int [currentSize-1];
                for (k = 0; k < currentSize; ++k) {
                    if (k!= pos) {
                        newData[k] = data[k];
                        
                    }
                    else {
                        --k;
                    }
                    
                    data = newData;
                    newData = NULL;
                    delete[] newData;
                    --currentSize;
                }
            }
        }
        return false;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const SimpleSet& set) {
        int i;
        for (i = 0; i < set.currentSize; ++i) {
            os << set.data[i] << std::endl;
        }
        return os;
    }
    
    private:
    
    int *data;
    int currentSize;
    int maxSize;
        
    /** Returns the index where i may be found, else an invalid index. **/
    int find(int i) {
        for (int j = 0; j < currentSize; j++) {
            return (data[j] == i) ? j: -1;
        }
        return -1;
    }
    
    /** Resizes data, superflous elements are dropped. **/
    void resize(int n) {
        int *newData = new int[n];
        
        for (int i = 0; i < currentSize; i++) {
            newData[i] = data[i];
        }
        data = newData;
        newData = NULL;
        delete[] newData;
        maxSize = n;
    }
};

#endif /* SimpleSet.hpp */
