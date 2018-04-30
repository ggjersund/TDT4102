//
//  mastermind.cpp
//  oving4
//
//  Created by Gjert Ingar Gjersund on 08.02.2018.
//  Copyright © 2018 Gjert Ingar Gjersund. All rights reserved.
//

#include "mastermind.hpp"

void playMastermind() {
    const int SIZE = 4;
    const int LETTERS = 6;
    
    char code[SIZE + 1] = {};
    char guess[SIZE + 1] = {};
    
    int NumberOfTries = 2;
    
    int restart = 1;
    
    while(restart == 1) {
        randomizeCString(code, SIZE + 1, 'A', 'A' + (LETTERS - 1));
        
        std::cout << code << std::endl;
        
        int tries = 0;
        bool winner = false;
        while (checkCharactersAndPosition(code, SIZE + 1, guess, SIZE + 1) < SIZE && tries < NumberOfTries) {
            readInputToCString(guess, SIZE + 1, 'A', 'A' + (LETTERS - 1));
            
            std::cout << guess << std::endl;
            
            int correct = checkCharactersAndPosition(code, SIZE + 1, guess, SIZE + 1);
            
            if (correct == SIZE) {
                winner = true;
                break;
            }
            
            std::cout << "Korrekte plasser: " << correct << std::endl;
            
            int correct2 = checkCharacters(code, SIZE + 1, guess, SIZE + 1, LETTERS);
            
            std::cout << "Korrekte bokstaver: " << correct2 << std::endl;
            tries++;
        }
        if (winner == true) {
            std::cout << "GRATULERER DU VANT! Ønsker du å spille igjen? 1 = ja, 0 = nei" << std::endl;
            std::cin >> restart;
        } else {
            std::cout << "Du tapte :( Ønsker du å prøve igjen? 1 = ja, 0 = nei" << std::endl;
            std::cin >> restart;
        }
    }
}

int checkCharactersAndPosition(char code[], int codeSize, char guess[], int guessSize) {
    int correct = 0;
    for (int i = 0; i < (codeSize - 1); i++) {
        if (code[i] == guess[i]) {
            correct++;
        }
    }
    return correct;
}

int checkCharacters(char code[], int codeSize, char guess[], int guessSize, int LETTERS) {
    int correct = 0;
    for (int i = 0; i < LETTERS; i++) {
        int numberInCode = countOccurencesOfCharacter(code, codeSize, 'A' + i);
        int numberInGuess = countOccurencesOfCharacter(guess, guessSize, 'A' + i);
        if (numberInGuess != 0) {
            if (numberInGuess >= numberInCode) {
                correct += numberInCode;
            } else {
                correct += numberInGuess;
            }
        }
    }
    return correct;
}
