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