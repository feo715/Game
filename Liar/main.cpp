#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

string topic[10] = { "��ȭ","�ι�","����","������","����","�츮�� ����","����","����","����","����" };
int main()
{
	srand(time(NULL));

	int member = 0;
	cout << "��� ���� �Է��ϼ��� :";
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
				cout << "����: " << topic[topic_index] << endl;
				cout << "����� ���̾� �Դϴ�! ���þ �Է��ϴ� ô�� �ϼ���: ";
				cin >> temp;
				system("cls");
			}
			else
			{
				cout << "����: " << topic[topic_index] << endl;
				cout << "���þ �Է��� �ּ���: ";
				cin >> answer[t];
				t++;
				system("cls");
			}
		}
		answer_index = rand() % (member - 1);

		for (int i = 0; i < member; i++)
		{
			char c;
			cout << "���þ� ���� �Ϸ�!" << endl << "���ʴ�� ���͸� �Է��Ͽ� ���þ Ȯ���ϼ���!" << endl;
			c = _getch();

			if (i == liar)
			{
				cout << "����� ���̾� �Դϴ�!" << endl << endl << endl;
				cout << "���͸� �Է����� ���� ������� �ѱ⼼��!" << endl;
				c = _getch();
				system("cls");
			}
			else
			{
				cout << "���þ�: " << answer[answer_index] << endl << endl << endl;
				cout << "���͸� �Է����� ���� ������� �ѱ⼼��!" << endl;
				c = _getch();
				system("cls");
			}
		}

		int cont = 0;
		cout << "�̾��ϱ�: 1" << endl;
		cin >> cont;

		if (cont == 1)
			continue;
		else
			break;
		system("cls");
	}

	return 0;
}

