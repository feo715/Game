#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

string job[4] = { "시민","경찰","의사","마피아" };

struct people
{
	int job;  // 0 시민 1 경찰 2 의사 3 마피아
	int life;
};

int main()
{
	srand(time(NULL));

	int member;
	int doctor;
	int cop;
	int citizen;
	int mafia;

	cout << "멤버 수를 입력하세요 :";
	cin >> member;
	cout << "마피아 수를 입력하세요 :";
	cin >> mafia;
	cout << "의사 수를 입력하세요 :";
	cin >> doctor;
	cout << "경찰 수를 입력하세요 :";
	cin >> cop;
	citizen = member - mafia - doctor - cop;
	system("cls");

	people* person = new people[member];
	while (1)
	{
		int t;
		for (int i = 0; i < member; i++)
		{
			person[i].job = -1;
			person[i].life = 1;
		}
		for (int i = 0; i < cop;)
		{
			t = rand() % member;
			if (person[t].job == -1)
			{
				person[t].job = 1;
				i++;
			}
		}
		for (int i = 0; i < cop;)
		{
			t = rand() % member;
			if (person[t].job == -1)
			{
				person[t].job = 2;
				i++;
			}
		}
		for (int i = 0; i < mafia;)
		{
			t = rand() % member;
			if (person[t].job == -1)
			{
				person[t].job = 3;
				i++;
			}
		}
		for (int i = 0; i < member; i++)
			if (person[i].job == -1)
				person[i].job = 0;
				
		while (1)
		{
			int n, m, d, c;
			for (int i = 0; i < member; i++)
			{
				system("cls");
				if (person[i].life)
				{
					cout << "밤이 되었습니다!" << endl;
					cout << i << " 님은 엔터를 누르고 행동을 시작하세요!" << endl;
					n = _getch();
					system("cls");
					cout << "당신은 " << job[person[i].job] << " 입니다!" << endl;

					if (person[i].job == 0)
					{
						cout << "아무 숫자나 입력하세요!" << endl;
						cin >> n;
					}
					else if (person[i].job == 1)
					{
						cout << "조사할 사람의 숫자를 입력하세요!" << endl;
						cin >> c;
						cout << "그 사람은 " << job[person[c].job] << "입니다" << endl;
						cout << "잠시후 메세지가 지워집니다 메세지가 지워지면 다음 사람에게 넘기세요!" << endl;
						Sleep(2000);
					}
					else if (person[i].job == 2)
					{
						cout << "살릴 사람의 숫자를 입력하세요!" << endl;
						cin >> d;
					}
					else if (person[i].job == 3)
					{
						cout << "죽일 사람의 숫자를 입력하세요!" << endl;
						cin >> m;
					}
				}
			}

			system("cls");
			cout << "낮이 되었습니다!" << endl << endl;
			int calive = 0;
			int malive = 0;
			if (m == c && (person[c].life == 1))
			{
				cout << c << " 님이 의사의 진료로 살아났습니다!" << endl;
			}
			else
			{
				cout << m << " 님이 마피아에게 사살당했습니다!" << endl;
				person[m].life = 0;
			}

			for (int i = 0; i < member; i++)
				if (person[i].life)
				{
					if (person[i].job == 3)
						malive++;
					else
						calive++;
				}
			if (malive >= calive)
			{
				cout << "마피아팀 승리!" << endl;
				cout << "계속하기: 엔터" << endl;
				_getch();
				break;
			}
			else if (malive == 0)
			{
				cout << "시민팀 승리!" << endl;
				cout << "계속하기: 엔터" << endl;
				_getch();
				break;
			}

			cout << endl << endl << "투표를 하여 죽일 사람의 번호를 입력하세요!" << endl;
			int vote;
			cin >> vote;
			person[vote].life = 0;
			cout << vote << "님 사망!" << endl;
			cout << "3초후 밤이 시작됩니다!" << endl;
			Sleep(3000);

			for (int i = 0; i < member; i++)
				if (person[i].life)
				{
					if (person[i].job == 3)
						malive++;
					else
						calive++;
				}
			if (malive >= calive)
			{
				cout << "마피아팀 승리!" << endl;
				cout << "계속하기: 엔터" << endl;
				_getch();
				break;
			}
			else if (malive == 0)
			{
				cout << "시민팀 승리!" << endl;
				cout << "계속하기: 엔터" << endl;
				_getch();
				break;
			}
		}
	}
	return 0;
}