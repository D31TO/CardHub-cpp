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
int Ppval1;
int Pdval1;
int Ppval2;
int Pdval2;
int PlayerTotal;

vector<string> SNames = { "S", "H", "C", "D" };

static string CardNames[] = {
	"A",
	"2",
	"3",
	"4",
	"5",
	"6",
	"7",
	"8",
	"9",
	"10",
	"J",
	"Q",
	"K",
};

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
		
		CardNames[PlayerVal1];
		cout << CardNames;

		//Game Output
		int PlayerTotal = PlayerVal1 + PlayerVal2;

		cout << "You have " << PlayerVal1 << " " << PlayerSuit1 << " and " << PlayerVal2 << " " << PlayerSuit2 << endl;
		cout << "Your total = " << PlayerTotal << endl;

	}
	else if (inp == 2) {
		cout << "Loading Solitaire" << endl;
	}



}


