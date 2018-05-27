//
//  Barbarian.cpp
//  project4
//
//  Created by Andrew Joseph on 5/23/18.
//  Copyright © 2018 Andrew Joseph. All rights reserved.
//

#include "Barbarian.hpp"

using namespace std;

Barbarian::Barbarian() : Character(2, 6, 2, 6, 0 ,12) {
    
}

string Barbarian::getType() {
    return "Barbarian";
}

Barbarian::~Barbarian() {
    
}

