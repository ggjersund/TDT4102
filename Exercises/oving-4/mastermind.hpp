//
//  mastermind.hpp
//  oving4
//
//  Created by Gjert Ingar Gjersund on 08.02.2018.
//  Copyright © 2018 Gjert Ingar Gjersund. All rights reserved.
//

#ifndef mastermind_hpp
#define mastermind_hpp

#include <stdio.h>
#include "utilities.hpp"

void playMastermind();
int checkCharactersAndPosition(char code[], int codeSize, char guess[], int guessSize);
int checkCharacters(char code[], int codeSize, char guess[], int guessSize, int LETTERS);

#endif /* mastermind_hpp */
