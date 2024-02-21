#include <string>
#include <iostream>
#include <vector>
#include "Card.h"
#include <iterator>
#include <random>
#include <algorithm>
#include "Deck.h"
#include <cstdlib>
#include <ctime>

using namespace std;
//Declerations
int inp;
//vector<Card> Deck;
int picked;
int GetTotal(vector<Card> PlayerHand);
void DisplayCardsHelper(Card InCard);
void DisplayHand(vector<Card>, bool IsDealer);
void BJCheck(int PPTotal, int DDTotal);
int pdec;
int DealerTotal;
int PlayerTotal;
bool Stood;
void WinCheck(int PPTotal, int DDTotal);

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


		vector<Card> PlayerHand = { TheDeck.GetCard(0), TheDeck.GetCard(1) };
		vector<Card> DealerHand = { TheDeck.GetCard(5), TheDeck.GetCard(6) };

		int PlayerTotal = 0;
		int NumAces = 0;
		int DealerTotal = 0;

		//Acces and total for Player
		PlayerTotal = GetTotal(PlayerHand);

		NumAces = 0;
		//Aces and total for dealer
		DealerTotal = GetTotal(DealerHand);

		//Game Output
#

		//Player values
		DisplayHand(PlayerHand, false);


		cout << "Your total = " << PlayerTotal << endl;

		//Dealer values
		DisplayHand(DealerHand, true);

		cout << "The Dealer's total = " << DealerTotal << endl;

		//Blackjack Check

		BJCheck(PlayerTotal, DealerTotal);


		//Player Decision
		cout << "Would you like to 1) hit or 2) stand?" << endl;
		int pdec;
		cin >> pdec;


		//Hit 1
		if (pdec == 1) {
			cout << "You hit" << endl;
			vector<Card> PlayerHand = { TheDeck.GetCard(0), TheDeck.GetCard(1), TheDeck.GetCard(2) };
			PlayerTotal = GetTotal(PlayerHand);
			DisplayHand(PlayerHand, false);


			cout << "Your total = " << PlayerTotal << endl;

			BJCheck(PlayerTotal, DealerTotal);

			if (PlayerTotal < 21) {
				//Player Decision 2
				cout << "Would you like to 1) hit or 2) stand?" << endl;
				int pdec;
				cin >> pdec;
				if (pdec == 1) {
					cout << "You hit" << endl;
					vector<Card> PlayerHand = { TheDeck.GetCard(0), TheDeck.GetCard(1), TheDeck.GetCard(2), TheDeck.GetCard(3) };
					PlayerTotal = GetTotal(PlayerHand);
					DisplayHand(PlayerHand, false);


					cout << "Your total = " << PlayerTotal << endl;

					BJCheck(PlayerTotal, DealerTotal);

					if (PlayerTotal < 21) {
						//Player Decision 3
						cout << "Would you like to 1) hit or 2) stand?" << endl;
						int pdec;
						cin >> pdec;
						if (pdec == 1) {
							cout << "You hit" << endl;
							vector<Card> PlayerHand = { TheDeck.GetCard(0), TheDeck.GetCard(1), TheDeck.GetCard(2), TheDeck.GetCard(3), TheDeck.GetCard(4) };
							PlayerTotal = GetTotal(PlayerHand);
							DisplayHand(PlayerHand, false);


							cout << "Your total = " << PlayerTotal << endl;

							BJCheck(PlayerTotal, DealerTotal);


						}
						else {
							Stood = true;
						}
					}
					
					
				}
				else {
					Stood = true;
				}


			}

		}
		else {
			Stood = true;
		}


		if (Stood) {
			cout << "You stand" << endl;
			BJCheck(PlayerTotal, DealerTotal);
			while(DealerTotal < 17){
				if (DealerTotal < 17) {
					vector<Card> DealerHand = { TheDeck.GetCard(5), TheDeck.GetCard(6), TheDeck.GetCard(7) };
					DealerTotal = GetTotal(DealerHand);
					DisplayHand(DealerHand, true);


					cout << "The Dealer has = " << DealerTotal << endl;
					BJCheck(PlayerTotal, DealerTotal);
					WinCheck(PlayerTotal, DealerTotal);
				}
			}WinCheck(PlayerTotal, DealerTotal);


		}
	}


		else if (inp == 2) {
			cout << "Loading Solitaire" << endl;
		}

	

}

int GetTotal(vector<Card> PlayerHand){

	int NumAces = 0;
	int PPtotal = 0;

	for (Card NextCard : PlayerHand) {
			int Value = NextCard.getValue();

			if (Value == 1) {
				NumAces++;

			}
			else {

				if (Value > 10) {
					PPtotal += 10;

				}
				else {
					PPtotal += Value;

				}
			}
		}
		if (NumAces > 0) {
			for (int i = 0; i < NumAces; i++) {
				if (PPtotal > 21) {
					PPtotal += 1;
				}
				else {
					PPtotal += 11;
				}
			}
		}
		return PPtotal;
}

void DisplayCardsHelper(Card InCard){

	int CardVal = InCard.getValue();
	string CardSuit = InCard.getSuit();

	if (CardVal == 1) {
		cout << "A of ";
		cout << CardSuit << " ";
	}
	else if (CardVal == 11) {
		cout << "J of ";
		cout << CardSuit << " ";
	}
	else if (CardVal == 12) {
		cout << "Q of ";
		cout << CardSuit << " ";
	}
	else if (CardVal == 13) {
		cout << "K of ";
		cout << CardSuit << " ";
	}
	else {
		cout << CardVal << " of " << CardSuit;
	}


}

void DisplayHand(vector<Card> Hand, bool IsDealer) {
	if (IsDealer) {
		cout << "The Dealer has ";
	}
	else{
		cout << "You have ";
	}
	for (Card NextCard : Hand) {
		DisplayCardsHelper(NextCard);
		cout << " and ";
	}

}

void BJCheck(int PPTotal, int DDTotal) {
	if (PPTotal == 21 and DDTotal == 21) {
		cout << "You draw! Double BlackJack" << endl;
		exit(0);
	}

	else if (PPTotal == 21) {
		cout << "You have blackjack! You win! :)" << endl;
		exit(0);
	}

	else if (DDTotal == 21) {
		cout << "The Dealer has blackjack! You lose! :(" << endl;
		exit(0);
	}
}

void WinCheck(int PPTotal, int DDTotal) {

	if (DDTotal > 21) {
		cout << "You win!!!!!";
		exit(0);
	}


	else if (PPTotal == DDTotal) {
		cout << "You draw";
		exit(0);
	}

	else if (PPTotal > DDTotal) {
		cout << "You win!!!!!";
		exit(0);
	}
	else if(DDTotal > PPTotal) {
		cout << "You lose :(";
		exit(0);
	}
}