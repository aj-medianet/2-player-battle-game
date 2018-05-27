//
//  Menu.cpp
//  project4
//
//  Created by Andrew Joseph on 5/23/18.
//  Copyright © 2018 Andrew Joseph. All rights reserved.
//

#include "Menu.hpp"

using namespace std;

void Menu::play() {
    string input;
    int play = 0;
    LinkedListContainers team1, team2, losers;
    
    // prompt user to play or quit
    while(!(play == 1 || play == 2)) {
        cout << "1. Play" << endl << "2. Quit" << endl;
        getline(cin, input);
        if (checkDigits(input)) {
            stringstream(input) >> play;
        }
        if (!(play == 1 || play == 2)) {
            cout << "Invalid input. Choose 1 or 2" << endl;
        }
    }
    
    // user chose to play - so play
    if (play == 1) {
        //play until user chooses to quit
        while(true) {
            int lineup1 = 0, lineup2 = 0;
            int menuChoice = 0;
            int playAgain = 0;
            
            /******************************************
             Choose number of fighters for each team
             ******************************************/
            while (!(lineup1 > 0)) {
                cout << "Choose number of fighters for Team 1: ";
                getline(cin, input);
                if (checkDigits(input) ) {
                    stringstream(input) >> lineup1;
                }
                // if input is not greater than 0
                if (!(lineup1 > 0)) {
                    cout << "Invalid Input. Choose a positive integer." << endl;
                }
            }
            
            while (!(lineup2 > 0)) {
                cout << "Choose number of fighters for Team 2: ";
                getline(cin, input);
                if (checkDigits(input) ) {
                    stringstream(input) >> lineup2;
                }
                // if input is not greater than 0
                if (!(lineup2 > 0)) {
                    cout << "Invalid Input. Choose a positive integer." << endl;
                }
            }
            
            /******************************************
             Create linked lists from number of fighters
             ******************************************/
            
            //lineup 1 - create list, choose fighter type and set fighter name
            cout << endl << "Team 1" << endl;
            while (lineup1 > 0) {
                //reset menu choice
                menuChoice = 0;

                //choose first fighter
                while (!(menuChoice == 1 || menuChoice == 2 || menuChoice == 3 || menuChoice == 4 || menuChoice == 5)) {
                    cout << endl << endl << "Choose type of character to fight" << endl;
                    cout << "1. Vampire" << endl << "2. Barbarian" << endl << "3. Blue Man" << endl << "4. Medusa" << endl << "5. Harry Potter" << endl;
                    getline(cin, input);
                    if (checkDigits(input) ) {
                        stringstream(input) >> menuChoice;
                    }
                    if (!(menuChoice == 1 || menuChoice == 2 || menuChoice == 3 || menuChoice == 4 || menuChoice == 5)) {
                        cout << "Invalid input. Please choose 1, 2, 3, 4 or 5" << endl;
                    }
                }
                
                //create fighter 1
                switch (menuChoice) {
                    case 1: {
                        c1 = new Vampire();
                        break;
                    }
                    case 2: {
                        c1 = new Barbarian();
                        break;
                    }
                    case 3: {
                        c1 = new BlueMen();
                        break;
                    }
                    case 4: {
                        c1 = new Medusa();
                        break;
                    }
                    case 5: {
                        c1 = new HarryPotter();
                        break;
                    }
                    default:
                        break;
                }
                
                //set name of fighter with user input
                cout << "Enter name of fighter: ";
                getline(cin, input);
                c1->setName(input);
                
                //add fighter to container
                team1.addTail(c1);

                //decrement lineup1
                lineup1--;
            }
            
            //test print of team1 lineup
            team1.print();
            
            
            //lineup 2 - create list, choose fighter type and set fighter name
            cout << endl << "Team 2" << endl;
            while (lineup2 > 0) {
                //reset menu choice
                menuChoice = 0;
            
                // choose second fighter
                menuChoice = 0;
                while (!(menuChoice == 1 || menuChoice == 2 || menuChoice == 3 || menuChoice == 4 || menuChoice == 5)) {
                    cout << endl << endl << "Choose type of character to fight" << endl;
                    cout << "1. Vampire" << endl << "2. Barbarian" << endl << "3. Blue Man" << endl << "4. Medusa" << endl << "5. Harry Potter" << endl;
                    getline(cin, input);
                    if (checkDigits(input) ) {
                        stringstream(input) >> menuChoice;
                    }
                    if (!(menuChoice == 1 || menuChoice == 2 || menuChoice == 3 || menuChoice == 4 || menuChoice == 5)) {
                        cout << "Invalid input. Please choose 1, 2, 3, 4 or 5" << endl;
                    }
                }
                
                //create fighter 2
                switch (menuChoice) {
                    case 1:
                        c2 = new Vampire();
                        break;
                    case 2:
                        c2 = new Barbarian();
                        break;
                    case 3:
                        c2 = new BlueMen();
                        break;
                    case 4:
                        c2 = new Medusa();
                        break;
                    case 5:
                        c2 = new HarryPotter();
                        break;
                    default:
                        break;
                }
                
                //set name of fighter with user input
                cout << "Enter name of fighter: ";
                getline(cin, input);
                c2->setName(input);
                
                //add fighter to container
                team2.addTail(c2);
                
                //decrement lineup2
                lineup2--;
            }
            
            //test print of team2 lineup
            team2.print();
            
            //while neither list is empty -> fight
            while (team1.getHead() != NULL && team2.getHead() != NULL) {
                //create fighters from the head node
                Character* fighter1 = team1.getHead();
                Character* fighter2 = team2.getHead();
                
                //delete head node
                team1.deleteHead();
                team2.deleteHead();
                
                //send players to fight
                fight(fighter1, fighter2);
                
                //fighter 1 dead - bump fighter 2 strength points, add fighter1 to losers, add fighter2 back to the tail of team2 container
                if (fighter1->getStrengthPoints() <= 0) {
                    fighter2->increaseStrengthPoints();
                    losers.addTail(fighter1);
                    team2.addTail(fighter2);
                }
                //fighter2 head - bump fighter 2 strength points, add fighter2 to losers, add fighter 1 back to tail of team 2 container
                if (fighter2->getStrengthPoints() <= 0) {
                    fighter1->increaseStrengthPoints();
                    losers.addTail(fighter2);
                    team1.addTail(fighter1);
                }
            }
            
            //test prints
            team1.print();
            team2.print();
            
            //if team1 container is empty, team 2 won
            if (team1.getHead() == NULL ) {
                //team 2 wins
                cout << endl << endl << "team2 wins" << endl << endl;
            //if team2 container is empty, team 1 won
            } else {
                //team 1 wins
                cout << endl << endl << "team1 wins" << endl << endl;
            }
            
            //print loser container?
            int loserPrint = 0;
            while(!(loserPrint == 1 || loserPrint == 2)) {
                cout << "1. Print Loser Pile" << endl << "2. Don't Print Loser Pile" << endl;
                getline(cin, input);
                if (checkDigits(input)) {
                    stringstream(input) >> loserPrint;
                }
                if (!(loserPrint == 1 || loserPrint == 2)) {
                    cout << "Invalid input. Choose 1 or 2" << endl;
                }
            }
            if (loserPrint == 1) {
                losers.print();
            }
            
            //delete lists so user can play again if they want
            while (team1.getHead() != NULL) {
                team1.deleteHead();
            }
            while (team2.getHead() != NULL) {
                team2.deleteHead();
            }
            while(losers.getHead() != NULL) {
                losers.deleteHead();
            }
            
           
            
            //delete dynamic memeory
            delete c1;
            delete c2;
            
            // prompt user to play again or quit
            while(!(playAgain == 1 || playAgain == 2)) {
                cout << "1. Play again" << endl << "2. Quit" << endl;
                getline(cin, input);
                if (checkDigits(input)) {
                    stringstream(input) >> playAgain;
                }
                if (!(playAgain == 1 || playAgain == 2)) {
                    cout << "Invalid input. Choose 1 or 2" << endl;
                }
            }
            // if user chooses quit, break out of play loop
            if (playAgain == 2) {
                break;
            }
        }
    }
}

