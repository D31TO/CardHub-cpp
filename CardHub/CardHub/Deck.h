#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Card.h"
#include <iterator>
#include <random>
#include <algorithm>

using namespace std;

class Deck
{
private:

	vector<Card> Cards;

public:

	void Shuffle();

	Deck();

	vector<Card> GetDeck();
	Card GetCard(int index);
	int deckSize();
	void removeCard(int Current);


};

