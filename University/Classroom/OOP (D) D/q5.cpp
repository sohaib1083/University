#include <iostream>
#include <vector>
using namespace std;

class card{
	int face, suit;
	// c
	static string array_face[100];
	static string array_suit[100];
	public:
	card(int f, int s)
	{
		face = f;
		suit = s;
	}
	// d
	card tostring ();
};

class DeckOfCards{
	vector <card> deck;
	int current_card;
	public:
	DeckOfCard()
	{
		
	}	
};


int main (void)
{
	return 0;
}
