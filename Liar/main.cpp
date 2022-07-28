#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

string topic[10] = { "영화","인물","나라","스포츠","게임","우리과 교수","직업","음식","동물","물건" };
int main()
{
	srand(time(NULL));

	int member = 0;
	cout << "멤버 수를 입력하세요 :";
	cin >> member;
	system("cls");

	int liar, topic_index, answer_index, t;
	string *answer = new string[5];
	string temp;
	while (1)
	{
		t = 0;
		liar= rand() % member;
		topic_index = rand() % 10;

		for (int i = 0; i < member; i++)
		{
			
			if (i == liar)
			{
				cout << "주제: " << topic[topic_index] << endl;
				cout << "당신은 라이어 입니다! 제시어를 입력하는 척을 하세요: ";
				cin >> temp;
				system("cls");
			}
			else
			{
				cout << "주제: " << topic[topic_index] << endl;
				cout << "제시어를 입력해 주세요: ";
				cin >> answer[t];
				t++;
				system("cls");
			}
		}
		answer_index = rand() % (member - 1);

		for (int i = 0; i < member; i++)
		{
			char c;
			cout << "제시어 결정 완료!" << endl << "차례대로 엔터를 입력하여 제시어를 확인하세요!" << endl;
			c = _getch();

			if (i == liar)
			{
				cout << "당신은 라이어 입니다!" << endl << endl << endl;
				cout << "엔터를 입력한후 다음 사람에게 넘기세요!" << endl;
				c = _getch();
				system("cls");
			}
			else
			{
				cout << "제시어: " << answer[answer_index] << endl << endl << endl;
				cout << "엔터를 입력한후 다음 사람에게 넘기세요!" << endl;
				c = _getch();
				system("cls");
			}
		}

		int cont = 0;
		cout << "이어하기: 1" << endl;
		cin >> cont;

		if (cont == 1)
			continue;
		else
			break;
		system("cls");
	}

	return 0;
}

