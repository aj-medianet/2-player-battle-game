//
//  Vampire.cpp
//  project4
//
//  Created by Andrew Joseph on 5/23/18.
//  Copyright © 2018 Andrew Joseph. All rights reserved.
//

#include "Vampire.hpp"

using namespace std;

Vampire::Vampire() : Character(1, 12, 1, 6, 1, 18) {
    
}

//50% chance attacker doesn't hurt vampire
void Vampire::updateStrengthPoints(int damage) {
    int charmChance = (rand() % 2) + 1; // get random number 1 or 2
    if (charmChance == 1) {
        damage = 0;
        cout << endl << "*** Vampire Charmed Attacker ***" << endl << endl;
    }
    return Character::updateStrengthPoints(damage);
}

string Vampire::getType() {
    return "Vampire";
}

Vampire::~Vampire() {
    
}
