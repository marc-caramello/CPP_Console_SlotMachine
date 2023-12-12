#ifndef MAIN_CPP
#define MAIN_CPP

#include <array>
#include <fstream>
#include <iostream>
#include <pdcurses/curses.h>
#include <string>
#include <cwchar>
#include <Windows.h>
#include "constants.hpp"
#include "slotMachine.hpp"

using namespace std;

int main() {
  srand(time(0));
  setlocale(LC_ALL, "");
  initscr();
  curs_set(0);
  noecho();
  cbreak();
  clear();
  keypad(stdscr, true);

  SlotMachine slotMachine(START_COINS);
  bool run = true;
  int key = '?';

  while(run) {
    slotMachine.printAll();
    key = getch();

    if(key == 'i' || key == 'I') {
      slotMachine.insertCoin();
    }
    else if(key == 's' || key == 'S') {
      slotMachine.spin();
    }
    else if(key == 'e' || key == 'E') {
      run = false;
    }
    clear();
    key = '?';
  }
  return 0;
}

#endif