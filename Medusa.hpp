//
//  Medusa.hpp
//  project4
//
//  Created by Andrew Joseph on 5/23/18.
//  Copyright © 2018 Andrew Joseph. All rights reserved.
//

#ifndef Medusa_hpp
#define Medusa_hpp

#include <stdio.h>
#include <string>
#include "Character.hpp"


class Medusa: public Character {
private:
    
public:
    Medusa();
    int attack();
    std::string getType();
    ~Medusa();
};

#endif /* Medusa_hpp */

