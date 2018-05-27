//
//  Vampire.hpp
//  project4
//
//  Created by Andrew Joseph on 5/23/18.
//  Copyright © 2018 Andrew Joseph. All rights reserved.
//

#ifndef Vampire_hpp
#define Vampire_hpp

#include <stdio.h>
#include <string>
#include "Character.hpp"

using namespace std;

class Vampire: public Character {
private:
public:
    Vampire();
    virtual void updateStrengthPoints(int damage);
    string getType();
    ~Vampire();
};

#endif /* Vampire_hpp */

