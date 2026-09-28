#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Game.h"
#include "Config.h"

using namespace std;


// ========================================
// コンストラクタ
// ========================================

Game::Game()
{
    // カードを作成
    cardManager.CreateCards();
}


// ========================================
// ゲーム開始
// ========================================

void Game::Start()
{
    // カードをシャッフル
    cardManager.ShuffleCards();


    // 初期カードを配る
    DealInitialCards();


    // Playerのターン
    bool playerTurnResult;

    playerTurnResult =
        turn.PlayPlayerTurn(
            &player,
            &cardManager
        );


    // CPUのターン
    if (playerTurnResult)
    {
        turn.PlayCpuTurn(
            &player,
            &cpu,
            &cardManager
        );
    }
    else
    {
        cout << "\nPlayerの負けです。\n";

        return;
    }


    // 勝敗判定
    ShowResult();
}


// ========================================
// 初期カードを配る
// ========================================

void Game::DealInitialCards()
{
    for (int i = 0;
        i < INITIAL_CARD_COUNT;
        i++)
    {
        // Playerにカードを配る
        int playerCard =
            cardManager.DrawCard();

        player.AddCard(playerCard);


        // CPUにカードを配る
        int cpuCard =
            cardManager.DrawCard();

        cpu.AddCard(cpuCard);
    }
}


// ========================================
// 勝敗判定
// ========================================

void Game::ShowResult()
{
    cout << "\n===========================\n";
    cout << "ゲーム結果\n";
    cout << "===========================\n";


    player.ShowStatus();
    cpu.ShowStatus();


    int playerTotal =
        player.GetTotal();

    int cpuTotal =
        cpu.GetTotal();


    // CPUがバースト
    if (cpuTotal >= BURST_SCORE)
    {
        cout << "\nPlayerの勝ちです。\n";
        return;
    }


    // 両方21
    if (playerTotal == TARGET_SCORE &&
        cpuTotal == TARGET_SCORE)
    {
        cout << "\n引き分けです。\n";
        return;
    }


    // Playerが21
    if (playerTotal == TARGET_SCORE)
    {
        cout << "\nPlayerの勝ちです。\n";
        return;
    }


    // CPUが21
    if (cpuTotal == TARGET_SCORE)
    {
        cout << "\nCPUの勝ちです。\n";
        return;
    }


    // 21との差
    int playerDistance =
        TARGET_SCORE - playerTotal;

    int cpuDistance =
        TARGET_SCORE - cpuTotal;


    if (playerDistance < cpuDistance)
    {
        cout << "\nPlayerの勝ちです。\n";
    }
    else if (playerDistance > cpuDistance)
    {
        cout << "\nCPUの勝ちです。\n";
    }
    else
    {
        cout << "\n引き分けです。\n";
    }
}