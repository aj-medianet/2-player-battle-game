//
//  Node.cpp
//  project4
//
//  Created by Andrew Joseph on 5/24/18.
//  Copyright © 2018 Andrew Joseph. All rights reserved.
//

#include "Node.hpp"

using namespace std;

//sets value inside node
void Node::setVal(Character* c) {
    this->c = c;
}

//returns value inside node
Character& Node::getVal() {
    return *this->c;
}

//sets previous node
void Node::setPrev(Node* n) {
    this->prev = n;
}

//sets next node
void Node::setNext(Node* n) {
    this->next = n;
}

//returns next node
Node& Node::getNext() {
    return *this->next;
}

//returns previous node
Node& Node::getPrev() {
    return *this->prev;
}
