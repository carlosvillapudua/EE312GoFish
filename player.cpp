//
// Created by Carlos Villapudua on 11/5/2018.
//

#include "player.h"
#include "card.h"
//test
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

	void Player::addCard(Card c){
		myHand.push_back(c);
		unsigned int currentTime = (unsigned) time(0);
        srand(currentTime);		
	}

	void Player::bookCards(Card c1, Card c2){
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

	string Player::showHand() const{
		vector<Card>::iterator iter;
		iter = myHand.begin();

		cout << "Cards in " << myName << "'s hand:" << endl;
		for(iter = myHand.begin() ; iter != myHand.end() ; iter++){
			cout << *iter << endl;
		}
	}

	string Player::showBooks() const{
		vector<Card>::iterator iter;
		iter = myBook.begin();

		cout << "Books of :" << myName << endl;
		for(iter = myBook.begin() ; iter != myBook.end() ; iter = iter + 2){
			cout << *iter << " " << *(iter + 1) << endl;
		}
	}

	int Player::getHandSize() const{
		return myHand.size();
	}

	int Player::getBookSize() const{
		return  myBook.size();
	}

	bool Player::checkHandForPair(Card &c1, Card &c2){
		vector<Card>::iterator iter;
		iter = myHand.begin();

		vector<Card>::iterator iterInner;
		iterInner = myHand.begin();

		for(iter = myHand.begin() ; iter != myHand.end() ; iter++){		
			for(iterInner = myHand.begin() ; iterInner != myHand.end() ; iter++){
				if(*iter == *iterInner){
					c1 = *iter;
					c2 = *iterInner;
					return true;
				}
			}
		}
		return false;
	}













