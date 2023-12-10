#ifndef SLOTMASHINE_CPP
#define SLOTMASHINE_CPP
#include "constants.hpp"
#include "slotmashine.hpp"

using namespace std;

SlotMashine::SlotMashine(int start_coins) {
  for(int i = 0; i < SLOTS; i++) {
    this->wheels[i] = ' ';
  }
  coinsLeft = start_coins;
  currentBet = 0;
}

SlotMashine::~SlotMashine() {
  for(int i = 0; i < SLOTS; i++) {
    this->wheels[i] = ' ';
  }
}

void SlotMashine::insertCoin() {
  if(this->coinsLeft > 0) {
    currentBet++;
    coinsLeft--;
  }
}

/*void SlotMashine::checkWin() {
  int coins = 1;

  int s1 = this->wheels[0];
  int s2 = this->wheels[1];
  int s3 = this->wheels[2];

  int m = 0, _;

  if (s1 == s2 && s2 == s3) {
    SlotMashine::getSlotValue(s1, _, m);
    this->won = true;
  }
  else if (s1 == s2 || s2 == s3 || s1 == s3) {
    SlotMashine::getSlotValue(s1, m, _);
  }
  coins *= m;

  if (s1 == VALUE_9 || s2 == VALUE_9 || s3 == VALUE_9) {
    coins = 0;
  }
  this->lastWin = coins;
  this->money += coins;
}*/
#endif