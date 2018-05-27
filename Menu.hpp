//
//  Menu.hpp
//  project4
//
//  Created by Andrew Joseph on 5/23/18.
//  Copyright © 2018 Andrew Joseph. All rights reserved.
//

#ifndef Menu_hpp
#define Menu_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>

#include "Character.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "LinkedListContainers.hpp"

class Menu {
private:
    // fighter 1 and fighter 2
    Character* c1;
    Character* c2;
public:
    void play();    // main memu and sent to fight
    bool checkDigits(std::string input); // integer validation
    void fight(Character* c1, Character* c2); // send 2 fighters to fight
};

#endif /* Menu_hpp */

