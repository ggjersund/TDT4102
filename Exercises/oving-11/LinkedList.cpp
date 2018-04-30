//
//  LinkedList.cpp
//  oving11
//
//  Created by Gjert Ingar Gjersund on 13.04.2018.
//  Copyright © 2018 Gjert Ingar Gjersund. All rights reserved.
//

#include "LinkedList.hpp"
#include <iostream>

std::ostream & operator<<(std::ostream &os, const Node &node) {
    os << node.getValue();
    return os;
}


Node* LinkedList::insert(Node *pos, const std::string& value) {
    for (auto it = this->begin(); it != this->end(); it++) {
        if ((*it).getNext() == pos) {
            (*it).next = std::make_unique<Node>(value, std::move(it->next));
            return it->getNext();
        }
    }
    if ((!this->isEmpty()) && pos == (this->end())) {
        std::cout << "Hei";
        (*(this->begin())).next = std::make_unique<Node>(value, std::move((this->begin())->next));
        return (this->begin())->getNext();
        
    }
    else if ((this->isEmpty()) && pos == (this->begin())) {
        std::unique_ptr<Node> newBeginning = std::make_unique<Node>(value, std::move(this->head));
        this->head = std::move(newBeginning);
        return this->begin();
    }
    return this->end();
}

Node* LinkedList::remove(Node* pos) {
    Node* next = (*pos).getNext();
    delete pos;
    return next;
}

Node* LinkedList::find(const std::string& value) {
    for (auto it = this->begin(); it != this->end(); it++) {
        if ((*it).getValue() == value) {
            return (*it).getNext();
        }
    }
    return this->end();
}

void LinkedList::remove(const std::string& value) {
    Node* pointer = this->find(value);
    this->remove(pointer);
}

std::ostream & operator<<(std::ostream & os, const LinkedList& list) {
    for (auto it = list.begin(); it != list.end();) {
        os << *it << std::endl;
        it = it->getNext();
    }
    return os;
}
