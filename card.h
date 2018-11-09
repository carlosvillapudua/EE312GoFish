//File Name: card.h
//
//Written by Owen Astrachan and Roger Priebe
// This class represents a playing card, i.e., "ace of spades"
// a Card is constructed from a rank (int in range 1..13)
// and a suit (Card::spades, Card::hearts, Card::diamonds,
// Card::clubs)
//
// Cards should be created by a Deck (see deck.h), a Deck returns
// good cards
// The function toString() converts a card to a string, e.g., to print
//
// Accessor functions include
//
// int GetRank()      -- returns 1, 2, ..., 13 for ace, two, ..., king
//
// bool SameSuitAs(c) -- returns true if same suit as Card c
//
// string suitString() -- returns "s", "h", "d" or "c"
//
// Note that the Ace is represented by 1 and the King by 13
/*

Rithvik Baddam (rrb2442) and Carlos Villapudua (civ298)
Date:   11/05/18

*/

#ifndef _CARD_H
#define _CARD_H

#include <iostream>
#include <string>
using namespace std;

class Card
{
public:
    enum Suit {spades, hearts, diamonds, clubs};

    /* FUNCTION - Card
        *creates a default card -- ACE oF SPADES

        input parms - none

        output parms - none
     */
    Card();          // default, ace of spades


    /* FUNCTION - Card, int rank, Suit s
        *creates a card of specified rank and suit

        input parms - rank instance of card and suit instance of card

        output parms - none
     */
    Card(int rank, Suit s);


    /* FUNCTION - string toString
        *prints out stitched string of rank (A, 4, J, etc.) and suit (c for clubs, h for hearts)

        input parms - none, but is done for the instance of the card that calls it

        output parms - string representation of  suit and rank
     */
    string toString()              const;  // return string version e.g. Ac 4h Js


    /* FUNCTION - Card
        *checks if card passed as input has same suit as card that calls function

        input parms - address of instance card to compare suit with

        output parms - true if cards have same suit, false if not
     */
    bool sameSuitAs(const Card& c) const;  // true if suit same as c


    /* FUNCTION - getRank
        *returns rank of card (1, 2, 3, .... 13)

        input parms - integer representation of card's rank

        output parms - none
     */
    int  getRank()                 const;  // return rank, 1..13


    /* FUNCTION - suitString, suit S
        *returns string representation of card's suit --- "s" or "h", etc.

        input parms - suit of card of suit datatype

        output parms - string rep. of card's suit
     */
    string suitString(Suit s)      const;  // return "s", "h",...


    /* FUNCTION - rankString, int r
        *returns string representation of card's rank --- "A", "5", "Q",....

        input parms - integer rep. of card's rank

        output parms - string rep. of card rank
     */
    string rankString(int r)       const;  // return "A", "2", ..."Q"


    /* FUNCTION - operator ==
    *defines protocol for how to use == operator between two cards

    input parms - card to compare with card that calls function

    output parms - true if cards match, false if not
    */
    bool operator == (const Card& rhs) const;


    /* FUNCTION - operator !=
    *defines protocol for how to use != operator between two cards

    input parms - card to compare with card that calls function

    output parms - false if cards match, true if not
    */
    bool operator != (const Card& rhs) const;

private:

    int myRank;
    Suit mySuit;


};

ostream& operator << (ostream& out, const Card& c);



#endif
