//
// Created by Carlos Villapudua on 11/5/2018.
//

#include "player.h"

#include <cstdlib>
#include <iostream>
#include <string>

#include <time.h>

using namespace std;
	
	Player::Player(){
		myName = "";
		unsigned int currentTime = (unsigned) time(0);
        srand(currentTime);		
	}

	Player::addCard(Card c){
		myHand.push_back(c);
		unsigned int currentTime = (unsigned) time(0);
        srand(currentTime);		
	}

	Player::bookCards(Card c1, Card c2){
		myBook.push_back(c1);
		myBook.push_back(c2);
	}


	Card Player::chooseCardFromHand() const{
		int randCard = rand() % myHand.size();
		return myHand[randCard];
	}

	bool Player::cardInHand(Card c) const{
		vector<Card>::iterator iter;

		for(iter = myHand.begin() ; iter != myHand.end() ; iter++){        
			if(c.getRank() == (*iter).getRank()){
				return true;
			}  
		}

		return false;
	}
	//confused about why returning the same card removed
	Card Player::removeCardFromHand(Card c){
//int i = 0;
		Card retCard = c;
		vector<Card>::iterator iter;
		iter = myHand.begin();

		while((*iter).getRank() != c.getRank()){
			iter++;
//i++
		}

//myHand.erase(myhand.begin()+i);
		myHand.erase(iter);
		return retCard;
	}

	string showHand() const{
		vector<Card>::iterator iter;
		iter = myHand.begin();

		cout << "Cards in " << myName << "'s hand:" << endl;
		for(iter = myHand.begin() ; iter != myHand.end() ; iter++){
			cout << *iter << endl;
		}
	}

	string showBooks() const{
		vector<Card>::iterator iter;
		iter = myBook.begin();

		cout << "Books of :" << myName << endl;
		for(iter = myBook.begin() ; iter != myBook.end() ; iter = iter + 2){
			cout << *iter << " " << *(iter + 1) << endl;
		}
	}

	int getHandSize() const{

	}

	int getBookSize() const{

	}