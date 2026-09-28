#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Game.h"
#include "Config.h"

using namespace std;

Game::Game()
{
	// カードを作成してシャッフル
	cardManager.CreateCards();
	cardManager.ShuffleCards();
}

void Game::Start()
{
	// 初期カードを配る
	DealInitialCards();
	// プレイヤーのターン
	bool playerTurnResult = turn.PlayPlayerTurn(&player, &cardManager);
	// CPUのターン
	if (playerTurnResult)
	{
		turn.PlayCpuTurn(&player, &cpu, &cardManager);
	}
	else
	{
		cout << "\nPlayerの負けです。\n" ;

		return;
	}
	// 勝敗判定
	ShowResult();
}

void Game::DealInitialCards()
{
	// プレイヤーとCPUに初期カードを配る
	for (int i = 0; i < INITIAL_CARD_COUNT; i++)
	{
		int playerCard = cardManager.DrawCard();
		player.AddCard(playerCard);
		int cpuCard = cardManager.DrawCard();
		cpu.AddCard(cpuCard);
	}
}

void Game::ShowResult()
{
	cout << "\n===========================\n";
	cout << "ゲーム結果\n";
	cout << "===========================\n";
	player.ShowStatus();
	cpu.ShowStatus();
	
	int playerTotal = player.GetTotal();
	int cpuTotal = cpu.GetTotal();

	if (cpuTotal >= BURST_SCORE || playerTotal == TARGET_SCORE)
	{
		cout << "\nPlayer'S Winner!!\n";
		return;
	}

	if (cpuTotal == TARGET_SCORE)
	{
		cout << "\nCPU'S Winner!!\n";
		return;

	}
	int playerDistance =TARGET_SCORE - playerTotal;

	int cpuDistance =TARGET_SCORE - cpuTotal;

	if (playerDistance > cpuDistance)
	{
		cout << "\nPlayerの勝ちです。\n";
	}
	else if (playerDistance < cpuDistance)
	{
		cout << "\nCPUの勝ちです。\n";
	}
	else
	{
		cout << "\n引き分けです。\n";
	}
}