#ifndef SLOTMASHINE_HPP
#define SLOTMASHINE_HPP

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

class SlotMashine {
  public:
    int coinsLeft;
    int currentBet;
    char wheels[SLOTS];
    SlotMashine(int);
    ~SlotMashine();
    void insertCoin();
  private:
    void checkWin();
};
#endif