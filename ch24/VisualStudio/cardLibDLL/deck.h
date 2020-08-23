//Deck class
//  -- from _C++20 for Lazy Programmers_

#ifndef DECK_H
#define DECK_H

#include "cardgroup.h"

namespace cards
{
    class Deck: private CardGroup
    {
    public:
        static constexpr int MAX_SIZE = 52;

        DECLSPEC Deck ();
        Deck (const Deck& other) = delete;

        Card deal    ()              {  return removeTop ();         }

        DECLSPEC void shuffle ();

        void print(std::ostream& out) const { CardGroup::print(out); }

        int  size    () const        { return CardGroup::size   ();  }
        bool isEmpty () const        { return CardGroup::isEmpty();  } 
        bool isFull  () const        { return CardGroup::isFull ();  }
        void addCard (const Card& c) { CardGroup::addCard(c);        }
    };

    inline
    std::ostream& operator<< (std::ostream& out, const Deck& foo)
    {
        foo.print (out); return out;
    }
} //namespace cards
#endif //DECK_H
