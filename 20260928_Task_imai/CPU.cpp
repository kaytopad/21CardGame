#include "CPU.h"
#include <iostream>
using namespace std;

CPU::CPU()
{
	total = 0;
}

void CPU::AddCard(int card)
{
	total += card;
}

int CPU::GetTotal()
{
	return total;
}

void CPU::ShowStatus()
{
	cout << "CPU‚Ì‡Œv:" << total << endl;

}