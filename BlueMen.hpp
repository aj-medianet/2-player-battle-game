//
//  BlueMen.hpp
//  project4
//
//  Created by Andrew Joseph on 5/23/18.
//  Copyright © 2018 Andrew Joseph. All rights reserved.
//

#ifndef BlueMen_hpp
#define BlueMen_hpp

#include <stdio.h>
#include <string>
#include "Character.hpp"

using namespace std;

class BlueMen: public Character {
private:
    
public:
    BlueMen();
    virtual void setDefense();
    int getStrengthPoints();
    string getType();
    ~BlueMen();
};

#endif /* BlueMen_hpp */

