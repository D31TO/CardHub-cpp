#include <string>
#include <iostream>
#include <vector>
#include "Card.h"
#include <iterator>
#include <random>
#include <algorithm>
#include "Deck.h"

using namespace std;
//Declerations
int inp;
//vector<Card> Deck;
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
int PlayerVal3;
string PlayerSuit3;
int PlayerVal4;
string PlayerSuit4;
int PlayerVal5;
string PlayerSuit5;

//vector<string> SNames = { "S", "H", "C", "D" };

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

	//for (int i = 1; i < 14; i++) {
	//	for (int j = 0; j < 4; j++) {
	//		Card NewCard = Card(SNames[j], i);
	//		Deck.push_back(NewCard);
	//	}
	//}

	//random_device rd;
	//mt19937 g(rd());

	//shuffle(Deck.begin(), Deck.end(), g);


	Deck TheDeck = Deck();
	TheDeck.Shuffle();

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
		PlayerVal1 = TheDeck.GetCard(0).getValue();
		PlayerSuit1 = TheDeck.GetCard(0).getSuit();
		DealerVal1 = TheDeck.GetCard(1).getValue();
		DealerSuit1 = TheDeck.GetCard(1).getSuit();
		PlayerVal2 = TheDeck.GetCard(2).getValue();
		PlayerSuit2 = TheDeck.GetCard(2).getSuit();
		DealerVal2 = TheDeck.GetCard(3).getValue();
		DealerSuit2 = TheDeck.GetCard(3).getSuit();

		vector<Card> PlayerHand = { TheDeck.GetCard(0), TheDeck.GetCard(2)};
		vector<Card> DealerHand = { TheDeck.GetCard(1), TheDeck.GetCard(3) };

		int PlayerTotal = 0;
		int NumAces = 0;
		int DealerTotal = 0;

		//Acces and total for Player
		for (Card NextCard : PlayerHand) {
			int Value = NextCard.getValue();
		
			if (Value == 1) {
				NumAces++;
				
			}
			else {
				
				if (Value > 10) {
					PlayerTotal += 10;
					
				}
				else {
					PlayerTotal += Value;
					
				}
			}
		}
		if (NumAces > 0) {
			for (int i = 0; i < NumAces; i++) {
				if (PlayerTotal > 21) {
					PlayerTotal += 1;
				}
				else {
					PlayerTotal += 11;
				}
			}
		}
		NumAces = 0;
		//Aces and total for dealer
		for (Card NextCard : DealerHand) {
			int Value = NextCard.getValue();

			if (Value == 1) {
				NumAces++;

			}
			else {

				if (Value > 10) {
					DealerTotal += 10;

				}
				else {
					DealerTotal += Value;

				}
			}
		}
		if (NumAces > 0) {
			for (int i = 0; i < NumAces; i++) {
				if (DealerTotal > 21) {
					DealerTotal += 1;
				}
				else {
					DealerTotal += 11;
				}
			}
		}

		//Game Output
#

		//Player first values
		cout << "You have ";
		if (PlayerVal1 == 1){
			cout << "A of ";
			cout << PlayerSuit1 << " ";
		}
		else if (PlayerVal1 == 11) {
			cout << "J of ";
			cout << PlayerSuit1 << " ";
		}
		else if (PlayerVal1 == 12) {
			cout << "Q of ";
			cout << PlayerSuit1 << " ";
		}
		else if (PlayerVal1 == 13) {
			cout << "K of ";
			cout << PlayerSuit1 << " ";
		}
		else {
			cout << PlayerVal1 << " of " << PlayerSuit1;
		}

		cout << " and a ";

		//Player second values
		if (PlayerVal2 == 1) {
			cout << "A of ";
			cout << PlayerSuit2;
		}
		else if (PlayerVal2 == 11) {
			cout << "J of ";
			cout << PlayerSuit2;
		}
		else if (PlayerVal2 == 12) {
			cout << "Q of ";
			cout << PlayerSuit2;
		}
		else if (PlayerVal2 == 13) {
			cout << "K of ";
			cout << PlayerSuit2;
		}
		else {
			cout << PlayerVal2 << " of " << PlayerSuit2;
		}
		cout << endl;

		cout << "Your total = " << PlayerTotal << endl;

		//Dealer first values
		cout << "The Dealer has ";
		if (DealerVal1 == 1) {
			cout << "A of ";
			cout << DealerSuit1 << " ";
		}
		else if (DealerVal1 == 11) {
			cout << "J of ";
			cout << DealerSuit1 << " ";
		}
		else if (DealerVal1 == 12) {
			cout << "Q of ";
			cout << DealerSuit1 << " ";
		}
		else if (DealerVal1 == 13) {
			cout << "K of ";
			cout << DealerSuit1 << " ";
		}
		else {
			cout << DealerVal1 << " of " << DealerSuit1;
		}

		cout << " and a ";

		//Dealer second values
		if (DealerVal2 == 1) {
			cout << "A of ";
			cout << DealerSuit2;
		}
		else if (DealerVal2 == 11) {
			cout << "J of ";
			cout << DealerSuit2;
		}
		else if (DealerVal2 == 12) {
			cout << "Q of ";
			cout << DealerSuit2;
		}
		else if (DealerVal2 == 13) {
			cout << "K of ";
			cout << DealerSuit2;
		}
		else {
			cout << DealerVal2 << " of " << DealerSuit2;
		}
		cout << endl;

		cout << "The Dealer has = " << DealerTotal << endl;

		//Blackjack Check

		if (PlayerTotal == 21 and DealerTotal == 21) {
			cout << "You draw! Double BlackJack" << endl;
			exit(0);
		}

		else if (PlayerTotal == 21) {
			cout << "You have blackjack! You win! :)" << endl;
			exit(0);
		}

		else if (DealerTotal == 21) {
			cout << "The Dealer has blackjack! You lose! :(" << endl;
			exit(0);
		}


		//Player Decision
		cout << "Would you like to 1) hit or 2) stand?" << endl;
		int pdec;
		cin >> pdec;

		if (pdec == 1) {
			cout << "You hit" << endl;

		}


		if (pdec == 2) {
			cout << "You stand" << endl;
		}


	}
	else if (inp == 2) {
		cout << "Loading Solitaire" << endl;
	}



}


