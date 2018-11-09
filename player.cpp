/*

Code By: Rithvik Baddam (rrb2442) and Carlos Villapudua (civ298)
Date:	11/05/18

This is a driver file for player.h

*/

#include "player.h"
#include "card.h"
#include <cstdlib>
#include <iostream>
#include <string>

#include <time.h>

#define FIVEBOOKS 10
#define EVERYBOOK 2

using namespace std;


Player::Player(){
    // initialize player and seed time
    myName = "";
    unsigned int currentTime = (unsigned) time(0);
    srand(currentTime);
}


void Player::addCard(Card c){
    myHand.push_back(c);
}


void Player::bookCards(Card c1, Card c2){ // add both cards to book
    myBook.push_back(c1);
    myBook.push_back(c2);
}

bool Player::rankInHand(Card c) const{
    vector<Card>::const_iterator iter;

    if(myHand.size() > 0){ // only check if player has cards in hand
        for(iter = myHand.begin() ; iter != myHand.end() ; iter++){
            if(c.getRank() == (*iter).getRank()){
                return true;
            }
        }
    }

    return false;
}

Card Player::chooseCardFromHand() const{
    int randCard = rand() % myHand.size();  // get a random number

    return myHand[randCard]; // return a random card from hand
}

bool Player::cardInHand(Card c) const{
    vector<Card>::const_iterator iter;

    for(iter = myHand.begin() ; iter != myHand.end() ; iter++){
        if(c == *iter){ // check if card is equal to the one in hand
            return true;
        }
    }

    return false;
}

Card Player::removeCardFromHand(Card c){
    vector<Card>::iterator iter;
    iter = myHand.begin();

    // loop until rank is found or if end it reached
    while((*iter).getRank() != c.getRank() && iter != myHand.end()){
        iter++;
    }

    // return card and erase it
    Card retcard = *iter;
    myHand.erase(iter);
    return retcard;
}

string Player::showHand() const{
    vector<Card>::const_iterator iter;
    string s;

    if(getHandSize() > 0){
        // priming the string
        iter = myHand.begin();
        s += (*iter).toString();
        iter++;

        // adding rest of the cards in with a comma in front
        while(iter != myHand.end()){
            s += ", ";
            s += (*iter).toString();
            iter++;
        }
    }
    else{
        // message if there's no cards
        s = "None";
    }

    return s;
}


string Player::showBooks() const{
    vector<Card>::const_iterator iter;
    string s;
    int bookCounter = 0;

    if(getBookSize() > 0){
        iter = myBook.begin();

        // adding rest of the cards in with a comma in front
        while(iter != myBook.end()){
            bookCounter++;
            s += (*iter).toString();

            // new line every 5 books
            if(bookCounter % FIVEBOOKS == 0){
                s += "\n";
            }

            // space after printing every book
            if(bookCounter % EVERYBOOK == 0){
                if(bookCounter % FIVEBOOKS != 0){
                    s += "  ";
                }

            }
            else{
                // comma between the cards in the book
                s += "|";
            }
            iter++;
        }
    }

        // error message if no books in player
    else{
        s = "None";
    }

    return s;
}

int Player::getHandSize() const{ // return the number of cards in myHand
    return myHand.size();
}

int Player::getBookSize() const{ // return the number of books in myBooks
    return  (myBook.size())/2;
}


bool Player::checkHandForPair(Card &c1, Card &c2){
    vector<Card>::const_iterator iter;
    vector<Card>::const_iterator iterInner;

    if(getHandSize() > 1) {
        for(iter = myHand.begin() ; iter != myHand.end() - 1 ; iter++){ // loop through first to second to last card
            for(iterInner = iter + 1 ; iterInner != myHand.end() ; iterInner++){ // loop through second to last card

                // if the ranks are equal in the hand, save those cards to the input paramets and return true
                if((*iter).getRank() == (*iterInner).getRank()){
                    c1 = *iter;
                    c2 = *iterInner;
                    return true;
                }
            }
        }
    }

    // if no pair found, return false
    return false;
}
