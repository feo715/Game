#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

string job[4] = { "�ù�","����","�ǻ�","���Ǿ�" };

struct people
{
	int job;  // 0 �ù� 1 ���� 2 �ǻ� 3 ���Ǿ�
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

	cout << "��� ���� �Է��ϼ��� :";
	cin >> member;
	cout << "���Ǿ� ���� �Է��ϼ��� :";
	cin >> mafia;
	cout << "�ǻ� ���� �Է��ϼ��� :";
	cin >> doctor;
	cout << "���� ���� �Է��ϼ��� :";
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
					cout << "���� �Ǿ����ϴ�!" << endl;
					cout << i << " ���� ���͸� ������ �ൿ�� �����ϼ���!" << endl;
					n = _getch();
					system("cls");
					cout << "����� " << job[person[i].job] << " �Դϴ�!" << endl;

					if (person[i].job == 0)
					{
						cout << "�ƹ� ���ڳ� �Է��ϼ���!" << endl;
						cin >> n;
					}
					else if (person[i].job == 1)
					{
						cout << "������ ����� ���ڸ� �Է��ϼ���!" << endl;
						cin >> c;
						cout << "�� ����� " << job[person[c].job] << "�Դϴ�" << endl;
						cout << "����� �޼����� �������ϴ� �޼����� �������� ���� ������� �ѱ⼼��!" << endl;
						Sleep(2000);
					}
					else if (person[i].job == 2)
					{
						cout << "�츱 ����� ���ڸ� �Է��ϼ���!" << endl;
						cin >> d;
					}
					else if (person[i].job == 3)
					{
						cout << "���� ����� ���ڸ� �Է��ϼ���!" << endl;
						cin >> m;
					}
				}
			}

			system("cls");
			cout << "���� �Ǿ����ϴ�!" << endl << endl;
			int calive = 0;
			int malive = 0;
			if (m == c && (person[c].life == 1))
			{
				cout << c << " ���� �ǻ��� ����� ��Ƴ����ϴ�!" << endl;
			}
			else
			{
				cout << m << " ���� ���Ǿƿ��� �����߽��ϴ�!" << endl;
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
				cout << "���Ǿ��� �¸�!" << endl;
				cout << "����ϱ�: ����" << endl;
				_getch();
				break;
			}
			else if (malive == 0)
			{
				cout << "�ù��� �¸�!" << endl;
				cout << "����ϱ�: ����" << endl;
				_getch();
				break;
			}

			cout << endl << endl << "��ǥ�� �Ͽ� ���� ����� ��ȣ�� �Է��ϼ���!" << endl;
			int vote;
			cin >> vote;
			person[vote].life = 0;
			cout << vote << "�� ���!" << endl;
			cout << "3���� ���� ���۵˴ϴ�!" << endl;
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
				cout << "���Ǿ��� �¸�!" << endl;
				cout << "����ϱ�: ����" << endl;
				_getch();
				break;
			}
			else if (malive == 0)
			{
				cout << "�ù��� �¸�!" << endl;
				cout << "����ϱ�: ����" << endl;
				_getch();
				break;
			}
		}
	}
	return 0;
}