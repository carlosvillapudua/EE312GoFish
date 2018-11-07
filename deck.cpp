//
// Created by Carlos Villapudua on 11/5/2018.
//

#include "deck.h"
#include "card.h"
#include "player.h"
#include <time.h>

    Deck::Deck(){
        myIndex = 0;                                                           //initialize index of where to deal cards from

        unsigned int currentTime = (unsigned) time(0);
        srand(currentTime);		                                               //seed rand function with time, which is different at ANY moment

        for (int i = 0; i < ((SIZE/4)); i++){                               //divide creation of deck of cards into four parts - by SUIT
            myCards[i] = Card(i+1, Card::spades);
        }
        for (int i = (SIZE/4); i < ((SIZE/2)); i++){
            myCards[i] = Card(i-(SIZE/4)+1, Card::hearts);
        }
        for (int i = (SIZE/2); i < ((3*SIZE/4)); i++){
            myCards[i] = Card(i-(SIZE/2)+1, Card::diamonds);
        }
        for (int i = (3*SIZE/4); i < (SIZE); i++){
            myCards[i] = Card(i-(3*SIZE/4)+1, Card::clubs);
        }

for (int i = 0; i < SIZE; i++){                                    //print out results to console to confirm deck is made correctly
cout << myCards[i].toString() << endl;
}
cout<< "hello hello hello" << endl;

    }

    void Deck::shuffle() {
        int randNum1;
        int randNum2;

        int cardsLeft = SIZE - myIndex;        
        Card temp;

        if(myIndex < SIZE){  //shuffle only if deck has cards left
            for (int j = 0; j < 4*cardsLeft; j++){
                randNum1 = (rand() % cardsLeft) + myIndex;                   //random numbers used to determine which indices to swap
                randNum2 = (rand() % cardsLeft) + myIndex;

                temp = myCards[randNum1];                   //save previous value of content @ index of randNum1
                myCards[randNum1] = myCards[randNum2];      //swap contents of randNum2 into element space determined by randNum1
                myCards[randNum2] = temp;                   //place contents of previous randNum1 into randNum2 space
            }
        }

for (int i = 0; i < SIZE; i++){                                    //print out results to console to confirm deck is shuffled correctly
cout << myCards[i].toString() << endl;
}
//test

    }

    Card Deck::dealCard() {               
        if (myIndex < SIZE){                          //make upper bound size, because we only want to deal 52 cards (0-51)
            Card retCard = myCards[myIndex];
            myIndex++;
            return retCard;
        }

        // not sure what to do when all cards are dealt
        Card c;
        return c;
    }

    int Deck::size() const {
        return (SIZE - myIndex);                    //myIndex tells us how many cards we have dealt -- (Cards Dealt) + (Cards Left to Deal) = (Total Cards)
    }




