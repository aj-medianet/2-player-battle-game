//
//  BlueMen.cpp
//  project4
//
//  Created by Andrew Joseph on 5/23/18.
//  Copyright © 2018 Andrew Joseph. All rights reserved.
//

#include "BlueMen.hpp"

BlueMen::BlueMen() : Character(2, 10, 3, 6, 3, 12) {
    
}

//sets defense die according to strength points left
void BlueMen::setDefense() {
    if (Character::getStrengthPoints() <= 8) {
        Character::setDefense(2, 6);
    }
    if (Character::getStrengthPoints() <= 4) {
        Character::setDefense(1, 6);
    }
}

int BlueMen::getStrengthPoints() {
    setDefense();
    return Character::getStrengthPoints();
}

string BlueMen::getType() {
    return "Blue Men";
}

BlueMen::~BlueMen() {
    
}

