//
//  Character.hpp
//  project4
//
//  Created by Andrew Joseph on 5/23/18.
//  Copyright © 2018 Andrew Joseph. All rights reserved.
//

#ifndef Character_hpp
#define Character_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


class Character {
private:
    int attackDie, attackDieSides, defenseDie, defenseDieSides, armor, strengthPoints;
    std::string name;
public:
    Character(int attackDie, int attackDieSides, int defenseDie, int defenseDieSides, int armor, int strengthPints);
    virtual int attack();
    int defend();
    //set funcitons
    void setAttack(int attackDie, int attackDieSides);
    virtual void setDefense(int defenseDie, int defenseDieSides);
    void setArmor(int armor);
    virtual void setStrengthPoints(int strengthPoints);
    // change strength points
    virtual void updateStrengthPoints(int damage);
    //get functions
    virtual int getArmor();
    virtual int getStrengthPoints();
    
    
    //returns type of character
    virtual std::string getType(void) = 0;
    
    //set name and get name of character that user sets
    void setName(std::string name);
    std::string getName();
    
    
    virtual ~Character();
};

#endif /* Character_hpp */
