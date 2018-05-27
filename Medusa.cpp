//
//  Medusa.cpp
//  project4
//
//  Created by Andrew Joseph on 5/23/18.
//  Copyright © 2018 Andrew Joseph. All rights reserved.
//


#include "Medusa.hpp"

using namespace std;

Medusa::Medusa() : Character(2, 6, 1, 6, 3, 8) {
    
}

//overloaded attack so if medusa rolls a 12 she automattically kills other player
int Medusa::attack() {
    int roll = Character::attack();
    if (roll == 12) {
        cout << "*** Medusa Glare ***" << endl;
        roll = 100;
    }
    return roll;
    
    
}

string Medusa::getType() {
    return "Medusa";
}

Medusa::~Medusa() {
    
}

