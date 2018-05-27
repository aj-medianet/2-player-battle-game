//
//  HarryPotter.cpp
//  project4
//
//  Created by Andrew Joseph on 5/23/18.
//  Copyright © 2018 Andrew Joseph. All rights reserved.
//

#include "HarryPotter.hpp"

HarryPotter::HarryPotter() : Character(2, 6, 2, 6, 0, 10) {
    this->extraLife = true;
}

//overloaded updateStrengthPoints for HP extra life
//if harry potter dies once, use extra life once, set strength to 20, extra life to false so can't use extra life again
void HarryPotter::updateStrengthPoints(int damage) {
    Character::updateStrengthPoints(damage);
    
    int sp = this->getStrengthPoints();
    if (sp <= 0 && extraLife) {
        cout << endl << "*** Harry Potter Extra Life ***" << endl << endl;
        this->extraLife = false;
        this->setStrengthPoints(20);
    }
}

string HarryPotter::getType() {
    return "Harry Potter";
}

HarryPotter::~HarryPotter() {
    
}

