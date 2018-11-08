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
		vector<Card>::const_iterator iter;

		for(iter = myHand.begin() ; iter != myHand.end() ; iter++){        
			if(c.getRank() == (*iter).getRank()){
				return true;
			}  
		}

		return false;
	}
	//confused about why returning the same card removed
	Card Player::removeCardFromHand(Card c){
		Card retCard = c;
		vector<Card>::iterator iter;
		iter = myHand.begin();

		// loop until rank is found or if end it reached
		while((*iter).getRank() != c.getRank() && iter != myHand.end()){
			iter++;
		}

//myHand.erase(myhand.begin()+i);
		myHand.erase(iter);
		return retCard;
	}

// this this function supposed to return the concacted version of all the cards in the hand?
	string Player::showHand() const{
		vector<Card>::const_iterator iter;
		string s;
		//cout << "Cards in " << myName << "'s hand:" << endl;
		if(getHandSize() > 0){
			for(iter = myHand.begin() ; iter != myHand.end() ; iter++){
				//cout << *iter << endl;
				s += (*iter).toString();
			}
		}
		else{
			s = "None";
		}

		return s;
	}

// this this function supposed to return the concacted version of all the cards in the book?
	string Player::showBooks() const{
		vector<Card>::const_iterator iter;
		string s;
		//cout << "Books of :" << myName << endl;
		if(getBookSize() > 0){
			for(iter = myBook.begin() ; iter != myBook.end() ; iter = iter + 2){
				//cout << *iter << " " << *(iter + 1) << endl;
				s += (*iter).toString();
			}
		}
		else{
			s = "None";
		}

		return s;
	}

	int Player::getHandSize() const{
		return myHand.size();
	}

	int Player::getBookSize() const{
		return  myBook.size();
	}

	bool Player::checkHandForPair(Card &c1, Card &c2){
		vector<Card>::const_iterator iter;
		vector<Card>::const_iterator iterInner;

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













