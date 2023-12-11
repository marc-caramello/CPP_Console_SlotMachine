#ifndef SlotMachine_HPP
#define SlotMachine_HPP

#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <pdcurses/curses.h>
#include <stdlib.h>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <windows.h>
#include "constants.hpp"

using namespace std;

class SlotMachine {
  public:
    int coinsLeft;
    int currentBet;
    bool winJustHappened;
    char wheels[SLOTS];

    SlotMachine(int startCoins);
    ~SlotMachine();
    
    void insertCoin();
    void spin();

    // Print the entire screen
    void printAll();
    void print_machine();

    // Print bottom message
    void print_menuControls();
    void print_pleaseWait();
    void print_cToContinue(int award, int currentBet);
    void print_eToExit();
    
    // Print small changes
    void printSpin(int horizOffset, char symbol);
};
#endif