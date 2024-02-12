#include "Card.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Card::Card(string n_Suit, int n_cardValue) {
	Suit = n_Suit;
	cardValue = n_cardValue;

}
Card::Card() {
	Suit = "";
	cardValue = 0;

}
//Getters
int Card::getValue() {
	return cardValue; 
}
string Card::getSuit() {
	return Suit;
}

void Card::setValue(int Val) {
	cardValue = Val;
}

void Card::setSuit(string Sui) {
	Suit = Sui;
}