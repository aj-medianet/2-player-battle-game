//
//  LinkedListContainers.cpp
//  project4
//
//  Created by Andrew Joseph on 5/24/18.
//  Copyright © 2018 Andrew Joseph. All rights reserved.
//

#include "LinkedListContainers.hpp"

using namespace std;

LinkedListContainers::LinkedListContainers() {
    //initialize empty list
    head = tail = NULL;
}

void LinkedListContainers::addHead(Character* c) {
    //if list is empty
    if (head == NULL && tail == NULL) {
        Node* tmp = new Node();
        tmp->setVal(c);
        tmp->setNext(tmp);
        tmp->setPrev(tmp);
        head = tmp;
        tail = tmp;
        //else create new head node
    } else {
        Node* tmp = new Node();
        tmp->setVal(c);
        tmp->setNext(head);
        head->setPrev(tmp);
        tmp->setPrev(tail);
        tail->setNext(tmp);
        head = tmp;
    }
}

//adds tail node
void LinkedListContainers::addTail(Character* c) {
    //if list is empty
    if (tail == NULL && head == NULL) {
        Node* tmp = new Node();
        tmp->setVal(c);
        tmp->setNext(tmp);
        tmp->setPrev(tmp);
        tail = tmp;
        head = tmp;
        // else create new tail node
    } else {
        Node* tmp = new Node();
        tmp->setVal(c);
        tmp->setPrev(tail);
        tail->setNext(tmp);
        tmp->setNext(head);
        head->setPrev(tmp);
        tail = tmp;
    }
}

//deletes head node
void LinkedListContainers::deleteHead() {
    if (head == NULL) {
        cout << endl << "Sorry the list is empty" << endl;
    } else {
        Node* deleteNode = head;
        head = &deleteNode->getNext();
        // if only one node left
        if (head == deleteNode) {
            delete deleteNode;
            head = tail = NULL;
        } else {
            head->setPrev(tail);
            tail->setNext(head);
            delete deleteNode;
        }
    }
    
    
}

//deletes tail node
void LinkedListContainers::deleteTail() {
    if (tail == NULL) {
        cout << endl << "Sorry the list is empty" << endl;
    } else {
        Node* deleteNode = tail;
        tail = &deleteNode->getPrev();
        //if only one node left
        if(tail == deleteNode) {
            delete deleteNode;
            head = tail = NULL;
        } else {
            tail->setNext(head);
            head->setPrev(tail);
            delete deleteNode;
        }
    }
}

//prints out the list
void LinkedListContainers::print() {
    Node* iter = head;
    cout << endl << endl;
    if (head != NULL) {
        do {
            cout << &iter->getVal() << " ";
            iter = &iter->getNext();
        } while(iter != head);
    }
    cout << endl << endl;
}


LinkedListContainers::~LinkedListContainers() {
    delete head;
    delete tail;
}
