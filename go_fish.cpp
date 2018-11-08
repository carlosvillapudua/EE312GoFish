// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);

void playerTurnAction(Player &pTurn, Player &pAsked, Deck d);


int main( )
{
    // int numCards = 5;
    // Card t(5, Card::clubs);
    // cout << t.toString() << endl ;
    // Card s(5, Card::clubs);
    // if (s != t){
    //     cout << "haha" << endl;
    // }
    // else if ( t == s ){
    //     cout << "no haha" << endl;
    // }

    // Deck p;
    // p.shuffle();
    // p.dealCard();

   int numCards = 7;

   Player p1("Yale Patt");
   Player p2("Ramesh Yerraballi");

   Deck d;  //create a deck of cards
   d.shuffle();

   dealHand(d, p1, numCards);
   dealHand(d, p2, numCards);


   cout << p1.showHand() << endl;
   cout << p2.showHand() << endl;
   cout << "*********************" << endl;
   cout << p1.showBooks() << endl;
   cout << p2.showBooks() << endl;

   while(p1.getBookSize() < 14 && p2.getBookSize() < 14){
    playerTurnAction(p1, p2, d);
    if(p1.getBookSize() < 14){
        playerTurnAction(p2, p1, d);
    }
   }


   // cout << p1.showHand() << endl;
   // cout << p2.showHand() << endl;
   // cout << "*********************" << endl;
   // cout << p1.showBooks() << endl;
   // cout << p2.showBooks() << endl;

   // playerTurnAction(p1, p2, d);

   cout << p1.showHand() << endl;
   cout << p2.showHand() << endl;
   cout << "*********************" << endl;
   cout << p1.showBooks() << endl;
   cout << p2.showBooks() << endl;


   /*p1.bookCards(d.dealCard(), d.dealCard());
   p1.bookCards(d.dealCard(), d.dealCard());
   p1.bookCards(d.dealCard(), d.dealCard());
   p1.bookCards(d.dealCard(), d.dealCard());
   p1.bookCards(d.dealCard(), d.dealCard());
   p1.bookCards(d.dealCard(), d.dealCard());

   cout << p1.getName() <<" has : " << p1.showHand() << endl;
   cout << p2.getName() <<" has : " << p2.showHand() << endl;

   cout << p1.getName() <<" has books:\n" << p1.showBooks() << endl;
   cout << p2.getName() <<" has books:\n" << p2.showBooks() << endl;
   //cout << "Ac, Ac  5s, 5s  Ac, Ac  5s, 5s  Ac, Ac  5s, 5s \nAc, Ac  5s, 5s  Ac, Ac  5s, 5s  Ac, Ac  5s, 5s\n";
   */
    return EXIT_SUCCESS;
}


// booking all possible pairs at once when it is a player's turn
void playerTurnAction(Player &pTurn, Player &pAsked, Deck d){
    Card c1;
    Card c2;

    bool askAgain = true;

    while(askAgain){
        // books all pairs in pTurn's hand
        while(pTurn.checkHandForPair(c1, c2)){
            pTurn.bookCards(c1, c2);
            cout << pTurn.getName() << " books the " << c1.rankString(c1.getRank()) << endl;
            cout << "\n";
            pTurn.removeCardFromHand(c1);
            pTurn.removeCardFromHand(c2);
        }

        //asks pAsked for a card
        Card ask = pTurn.chooseCardFromHand();
        cout << pTurn.getName() << " asks - Do you have a " << ask.rankString(ask.getRank()) << "?" << endl;
        Card getCard;
        if(pAsked.rankInHand(ask)){ // if pAsked has the card with same rank in hand
            cout << pAsked.getName() << " says - Yes, I have a " << ask.rankString(ask.getRank()) << "." << endl;
            getCard = pAsked.removeCardFromHand(ask);
            pTurn.addCard(getCard);
            askAgain = true;
        }
        else{
            cout << pAsked.getName() << " says - Go Fish!" << endl;
            getCard = d.dealCard();
            pTurn.addCard(getCard);
            cout << pTurn.getName() << " draws " << getCard << endl;
            cout << pTurn.showHand() << endl;
            cout << "\n";
            askAgain = false;
        }
    }

}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
       p.addCard(d.dealCard());
}