void Menu::fight(Character* c1, Character* c2) {
    int round = 0;
    int damage1 = 0, damage2 = 0;
    int attackc1 = 0, defendc2 = 0, attackc2 = 0, defendc1 = 0;
    
    
    cout << endl << endl << c1->getType() << " (" << c1->getName() << ")" << " vs. " << c2->getType() << " (" << c2->getName() << ")" << endl;
    while (true) {
        round++;
        cout << endl << "--- Round " << round << " ---" << endl << endl;
        
        //print stats
        cout << "Attacker: " << c1->getType() << endl << "Defender: " << c2->getType() << " Armor: " << c2->getArmor() << " Strength Points: " << c2->getStrengthPoints() << endl;
        
        //character 1 attack character 2
        attackc1 = c1->attack();
        defendc2 = c2->defend();
        
        cout << "Attackers dice roll: " << attackc1 << endl;
        cout << "Defenders dice roll: " << defendc2 << endl;
        
        //calculate damage
        damage1 = attackc1 - defendc2 - c2->getArmor();
        cout << "Total infliced damage: " << damage1 << endl;
        
        //subtract inflicted damage from strength points
        if (damage1 > 0) {
            c2->updateStrengthPoints(damage1);
        }
        cout << "Defenders updated strength points: " << c2->getStrengthPoints() << endl << endl;
        
        //if c2 is dead, break out of loop
        if (c2->getStrengthPoints() <= 0) {
            cout << endl << "--- Team 1: " << c1->getType() << " (" << c1->getName() << ")" << " has won ---" << endl << endl;
            break;
        }
        
        //print stats for c2 to attack c1
        cout << "Attacker: " << c2->getType() << endl << "Defender: " << c1->getType() << " Armor: " << c1->getArmor() << " Strength Points: " << c1->getStrengthPoints() << endl;
        
        //c2 attack c1
        attackc2 = c2->attack();
        defendc1 = c1->defend();
        
        cout << "Attackers dice roll: " << attackc2 << endl;
        cout << "Defenders dice roll: " << defendc1 << endl;
        
        //calculate damage
        damage2 = attackc2 - defendc1 - c1->getArmor();
        cout << "Total infliced damage: " << damage2 << endl;
        
        //subtract inflicted damage from strength points
        if (damage2 > 0) {
            c1->updateStrengthPoints(damage2);
        }
        cout << "Defenders updated strength points: " << c1->getStrengthPoints() << endl;
        
        if (c1->getStrengthPoints() <= 0) {
            cout << endl << "--- Team 2: " << c2->getType() << " (" << c2->getName() << ")" << " has won ---" << endl << endl;
            break;
        }
    }
}

//checks input for anything but an integer
bool Menu::checkDigits(string input) {
    for (int i = 0; i < input.length(); i++) {
        if (! ::isdigit(input[i]))
            return false;
    }
    return true;
}

