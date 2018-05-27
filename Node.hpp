//
//  Node.hpp
//  project4
//
//  Created by Andrew Joseph on 5/24/18.
//  Copyright © 2018 Andrew Joseph. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include <iostream>
#include "Character.hpp"

class Node {
private:
    Character* c;
    Node* next;
    Node* prev;
    
public:
    void setVal(Character* c);
    Character& getVal();
    void setPrev(Node* n);
    void setNext(Node* n);
    Node& getNext();
    Node& getPrev();
};


#endif /* Node_hpp */
