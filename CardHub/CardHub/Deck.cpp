#include "Deck.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> SNames = { "S", "H", "C", "D" };

Deck::Deck() {
	for (int i = 1; i < 14; i++) {
		for (int j = 0; j < 4; j++) {
			Card NewCard = Card(SNames[j], i);
			Cards.push_back(NewCard);
		}
	}
	
};

void Deck::Shuffle() {
	random_device rd;
	mt19937 g(rd());

	shuffle(Cards.begin(), Cards.end(), g);
}

vector<Card> Deck::GetDeck() {
	return Cards;
}

Card Deck::GetCard(int index) {
	return Cards[index];
}

int Deck::deckSize() {
	return Cards.size();
}

void Deck::removeCard(int Current) {
	Cards.erase(Cards.begin() + Current);
}

void Deck::removeCard(Card inCard) {
	for (int i = 0; i < Cards.size(); i++) {
		Card nextCard = Cards.at(i);
		if (nextCard.getValue() == inCard.getValue() and nextCard.getSuit() == inCard.getSuit()) {

			Cards.erase(Cards.begin() + i); 
			//cout << "index: " << i << " my card be is the " << nextCard.getValue() << " of " << nextCard.getSuit() << " yeah man";
			break;

		}
	}
}