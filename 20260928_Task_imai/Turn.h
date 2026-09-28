#pragma once
#include "Player.h"
#include "CPU.h"
#include "CardManager.h"

class Turn
{
public:
	//Player'sTurn
	bool PlayPlayerTurn(Player*player,CardManager*cardManager);
	//Cpu'sTurn
	void PlayCpuTurn(Player*player,CPU*cpu,CardManager*cardManager);
};

