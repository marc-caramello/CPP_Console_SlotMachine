#ifndef MAIN_CPP
#define MAIN_CPP

#include <array>
#include <fstream>
#include <iostream>
#include <pdcurses/curses.h>
#include <string>
#include <Windows.h>
#include "constants.hpp"
#include "slotmashine.hpp"
#include "slotmashineview.hpp"

using namespace std;

int main() {
  srand(time(0)); 
  setlocale(LC_ALL, "");
  initscr();
  curs_set(0);
  start_color();
  noecho();
  cbreak();
  clear();
  keypad(stdscr, true);

  SlotMashine* slotMashine = new SlotMashine(START_COINS);
  SlotMashineView* slotMashineView = new SlotMashineView(slotMashine);
  bool run = true;
  int key = '?';

  while(run) {
    slotMashineView->print();
    key = getch();

    if(key == 'i' || key == 'I') {
      slotMashine->insertCoin();
    }
    else if(key == 's' || key == 'S') {
      slotMashineView->spin();
      // CALL CHECKWIN FUNCTION
    }
    else if(key == 'q' || key == 'Q') {
      run = false;
    }
    clear();
    key = '?';
  }
  return 0;
}

#endif