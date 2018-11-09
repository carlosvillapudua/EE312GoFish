// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <fstream>
#include <iostream>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards, ofstream& file);

void playerTurnAction(Player &pTurn, Player &pAsked, Deck &d, ofstream& outputFile);

void playerBookCards(Player &pTurn, ofstream& outputFile);

int main( ) {
    ofstream outputFile;
    outputFile.open("gofish_results.txt");

    int numCards = 7;

    Player p1("Yale Patt");
    Player p2("Ramesh Yerraballi");

    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards, outputFile);
    dealHand(d, p2, numCards, outputFile);

    outputFile << p1.getName() << "'s hand: " << p1.showHand() << endl;
    outputFile << p2.getName() << "'s hand: " << p2.showHand() << endl;
    outputFile << "*********************" << endl;
    outputFile << p1.getName() <<" has books:\n" << p1.showBooks() << endl;
    outputFile << p2.getName() <<" has books:\n" << p2.showBooks() << endl;
    outputFile << "*********************\n" << endl;
    outputFile << "GAME BEGINS!\n" << endl;

    while(p1.getBookSize() < 14 && p2.getBookSize() < 14){
        playerTurnAction(p1, p2, d, outputFile);
        if(p1.getBookSize() < 14){
            playerTurnAction(p2, p1, d, outputFile);
        }
    }

    outputFile << p1.getName() << "'s hand: " << p1.showHand() << endl;
    outputFile << p2.getName() << "'s hand: " << p2.showHand() << endl;
    outputFile << "*********************" << endl;
    outputFile << p1.getName() <<" has books:\n" << p1.showBooks() << endl;
    outputFile << p2.getName() <<" has books:\n" << p2.showBooks() << endl;

    outputFile.close();

    return EXIT_SUCCESS;
}

// booking all possible pairs at once when it is a player's turn
void playerTurnAction(Player &pTurn, Player &pAsked, Deck &d, ofstream& outputFile){
    bool askAgain = true;

    while(askAgain){
        playerBookCards(pTurn, outputFile);

        if(pTurn.getHandSize() == 0){
            dealHand(d, pTurn, 1, outputFile);
        }
        //asks pAsked for a card
        Card ask = pTurn.chooseCardFromHand(); // get random card to ask from hand
        outputFile << pTurn.getName() << " asks - Do you have a " << ask.rankString(ask.getRank()) << "?" << endl;
        Card getCard;

        if(pAsked.rankInHand(ask)){ // if pAsked has the card with same rank in hand
            outputFile << pAsked.getName() << " says - Yes, I have a " << ask.rankString(ask.getRank()) << "." << endl;
            getCard = pAsked.removeCardFromHand(ask);
            pTurn.addCard(getCard);
            askAgain = true;
        }
        else{ // When the opponent does not have the requested card

            outputFile << pAsked.getName() << " says - Go Fish!" << endl;

            // grab a card from the deck and book any pairs before ending turn
            dealHand(d, pTurn, 1, outputFile);
            playerBookCards(pTurn, outputFile);

            outputFile << pTurn.showHand() << endl;
            outputFile << "\n";

            askAgain = false;
        }
    }

}

void playerBookCards(Player &pTurn, ofstream& outputFile){
    Card c1;
    Card c2;
    while(pTurn.checkHandForPair(c1, c2)){
        pTurn.bookCards(c1, c2);
        outputFile << pTurn.getName() << " books the " << c1.rankString(c1.getRank()) << endl;
        outputFile << "\n";
        pTurn.removeCardFromHand(c1);
        pTurn.removeCardFromHand(c2);
    }
}

void dealHand(Deck &d, Player &p, int numCards, ofstream& outputFile)
{
    Card c;
    for (int i=0; i < numCards; i++){
        c = d.dealCard();
        p.addCard(c);
    }
    outputFile << p.getName() << " draws " << c << endl;

}



