#include "CardUser.h"
#include <iostream>

using namespace std;

CardUser::CardUser()
{
	total = 0;
}

void CardUser::AddCard(int card)
{
	total += card;

}

int CardUser::GetTotal()
{
	return total;
}

void CardUser::ShowStatus()
{
	cout << "‡Œv:" << total << endl;

}