//
//  HarryPotter.hpp
//  project4
//
//  Created by Andrew Joseph on 5/23/18.
//  Copyright © 2018 Andrew Joseph. All rights reserved.
//

#ifndef HarryPotter_hpp
#define HarryPotter_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "Character.hpp"


class HarryPotter : public Character {
private:
    bool extraLife;
public:
    HarryPotter();
    void useExtraLife();
    bool getExtraLife();
    void updateStrengthPoints(int damage);
    std::string getType();
    ~HarryPotter();
};

#endif /* HarryPotter_hpp */

