/*

Code By: Rithvik Baddam (rrb2442) and Carlos Villapudua (civ298)
Date:	11/05/18

card.cpp has functions to

*/
#include <stdlib.h>
#include <iostream>
#include <string.h>

#include "card.h"

using namespace std;



    Card::Card(){
        myRank = 1;
        mySuit = spades;                //set default card to ace of spades
    }

    Card::Card(int rank, Suit s){
        myRank = rank;
        mySuit = s;                     //set newly created card to user input for suit and rank
    }

    string Card::toString() const {
        string appendVal =  rankString(myRank) + suitString(mySuit);
        return appendVal;
    }

    bool Card::sameSuitAs(const Card &c) const {
        if (mySuit == c.mySuit){
            return true;
        }
        else
            return false;
    }

    int Card::getRank() const {
        return myRank;
    }

    string Card::suitString(Suit s) const {

        switch (s){
            case spades:    return "s";             //return first letter of Suit to notify what suit a card is
            break;
            case hearts:    return "h";
            break;
            case clubs:     return "c";
            break;
            case diamonds:  return "d";
        }
    }

    string Card::rankString(int r) const {
        if (r >= 2 && r <= 10){
            string rankStr = to_string(r);
           return rankStr;
        }
        else{
            switch (r){                     //assuming that ace is rank of 1 and king is rank of 13
                case 1:     return "A";
                break;
                case 11:    return "J";
                break;
                case 12:    return  "Q";
                break;
                case 13:    return "K";
                break;
            }
        }
        return "ERROR";
    }
    //test

    bool Card::operator == (const Card& rhs) const{
        if (mySuit == rhs.mySuit && myRank == rhs.myRank){
            return true;
        }
        else
            return false;
    }

    bool Card::operator != (const Card& rhs) const{
        if (mySuit == rhs.mySuit && myRank == rhs.myRank){
            return false;
        }
        else
            return true;
    }

    ostream& operator << (ostream& out, const Card& c){
        out << c.toString();
        return out;
    }

