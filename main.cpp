//
//  main.cpp
//  project4
//
//  Created by Andrew Joseph on 5/23/18.
//  Copyright © 2018 Andrew Joseph. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>

#include "Menu.hpp"

using namespace std;


int main(int argc, const char * argv[]) {
    Menu* m = new Menu();
    srand((unsigned)time(0)); //creates random once so can use multiple times
    //starts the game
    m->play();
    
    delete m;
    
    return 0;
}
