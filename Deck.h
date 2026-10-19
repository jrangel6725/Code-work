#ifndef DECK_H
#define DECK_H

#include "Hand.h"

class Deck : public Hand
{
public:
    Deck();

    void populate();
    void shuffle();
    void deal(Hand& hand);
};

#endif
