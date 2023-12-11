#ifndef SLOTMACHINE_CPP
#define SLOTMACHINE_CPP
#include "constants.hpp"
#include "slotMachine.hpp"

using namespace std;

SlotMachine::SlotMachine(int startCoins) {
  for(int i = 0; i < SLOTS; i++) {
    wheels[i] = ' ';
  }
  coinsLeft = startCoins;
  currentBet = 0;
  winJustHappened = false;
}

SlotMachine::~SlotMachine() {
  for(int i = 0; i < SLOTS; i++) {
    wheels[i] = ' ';
  }
}

void SlotMachine::insertCoin() {
  if(coinsLeft > 0) {
    currentBet++;
    coinsLeft--;
  }
}

void SlotMachine::spin() {
  if(currentBet > 0) {
    print_pleaseWait();

    int horizOffset = 0;
    char symbol;

    for(int i = 0; i < 3; i++) {
      for(int j = 1; j <= 199; j++) {
        Sleep(1);

        if (j % 5 == 0) {
          int index = (rand() % WHEEL_SIZE);
          symbol = ALL_SYMBOLS[index];
          printSpin(horizOffset, symbol);
        }
      }
      horizOffset += 6;
      wheels[i] = symbol;
    }
    int mulitiplier = 0;

    if(wheels[0] == wheels[1] || wheels[1] == wheels[2] || wheels[0] == wheels[2]) {
      mulitiplier = 2;
    }
    else if(wheels[0] == wheels[1] && wheels[1] == wheels[2]) {
      mulitiplier = 3;
    }
    int award = currentBet * mulitiplier;
    coinsLeft += award;
    bool isGameOver = (award == 0 && coinsLeft == 0);
    
    if(!isGameOver) {
      print_cToContinue(award, currentBet);
      char keyPress;
      while ((keyPress = getch()) != 'c' && keyPress != 'C') {
        cout << "";
      }
    }
    else {
      print_eToExit();
      char keyPress;
      while ((keyPress = getch()) != 'e' && keyPress != 'E') {
        cout << "";
      }
      exit(0);
    }
    currentBet = 0;
  }
}

void SlotMachine::printAll() {
  print_machine();
  print_menuControls();
}

void SlotMachine::print_machine() {
  addstr(
  "                                         \n"
  "                                         \n"
  "                                         \n"
  "         _______________________         \n"
  "         | ___________________ |         \n"
  "         | |     |     |     | |         \n"
  "         | |     |     |     | |         \n"
  "         | |_____|_____|_____| |         \n"
  "         |_____________________|         \n"
  "             |             |             \n"
  "             |             |             \n"
  "    _________|_____________|__________   \n"
  "    |                                |   \n"
  "    |                                |   \n"
  "    |                                |   \n"
  "    |                                |   \n"
  "    |________________________________|   \n"
  );
  mvprintw(15, 11, "Coins left:  %6i", coinsLeft);
  mvprintw(13, 11, "Current bet: %6i", currentBet);
  refresh();
}

void SlotMachine::print_menuControls() {
  mvprintw(18, 11, "Insert coin ----> I");
  mvprintw(19, 11, "Spin machine ---> S");
  mvprintw(20, 11, "Exit program ---> E");
  refresh();
}

void SlotMachine::print_pleaseWait() {
  mvprintw(18, 10, "     Please wait     ");
  mvprintw(19, 0, "%50s", "");
  mvprintw(20, 10, "                     ");
  refresh();
}

void SlotMachine::print_cToContinue(int award, int currentBet) {
  if(award > 0) {
    mvprintw(18, 6, "Congrats! You just won %d coins", award);
  }
  else {
    mvprintw(18, 10, "You just lost %d coins", currentBet);
  }
  mvprintw(19, 0, "%50s", "");
  mvprintw(20, 11, "Press C to continue");
  refresh();
}

void SlotMachine::print_eToExit() {
  mvprintw(18, 11, "You're out of coins!");
  mvprintw(19, 0, "%50s", "");
  mvprintw(20, 8, "Press E to exit the program");
  refresh();
}

void SlotMachine::printSpin(int horizOffset, char symbol) {
  mvaddch(6, 14 + horizOffset, symbol);
  refresh();
}
#endif