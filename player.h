// FILE:  player.h
// written by Roger Priebe
// 1/22/08 (revised 9/2/08)
// This class represents a player in a card game that takes "tricks"
// The "Books" represent a container for holding tricks

/*

Rithvik Baddam (rrb2442) and Carlos Villapudua (civ298)
Date:   11/05/18



*/

#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include <string>
#include <vector>


#include "card.h"
using namespace std;


class Player
{

public:
    /* FUNCTION - Player
       *creates a default player with no name

       input parms - none

       output parms - none
    */
    Player();

    /* FUNCTION - Player (string name)
       *creates a default player with input name

       input parms - string of player's name

       output parms - none
    */
    Player(string name) {
        myName = name;
    }



    /* FUNCTION - string getName
      *returns name of player that called function

    input parms - none

    output parms - string of players name
    */
    string getName() const {
        return myName;
    }



    /* FUNCTION - addCard (Card c)
  *add card to player hand

  input parms - Card type from deck

  output parms - none
*/
    void addCard(Card c);  //adds a card to the hand



    /* FUNCTION - bookCards(Card c1, Card c2)
      *adds two cards to the book

      input parms - cards to put into book

      output parms - none

      pre: cards passed are of the same rank and are in player's hands
      post: cards are removed from player hand
   */
    void bookCards(Card c1, Card c2);


    //OPTIONAL
    // comment out if you decide to not use it
    //Does the player have a card with the same rank as c in her hand?
    /* FUNCTION - rankInHand(card c)
      *checks if card in players hand has a certain rank

      input parms - card to check for rank

      output parms - true if a card with specified rank exists, false otherwise

      pre: hand is not empty
      post: none
   */
    bool rankInHand(Card c) const;


    //uses some strategy to choose one card from the player's
    //hand so they can say "Do you have a 4?"
    /* FUNCTION - Card chooseCardFromHand
      *randomly selects card from hand

      input parms - none

      output parms - randomly selected card from hand

      pre: hand is not empty
      post: random card has been chosen from hand
   */
    Card chooseCardFromHand() const;


    //Does the player have the card c in her hand?
    /* FUNCTION -  bool cardInHAnd(card C)
      *looks for matching card in players hand

      input parms - cards to compare with card that called function

      output parms - true if card exists in players hand, false otherwise

      pre: there must be card in player's hand
      post: none
   */
    bool cardInHand(Card c) const;


    //Remove the card c from the hand and return it to the caller
    /* FUNCTION - Card removeCardFromHand (Card c)
      *removes specified card from players hand

      input parms - card (with certain rank and suit)to remove from player hand

      output parms - card that has been removed from player hand

      pre: card passed in through function exists in player's hand
      post: card is removed from player hand
   */
    Card removeCardFromHand(Card c);


    /* FUNCTION - string showHand
      *shows the cards that are in player hand

      input parms - none

      output parms - string rep. of each card in hand

      pre: none
      post: cards existing in hand are returned in a string
   */
    string showHand() const;


    /* FUNCTION - string showBooks
      *returns a string rep. of books that belong to a single player

      input parms - none

      output parms - string rep.of books of player

      pre: none
      post: books in players hand are rep. by string and returned
   */
    string showBooks() const;


    /* FUNCTION - int getHandSize
      *returns int value of how many cards are in player hand

      input parms - none

      output parms - integer value of how many cards in player hand

      pre: none
      post: none
   */
    int getHandSize() const;


    /* FUNCTION - int getBookSize
      *returns int value of how many books player has

      input parms - none

      output parms - integer value of how many books player has

      pre: none
      post: none
   */
    int getBookSize() const;


    //OPTIONAL
    // comment out if you decide to not use it
    //this function will check a players hand for a pair.
    //If a pair is found, it returns true and populates the two variables with the cards tha make the pair.
    /* FUNCTION - bool checkHandForPair (Card &cl, Card &c2)
      *returns boolean value based on if hand has a pair or not

      input parms - cards to populate possible pair into

      output parms - true if there exists a pair in hand, false if otherwise

      pre: none
      post: c1 and c2 are populated with cards that match -- if no cards match, then cards have nonsense in them
   */
    bool checkHandForPair(Card &c1, Card &c2);


private:

    vector <Card> myHand;
    vector <Card> myBook;

    string myName;

};

#endif







