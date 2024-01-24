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
int PlayerVal1;
string PlayerSuit1;
int DealerVal1;
string DealerSuit1;
int PlayerVal2;
string PlayerSuit2;
int DealerVal2;
string DealerSuit2;

vector<string> SNames = { "S", "H", "C", "D" };


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


	if (inp != 1 && inp != 2) {
		cout << "You can't pick that, try again." << endl;
		exit(0);
	}
	else if (inp == 1) {

		cout << "Loading Blackjack" << endl;
		//Fetching cards
		PlayerVal1 = Deck[0].getValue();
		PlayerSuit1 = Deck[0].getSuit();
		DealerVal1 = Deck[0].getValue();
		DealerSuit1 = Deck[0].getSuit();
		PlayerVal2 = Deck[1].getValue();
		PlayerSuit2 = Deck[1].getSuit();
		DealerVal2 = Deck[1].getValue();
		DealerSuit2 = Deck[1].getSuit();

		//Picture Cards


		string tempVal1;
		string tempVal2;

		if (PlayerVal1 == 11) {
			tempVal1 = "J";
			tempVal1 = to_string(PlayerVal1);
		}
		else if (PlayerVal1 == 12) {
			tempVal1 = "Q";
			tempVal1 = to_string(PlayerVal1);
		}
		else if (PlayerVal1 == 13) {
			tempVal1 = "K";
			tempVal1 = to_string(PlayerVal1);
		}

		if (PlayerVal2 == 11) {
			tempVal2 = "J";
			tempVal2 = to_string(PlayerVal2);
		}
		else if (PlayerVal2 == 12) {
			tempVal2 = "Q";
			tempVal2 = to_string(PlayerVal2);
		}
		else if (PlayerVal2 == 13) {
			tempVal2 = "K";
			tempVal2 = to_string(PlayerVal2);
		}


		if (DealerVal1 == 11) {
			tempVal1 = "J";
			string DealerVal1 = tempVal1;
		}
		else if (DealerVal1 == 12) {
			tempVal1 = "Q";
			string DealerVal1 = tempVal1;
		}
		else if (DealerVal1 == 13) {
			tempVal1 = "K";
			string DealerVal1 = tempVal1;
		}

		if (DealerVal2 == 11) {
			tempVal2 = "J";
			string DealerVal2 = tempVal1;
		}
		else if (DealerVal2 == 12) {
			tempVal2 = "Q";
			string DealerVal2 = tempVal1;
		}
		else if (DealerVal2 == 13) {
			tempVal2 = "K";
			string DealerVal2 = tempVal1;
		}


		//Aces
		if (PlayerVal1 == 1) {
			if (PlayerVal1 + PlayerVal2 > 21) {
				PlayerVal1 = 11;
			}
		}
		if (PlayerVal2 == 1) {
			if (PlayerVal1 + PlayerVal2 > 21) {
				PlayerVal2 = 11;
			}
		}
		if (DealerVal2 == 1) {
			if (DealerVal1 + DealerVal2 > 21) {
				DealerVal1 = 11;
			}
		}
		if (DealerVal2 == 1) {
			if (DealerVal1 + DealerVal2 > 21) {
				DealerVal2 = 11;
			}
		}




		//Game Output
		int PlayerTotal = PlayerVal1 + PlayerVal2;

		cout << "You have " << PlayerVal1 << " " << PlayerSuit1 << " and " << PlayerVal2 << " " << PlayerSuit2 << endl;
		cout << "Your total = " << PlayerTotal << endl;

	}
	else if (inp == 2) {
		cout << "Loading Solitaire" << endl;
	}



}


