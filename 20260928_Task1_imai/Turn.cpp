#include "Turn.h"
#include <iostream>
#include"Config.h"

using namespace std;

bool Turn::PlayPlayerTurn(Player* player, CardManager* cardManager)
{
	while (true)
	{
		cout << "\n===========================\n";
		cout << "PLAYER Turn\n";
		cout << "===========================\n";

		player->ShowStatus();
		if (player->GetTotal() == TARGET_SCORE)
		{
			cout << "\nPlayer's Total : 21\n";

			return true;
		}

		cout << "\nカードを引きますか？？\n";
		cout << INPUT_YES << ":Yes\n";
		cout << INPUT_NO << ":No\n";

		int input;

		cin >> input;

		//カード引かない
		if (input == INPUT_NO)
		{
			cout << "\nカードを引きません\n";
			return true;
		}

		if (input == INPUT_YES)
		{
			//カードを取得
			int card = cardManager->DrawCard();

			cout << "\nPlayerがカードを引きました\n";
			cout << "引いたカード:" << card << endl;

			//Playerに引いたカードを追加
			player->AddCard(card);

			player->ShowStatus();
		}

		if (player->GetTotal() >= BURST_SCORE)
		{
			cout << "\nPlayerはバーストしました\n";
			return false;
		}

	}

}


void Turn::PlayCpuTurn(Player* player, CPU* cpu, CardManager* cardManager)
{
	cout << "\n===========================\n";
	cout << "CPU Turn\n";
	cout << "===========================\n";
	player->ShowStatus();
	cpu->ShowStatus();

	while (true)
	{
		if (cpu->GetTotal() == TARGET_SCORE)
		{
			cout << "CPU'S Total: 21 \n";
			break;
		}

	
		if (cpu->GetTotal() >= BURST_SCORE)
		{
			cout << "\nCPUはバーストしました\n";
			break;
		}
		

		if (cpu ->GetTotal() <= CPU_DRAW_LIMIT)
		{
			cout << "\nCPUは15以下なのでカードを引きます。\n";
		}
		else if (cpu->GetTotal() < player->GetTotal())
		{
			cout << "CPUはPlayerより小さいのでカードを引きます。" << endl;
		}
		else
		{
			cout << "CPUはPlayer以上になりました。" << endl;
			cout << "CPUはカードを引きません。" << endl;

			break;	
		}

		//カードを取得
		int card = cardManager->DrawCard();
		cout << "\nCPUがカードを引きました\n";
		cout << "引いたカード:" << card << endl;
		//CPUに引いたカードを追加
		cpu->AddCard(card);
		cpu->ShowStatus();
	}
}