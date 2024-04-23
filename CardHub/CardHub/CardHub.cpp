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
int Counter = 0;
int Counting = 1;

//All the card types/name
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
	//Shuffles the Deck/Makes Deck
	Deck TheDeck = Deck();
	TheDeck.Shuffle();

	cout << "Welcome to the card hub!" << endl;
	cout << "Would you like to play Blackjack (1) or Solitaire (Hit Or Miss)? (2)" << endl;
	cin >> inp;


	if (inp != 1 && inp != 2) {
		cout << "You can't pick that, try again." << endl;
		exit(0);
	}
	else if (inp == 1) {

		cout << "Loading Blackjack" << endl;

		//Fetching cards

		//Makes the first hands of the player and the dealer
		vector<Card> PlayerHand = { TheDeck.GetCard(0), TheDeck.GetCard(1) };
		vector<Card> DealerHand = { TheDeck.GetCard(5), TheDeck.GetCard(6) };

		int PlayerTotal = 0;
		int NumAces = 0;
		int DealerTotal = 0;

		//Aces and total for Player
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


		//Player Decision 1
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

							if (PlayerTotal < 21) {
								//Player Decision 4
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
							else {
								Stood = true;
							}
						}
						else {
							Stood = true;
						}
					}
					else {
						Stood = true;
					}
					
				}
				else {
					Stood = true;
				}


			}
			else {
				Stood = true;
			}
		}
		else {
			Stood = true;
		}

		//Standing
		if (Stood) {
			cout << "You stand" << endl;
			BJCheck(PlayerTotal, DealerTotal);
			int dealerCardIndex = 7;
			while(DealerTotal < 17){
				if (DealerTotal < 17) {
					//vector<Card> DealerHand = { TheDeck.GetCard(5), TheDeck.GetCard(6), TheDeck.GetCard(7) };
					DealerHand.push_back(TheDeck.GetCard(dealerCardIndex));
					dealerCardIndex++;
					DealerTotal = GetTotal(DealerHand);
					DisplayHand(DealerHand, true);


					cout << "The Dealer has = " << DealerTotal << endl;

					BJCheck(PlayerTotal, DealerTotal);
					
					
				}
				
			}
			WinCheck(PlayerTotal, DealerTotal);


		}
	}
	//Solitaire (Hit or Miss) a simple solitaire game that can be played with a single deck of cards.
		else if (inp == 2) {
			cout << "Loading Solitaire (Hit Or Miss)" << endl;
			cout << "How to play Hit Or Miss: " << endl;
			cout << "You will draw through a deck of shuffled cards." << endl;
			cout << "While drawing cards you will count in your head, from ace to king. A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K." << endl;
			cout << "If the card you have counted in your head gets drawn, it is a hit and is added to the hit pile." << endl;
			
			vector<Card> Hits;

			int Lives = 3;
			cout << "Press type n for next card, h for hit, and e to exit." << endl;
			//cout << "Your first card is: ";
			//DisplayCardsHelper(Current);
			//cout << endl;
			int timesHitted = 0;
			int round = 0;
			while (TheDeck.deckSize() > 0) {
				Counter = 0;
				Counting = 1;
				Card Current = TheDeck.GetCard(Counter);
				int Val = Current.getValue();
				string Suit = Current.getSuit();
				cout << "Deck Flickthrough (The Counter has been reset). You have ";
				cout << TheDeck.deckSize() <<" Cards left in the deck" << endl;
				if (round > 0) {
					if (timesHitted <= 0) {
						Lives--;
						TheDeck.Shuffle();
						cout << "You didn't hit all round, you have lost 1 life. You have " << Lives << " lives remaining." << endl;
						if (Lives == 0) {
							cout << "You have no more lives. You have lost :(" << endl;
							exit(0);
						}
					}
				}
				round++;
				timesHitted = 0;
				cout << "Your first card is: ";
				DisplayCardsHelper(Current);
				Counter++;
				cout << endl;

				for (int i = 0; i < TheDeck.deckSize(); i++) {

					if (Counter >= TheDeck.deckSize()) {
						break;
					}

					string pin;
					cin >> pin;


					if (pin == "e") {
						exit(0);
					}
					else if (pin == "n") {
						Counting++;
						if (Counting >= 14) {

							Counting = 1;
						}

						//cout << "index: " << i << ", counter: " << Counter << ", deck size: " << TheDeck.deckSize() << "\n";

						Current = TheDeck.GetCard(Counter);
						Val = Current.getValue();
						DisplayCardsHelper(Current);

						//Debug
						//cout << Val << endl;
						//cout << endl;
						//cout << Counting << endl;


						cout << endl;
						Counter++;

						//cout << Current.getValue();
						//cout << Current.getSuit();

					}
					else if (pin == "h") {
						if (Val == Counting) {
							cout << "You have hit successfully!" << endl;
							timesHitted++;
							//cout << Current.getValue();
							//cout << Current.getSuit();
							Hits.push_back(Current);
							TheDeck.removeCard(Current);
						}
						else {
							Lives--;
							cout << "Not hit here!  -1 life. You have " << Lives << " lives remaining." << endl;
							if (Lives == 0) {
								cout << "You hit wrong too many times. You have lost :(";
								exit(0);

							}
						}
					}
				}
			}cout << "You win! There are no more cards avaliable to hit" << endl;
			exit(0);
		}//cout << "You win! There are no more cards avaliable to hit" << endl;
		//exit(0);
		



}

//Function to get the total while knowing if there are aces
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
				if (PPtotal + 11 > 21) {
					PPtotal += 1;
				}
				else {
					PPtotal += 11;
				}
			}
		}
		return PPtotal;
}
//This is the main script used to display the right cards
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
//This actually displays the hand but can tell the difference between dealer and player
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

//Funny name.... oh and it checks if there is BLACKJACK
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

//Checks for a win if there isnt blackjack
void WinCheck(int PPTotal, int DDTotal) {

	if (PPTotal > 21) {
		cout << "You lose, you went bust first.";
		exit(0);
	}

	if (DDTotal > 21) {
		cout << "You win! Dealer went bust.";
		exit(0);
	}

	else if (PPTotal == DDTotal) {
		cout << "You draw.";
		exit(0);
	}

	else if (PPTotal > DDTotal) {
		cout << "You win!!!!!";
		exit(0);
	}
	else if(DDTotal > PPTotal) {
		cout << "You lose :( Dealer closer to 21.";
		exit(0);
	}
}