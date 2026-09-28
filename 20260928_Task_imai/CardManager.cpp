#include "CardManager.h"
#include <cstdlib>
#include <ctime>

CardManager::CardManager()
{
	cardCount = CARD_TOTAL;
}

void CardManager::CreateCards()
{
	int index = 0;
	//カード作成
	for (int number = CARD_MIN; number <= CARD_MAX; number++)
	{
		for (int i = 0; i < CARD_DUPLICATE_COUNT; i++)
		{
			cards[index] = number;
			index++;
		}
	}

	cardCount = CARD_TOTAL;

}

void CardManager::ShuffleCards()
{
	//シャフル
	for (int j = 0; j < CARD_TOTAL; j++)
	{
		int randomIndex = j + rand() % (CARD_TOTAL - j);
		int temp = cards[j];
		cards[j] = cards[randomIndex];
		cards[randomIndex] = temp;
	}
}

int CardManager::DrawCard()
{
	int card = cards[0];

	//残りのカードを前詰める
	for (int i = 0; i < cardCount - 1; i++)
	{
		cards[i] = cards[i + 1];
	}

	cardCount--;

	return card;
}

int CardManager::GetCardCount()
{
	return cardCount;
}