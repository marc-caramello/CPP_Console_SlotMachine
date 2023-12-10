#ifndef SLOTMASHINEVIEW_HPP
#define SLOTMASHINEVIEW_HPP

#include <array>
#include <pdcurses/curses.h>
#include "constants.hpp"
#include "slotmashine.hpp"

using namespace std;

class SlotMashineView {
  private:
    SlotMashine* slotMashine;
    int lightFrame;
    int leverFrame;
    int coinFrame;
    int coinsFrame;
    bool blink;

  public:
    SlotMashineView(SlotMashine*);
    ~SlotMashineView();
    void spin();
    void print();

  private:
    void printBase();
    void printScreen();
    void printMoney();
    void printHelp();
    void removeHelp();
};
#endif