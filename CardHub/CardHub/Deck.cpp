#include "Deck.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> SNames = { "S", "H", "C", "D" };

//Create the deck properly
Deck::Deck() {
	for (int i = 1; i < 14; i++) {
		for (int j = 0; j < 4; j++) {
			Card NewCard = Card(SNames[j], i);
			Cards.push_back(NewCard);
		}
	}
	
};


//Shuffle the deck with a random seed
void Deck::Shuffle() {
	random_device rd;
	mt19937 g(rd());

	shuffle(Cards.begin(), Cards.end(), g);
}

vector<Card> Deck::GetDeck() {
	return Cards;
}

//Pick specific card to get details
Card Deck::GetCard(int index) {
	return Cards[index];
}

//Used for determining deck size
int Deck::deckSize() {
	return Cards.size();
}

//Old remove card function
void Deck::removeCard(int Current) {
	Cards.erase(Cards.begin() + Current);
}


//New better remove card function. Goes through every card until its matching with the card it wants. Then removes it.
void Deck::removeCard(Card inCard) {
	for (int i = 0; i < Cards.size(); i++) {
		Card nextCard = Cards.at(i);
		if (nextCard.getValue() == inCard.getValue() and nextCard.getSuit() == inCard.getSuit()) {

			Cards.erase(Cards.begin() + i); 
			break;

		}
	}
}