#pragma once
class CPU
{
private:
	int total;
public:
	//コンストラクタ
	CPU();
	//カードを追加
	void AddCard(int card);
	//合計点を取得する
	int GetTotal();
	//現在の状態を表示
	void ShowStatus();

};

