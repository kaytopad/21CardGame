#pragma once
#include "Config.h"
class CardManager
{
private:
	int cards[CARD_TOTAL];
	int cardCount;
public:
	//コンストラクタ
	CardManager();
	//カードを作成
	void CreateCards();
	//カードシャフル
	void ShuffleCards();
	//カードを1枚引く
	int DrawCard();
	//残りのカード枚数を取得
	int GetCardCount();
};

