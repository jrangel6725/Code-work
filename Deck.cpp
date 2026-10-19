#include "Deck.h"
#include <algorithm>
#include <random>

Deck::Deck()
    : Hand()
{
    populate();
}

void Deck::populate()
{
    for (int suit = Card::CLUBS; suit <= Card::SPADES; ++suit)
    {
        for (int rank = Card::ACE; rank <= Card::KING; ++rank)
        {
            add(new Card(
                static_cast<Card::RANK>(rank),
                static_cast<Card::SUIT>(suit)
            ));
        }
    }
}

void Deck::shuffle()
{
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());

    std::shuffle(cardVector.begin(), cardVector.end(), generator);
}

void Deck::deal(Hand& hand)
{
    if (!cardVector.empty())
    {
        hand.add(cardVector.back());
        cardVector.pop_back();
    }
}
