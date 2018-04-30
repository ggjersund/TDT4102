//
//  card.cpp
//  oving5
//
//  Created by Gjert Ingar Gjersund on 10.02.2018.
//  Copyright © 2018 Gjert Ingar Gjersund. All rights reserved.
//

#include "Card.hpp"

std::string suitToString(Suit suit) {
    std::string suitString;
    switch (suit) {
        case CLUBS: suitString = "clubs"; break;
        case DIAMONDS: suitString = "diamonds"; break;
        case HEARTS: suitString = "hearts"; break;
        case SPADES: suitString = "spades"; break;
        default: throw std::invalid_argument("Suit provided is invalid"); break;
    }
    return suitString;
}

std::string rankToString(Rank rank) {
    std::string rankString;
    switch (rank) {
        case TWO: rankString = "two"; break;
        case THREE: rankString = "three"; break;
        case FOUR: rankString = "four"; break;
        case FIVE: rankString = "five"; break;
        case SIX: rankString = "six"; break;
        case SEVEN: rankString = "seven"; break;
        case EIGHT: rankString = "eight"; break;
        case NINE: rankString = "nine"; break;
        case TEN: rankString = "ten"; break;
        case JACK: rankString = "jack"; break;
        case QUEEN: rankString = "queen"; break;
        case KING: rankString = "king"; break;
        case ACE: rankString = "ace"; break;
        default: throw std::invalid_argument("Rank provided is invalid"); break;
    }
    return rankString;
}

std::string toString(CardStruct card) {
    std::string returnString = rankToString(card.r) + " of " + suitToString(card.s);
    return returnString;
}


std::string toStringShort(CardStruct card) {
    std::string returnString = suitToString(card.s).substr(0, 1) + std::to_string(card.r);
    return returnString;
}

void Card::initialize(Suit suit, Rank rank) {
    this->rank = rank;
    this->suit = suit;
    this->valid = true;
}

Suit Card::getSuit() {
    return this->suit;
}

Rank Card::getRank() {
    return this->rank;
}

std::string Card::toString() {
    if (!this->valid) return "Invalid card";
    std::string returnString = rankToString(this->rank) + " of " + suitToString(this->suit);
    return returnString;
}

std::string Card::toStringShort() {
    if (!this->valid) return "Invalid card";
    std::string returnString = suitToString(this->suit).substr(0, 1) + std::to_string(this->rank);
    return returnString;
}

Card::Card() {
    valid = false;
}

Card::Card(Suit suit, Rank rank) {
    initialize(suit, rank);
}
