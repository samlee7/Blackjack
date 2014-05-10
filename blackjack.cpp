#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

enum Suits{Hearts, Clubs, Spades, Diamonds};
int numval = 13;

int myrandom(int i) { return rand() % i; }

struct card{
	string suit;
	int val;

	card(string suit, int val) : suit(suit), val(val) {}
};

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
	srand(unsigned(time(0)));
	vector<card> deck;
	create_deck(deck);
	cout << deck.size() << endl;

	random_shuffle(deck.begin(), deck.end(), myrandom);

	int cardamount = 0;
	int totalValue = 0;
	string input;

	while (1)
	{
		while (cardamount < 2)
		{
			card top = deck.back();
			deck.pop_back();

			if (top.val == 11 || top.val == 12 || top.val == 12) totalValue = totalValue + 10;
			else totalValue = totalValue + top.val;

			cout << "Card showing: " << top.suit << " " << top.val << endl;
			cardamount++;
		}
		cout << "Current Value: " << totalValue << endl;
		if (totalValue == 21) cout << "You got a Blackjack!" << endl;
		else cout << "You did not get a Blackjack" << endl;

		if (deck.size() == 0) break;

		cout << "Do you want an another hand? (yes/no)" << endl;
		cin >> input;

		if (input == "no") break;
		else if (input == "yes") ;

		cardamount = 0;
		totalValue = 0;
	}
}