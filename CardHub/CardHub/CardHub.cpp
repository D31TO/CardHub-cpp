#include <string>
#include <iostream>
#include <vector>
#include "Card.h"
#include <iterator>
#include <random>
#include <algorithm>
using namespace std;
//Declerations
int inp;
vector<Card> Deck;
int picked;
int PlayerVal;
string PlayerSuit;
int DealerVal;
string DealerSuit;

vector<string> SNames = { "s", "h", "c", "d" };


int main()
{

	for (int i = 1; i < 14; i++) {
		for (int j = 0; j < 4; j++) {
			Card NewCard = Card(SNames[j], i);
			Deck.push_back(NewCard);
		}
	}

	random_device rd;
	mt19937 g(rd());

	shuffle(Deck.begin(), Deck.end(), g);


	cout << "Welcome to the card hub!" << endl;
	cout << "Would you like to play Blackjack (1) or Solitaire? (2)" << endl;
	cin >> inp;

	//Blackjack
	if (inp == 1) {
		cout << "Loading Blackjack" << endl;
		PlayerVal = Deck[0].getValue();
		PlayerSuit = Deck[0].getSuit();
	}
	







	//Solitaire
	if (inp == 2) {
		cout << "Loading Solitaire" << endl;
	}

	//Quitcheck
	if(inp != 1) {
		cout << "You can't pick that try again." << endl;
		exit(0);
	}
	if (inp != 2) {
		cout << "You can't pick that try again." << endl;
		exit(0);
	}



}


