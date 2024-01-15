#include "Card.h"
#include <iostream>
#include <string>
using namespace std;

Card::Card(string n_Suit, int n_cardValue) {
	Suit = n_Suit;
	cardValue = n_cardValue;


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