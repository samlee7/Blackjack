#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <ctime>
#include <windows.h>

using namespace std;

enum Suits{Hearts, Clubs, Spades, Diamonds};
int numval = 13;

int myrandom(int i) { return rand() % i; }

struct card{
	string suit;
	int val;

	card(string suit, int val) : suit(suit), val(val) {}
};

/* creates a deck of size 52 */
void create_deck(vector<card> &deck)
{
	for (int i = 1; i <= numval; i++)
	{
		deck.push_back(card("Hearts", i));
	}
	for (int i = 1; i <= numval; i++)
	{
		deck.push_back(card("Clubs", i));
	}
	for (int i = 1; i <= numval; i++)
	{
		deck.push_back(card("Spades", i));
	}
	for (int i = 1; i <= numval; i++)
	{
		deck.push_back(card("Diamonds", i));
	}
}

int main()
{
	cout << "Welcome to Sam's Blackjack v1" << endl << endl;

	int cash = 1000;

	srand(unsigned(time(0)));
	vector<card> deck;
	create_deck(deck);

	/* shuffles the deck */
	random_shuffle(deck.begin(), deck.end(), myrandom);

	int cardamount = 0;
	int dealeramount = 0;
	int yourValue = 0;
	int dealerValue = 0;
	string input;

	/* while loop that powers the game */
	while (1)
	{
		cout << "You have " << cash << " dollars" << endl;
		while (cardamount < 2)
		{
			card top = deck.back();
			deck.pop_back();

			/* If the card value is > 10, it is set to 10 */
			/* Jack, Queen, King has value of 10 */
			if (top.val == 11 || top.val == 12 || top.val == 13) yourValue = yourValue + 10;
			else yourValue = yourValue + top.val;

			Sleep(2000);
			cout << "Your Card Showing: " << top.suit << " " << top.val << endl;
			cardamount++;
		}
		while (dealeramount < 2)
		{
			card top = deck.back();
			deck.pop_back();

			/* If the card value is > 10, it is set to 10 */
			/* Jack, Queen, King has value of 10 */
			if (top.val == 11 || top.val == 12 || top.val == 13) dealerValue = dealerValue + 10;
			else dealerValue = dealerValue + top.val;

			Sleep(2000);
			dealeramount++;
			cout << "Dealer Card Showing: " << top.suit << " " << top.val << endl;
		}
		cout << "Your Current Value: " << yourValue << endl;
		cout << "Dealer Current Value: " << dealerValue << endl;

		if (deck.size() == 0) break;

		cout << "Do you want an another hand? (yes/no)" << endl;
		cin >> input;

		if (input == "no") break;
		/* if input is yes, do nothing */
		else if (input == "yes") ;

		/* reset card value and total value */
		cardamount = 0;
		dealeramount = 0;
		yourValue = 0;
		dealerValue = 0;

		cout << endl;
	}
}