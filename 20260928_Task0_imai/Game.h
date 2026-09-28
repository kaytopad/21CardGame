#pragma once

#include "Player.h"
#include "CPU.h"
#include "CardManager.h"
#include "Turn.h"

class Game
{
private:

    // カード管理
    CardManager cardManager;

    // Player
    Player player;

    // CPU
    CPU cpu;

    // ターン管理
    Turn turn;


public:

    // コンストラクタ
    Game();

    // ゲーム開始
    void Start();


private:

    // 初期カードを配る
    void DealInitialCards();

    // 勝敗判定
    void ShowResult();
};