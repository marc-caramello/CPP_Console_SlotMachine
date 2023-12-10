#ifndef SLOTMASHINEVIEW_CPP
#define SLOTMASHINEVIEW_CPP

#include "constants.hpp"
#include "slotmashine.hpp"
#include "slotmashineview.hpp"

using namespace std;

SlotMashineView::SlotMashineView(SlotMashine* slotMashine) {
  this->slotMashine = slotMashine;
  this->lightFrame = 0;
  this->leverFrame = 0;
  this->coinFrame = -1;
  this->coinsFrame = 0;
  this->blink = false;
}

SlotMashineView::~SlotMashineView() {
  this->slotMashine = NULL;
  this->lightFrame = 0;
  this->leverFrame = 0;
  this->coinFrame = 0;
  this->coinsFrame = 0;
  this->blink = false;
}

void SlotMashineView::spin() {
  this->removeHelp();
  array<int,3> spinResult;
  int horizOffset = 0;
  char symbol;

  for(int i = 0; i < 3; i++) {
    for(int j = 1; j <= 199; j++) {
      Sleep(1);

      if (j % 5 == 0) {
        int index = (rand() % WHEEL_SIZE);
        symbol = ALL_SYMBOLS[index];
        mvaddch(6, 14 + horizOffset, symbol);
        refresh();
      }
    }
    horizOffset += 6;
    this->slotMashine->wheels[i] = symbol;
  }
}

void SlotMashineView::print() {
  this->printBase();     // WORKING
  this->printMoney();    // WORKING
  this->printHelp();     // WORKING
  //this->printScreen();   // NOT WORKING
}

void SlotMashineView::printBase() {
  addstr(
  "                                         \n"
  "                                         \n"
  "                                         \n"
  "        _________________________        \n"
  "        |  ___________________  |        \n"
  "        |  |     |     |     |  |        \n"
  "        |  |     |     |     |  |        \n"
  "        |  |_____|_____|_____|  |        \n"
  "        |_______________________|        \n"
  "             |             |             \n"
  "             |             |             \n"
  "     ________|_____________|_________    \n"
  "    |                                |   \n"
  "    |                                |   \n"
  "    |                                |   \n"
  "    |                                |   \n"
  "    |________________________________|   \n"
  );
  refresh();
}

/*void SlotMashineView::printScreen() {
  if (this->slotMashine->won && this->blink) {
    mvaddstr(23,  13, "  WINNER!  ");
  }
  else if ((this->slotMashine->waiting || this->slotMashine->taking_coin) && this->blink) {
    mvaddstr(23,  19, "Insert Coin");
  }
  else if (this->slotMashine->spinning && this->blink) {
    mvaddstr(23,  13, "Pull  Lever");
  }
  refresh();
}*/

void SlotMashineView::printMoney() {
  mvprintw(15, 11, "Coins left:  %6i", this->slotMashine->coinsLeft);
  mvprintw(13, 11, "Current bet: %6i", this->slotMashine->currentBet);
  refresh();
}

void SlotMashineView::printHelp() {
  mvaddstr(18, 11, "I ----> Insert coin");
  mvaddstr(19, 11, "S ---> Spin machine");
  mvaddstr(20, 11, "Q ---> Exit program");
  refresh();
}

void SlotMashineView::removeHelp() {
  mvaddstr(18, 11, "                   ");
  mvaddstr(19, 11, "                   ");
  mvaddstr(20, 11, "                   ");
  refresh();
}
#endif