//
//  Card.hpp
//  oving5
//
//  Created by Gjert Ingar Gjersund on 10.02.2018.
//  Copyright © 2018 Gjert Ingar Gjersund. All rights reserved.
//

#ifndef Card_hpp
#define Card_hpp

#include <stdio.h>
#include <string>
#include <stdexcept>
#include <iostream>

enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };
enum Rank { TWO = 2, THREE = 3, FOUR = 4, FIVE = 5, SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9, TEN = 10, JACK, QUEEN, KING, ACE };

std::string suitToString(Suit suit);
std::string rankToString(Rank rank);

struct CardStruct {
    Suit s;
    Rank r;
};

std::string toString(CardStruct card);
std::string toStringShort(CardStruct card);

class Card {
    private:
        Suit suit;
        Rank rank;
        bool valid;
    public:
        Card();
        void initialize(Suit suit, Rank rank);
        Card(Suit suit, Rank rank);
        Suit getSuit();
        Rank getRank();
        std::string toString();
        std::string toStringShort();
};

#endif /* Card_hpp */
