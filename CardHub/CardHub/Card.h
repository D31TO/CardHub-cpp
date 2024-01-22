#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//Setting up the class
class Card{
private:
	string Suit;
	int cardValue;
//Setting up the constructor
public:
	Card(string n_Suit, int n_cardValue);

	int getValue();
	string getSuit();
	void setValue(int Val);
	void setSuit(string Sui);

	Card();

};

