//
//  functions.cpp
//  oving11
//
//  Created by Gjert Ingar Gjersund on 12.04.2018.
//  Copyright © 2018 Gjert Ingar Gjersund. All rights reserved.
//

#include "functions.hpp"

void replace(std::vector<std::string> &strings, std::string old, std::string replace) {
    for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++) {
        if (*it == old) {
            it = strings.erase(it);
            it = strings.insert(it, replace);
        }
    }
}
