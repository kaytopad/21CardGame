#pragma once
class Player
{
private:
	int total;
public:
	//コンストラクタ
	Player();
	//カードを追加
	void AddCard(int card);
	//合計点を取得する
	int GetTotal();
	//現在の状態を表示
	void ShowStatus();

};

