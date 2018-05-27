//
//  Barbarian.hpp
//  project4
//
//  Created by Andrew Joseph on 5/23/18.
//  Copyright © 2018 Andrew Joseph. All rights reserved.
//

#ifndef Barbarian_hpp
#define Barbarian_hpp

#include <stdio.h>
#include <string>
#include "Character.hpp"

using namespace std;

class Barbarian: public Character {
private:
    
public:
    Barbarian();
    string getType();
    ~Barbarian();
};

#endif /* Barbarian_hpp */

