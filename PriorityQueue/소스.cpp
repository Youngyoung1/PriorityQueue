#include <iostream>
#include "���.h"
using namespace std;
void printMenu();
int main()
{
	Priority_Queue pq;
	int counter=0, process_id, priority, time;
	int Menu;
	while (1) 
	{
		cout << "�޴��� �Է��Ͻÿ�: \n\n";
		printMenu();
		cin >> Menu;
		switch (Menu) 
		{
		case 1: // ù ��� ���� Create �Լ�
			cout << "���μ��� ID�� �Է��Ͻÿ� ";
			cin >> process_id;
			cout << "�켱������ �Է��Ͻÿ�:  ";
			cin >> priority;
			cout << "���� �ð��� �Է��Ͻÿ�: ";
			cin >> time;
			pq.Create(process_id, priority, time);
			counter++;
			break;
		case 2: // �켱���� �� ���� ��� ���� Remove �Լ�
			pq.remove();
			counter--;
			break;
		case 3: // ��� �߰��� �����ϴ� Insert �Լ�
			cout << "���μ��� ID�� �Է��Ͻÿ� ";
			cin >> process_id;
			cout << "�켱������ �Է��Ͻÿ�:  ";
			cin >> priority;
			cout << "���� �ð��� �Է��Ͻÿ�: ";
			cin >> time;
			pq.Insert(process_id, priority, time);
			counter++;
			break;
		case 4: // ��� ��� �����ִ� ShowAll �Լ�
			pq.showAll();
			cout << "ť�� ����: " << counter<<"\n\n";
			break;
		case 5: // ���α׷� ���� �Լ�
			cout << "���α׷��� �����մϴ�.\n";
			return 0;
		default:
			cout << "��ȿ���� ���� �ɼ��Դϴ�. \n";
			break;
		}
	}
}

void printMenu()
{
	cout << "=============================================\n";
	cout << ("1.�켱���� ť ����\n\n");
	cout << ("2.�켱���� ť ����\n\n");
	cout << ("3.�켱���� ť ����\n\n");
	cout << ("4.��� ť ����\n\n");
	cout << ("5.���α׷� ����\n");
	cout << ("--------------------------------------------\n");
	cout << ("\n �޴��� �Է��ϼ���:\n");
}