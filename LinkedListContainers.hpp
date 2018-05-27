//
//  LinkedListContainers.hpp
//  project4
//
//  Created by Andrew Joseph on 5/24/18.
//  Copyright © 2018 Andrew Joseph. All rights reserved.
//

#ifndef LinkedListContainers_hpp
#define LinkedListContainers_hpp

#include <stdio.h>
#include <iostream>
#include "Node.hpp"
#include "Character.hpp"

class LinkedListContainers {
private:
    Node* head;
    Node* tail;
public:
    LinkedListContainers();
    void addHead(Character* c);
    void addTail(Character* c);
    void deleteHead();
    void deleteTail();
    void print();
    Character* getHead();
    ~LinkedListContainers();
};

#endif /* LinkedListContainers_hpp */
