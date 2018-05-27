//
//  Character.cpp
//  project4
//
//  Created by Andrew Joseph on 5/23/18.
//  Copyright © 2018 Andrew Joseph. All rights reserved.
//

#include "Character.hpp"

using namespace std;

Character::Character(int attackDie, int attackDieSides, int defenseDie, int defenseDieSides, int armor, int strengthPoints) {
    setAttack(attackDie, attackDieSides);
    setDefense(defenseDie, defenseDieSides);
    setArmor(armor);
    setStrengthPoints(strengthPoints);
}

//gets attackers die roll
int Character::attack() {
    int die = this->attackDie;
    int dieRoll = 0;
    while (die > 0) {
        dieRoll += (rand() % this->attackDieSides) + 1; // add random roll between 1 and number of sides
        die--; // count down from number of dies they got
    }
    return dieRoll;
}

//returns defenders die roll
int Character::defend() {
    int die = this->defenseDie;
    int dieRoll = 0;
    while (die > 0) {
        dieRoll += (rand() % this->defenseDieSides) + 1; // add random roll between 1 and number of sides
        die--; // count down from number of dies they got
    }
    return dieRoll;
}

//sets up attack dies and sides
void Character::setAttack(int attackDie, int attackDieSides) {
    this->attackDie = attackDie;
    this->attackDieSides = attackDieSides;
}

//sets up defense dies and sides
void Character::setDefense(int defenseDie, int defenseDieSides) {
    this->defenseDie = defenseDie;
    this->defenseDieSides = defenseDieSides;
}

void Character::setArmor(int armor) {
    this->armor = armor;
}

void Character::setStrengthPoints(int strengthPoints) {
    this->strengthPoints = strengthPoints;
}

int Character::getArmor() {
    return this->armor;
}

int Character::getStrengthPoints() {
    return this->strengthPoints;
}

//subtract damage from strength points to get updated strength pints
void Character::updateStrengthPoints(int damage) {
    this->strengthPoints -= damage;
}

void Character::setName(string name) {
    this->name = name;
}

string Character::getName() {
    return this->name;
}

//gives character a bump in strength if they win a round
void Character::increaseStrengthPoints() {
    //adds 50% of current strength points to strength points
    int bump = strengthPoints * (.5);
    this->strengthPoints += bump;
}

Character::~Character() {
    
}
