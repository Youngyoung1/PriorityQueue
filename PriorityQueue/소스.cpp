#include <iostream>
#include "헤더.h"
using namespace std;
void printMenu();
int main()
{
	Priority_Queue pq;
	int counter=0, process_id, priority, time;
	int Menu;
	while (1) 
	{
		cout << "메뉴를 입력하시오: \n\n";
		printMenu();
		cin >> Menu;
		switch (Menu) 
		{
		case 1: // 첫 노드 생성 Create 함수
			cout << "프로세스 ID를 입력하시오 ";
			cin >> process_id;
			cout << "우선순위를 입력하시오:  ";
			cin >> priority;
			cout << "수행 시간을 입력하시오: ";
			cin >> time;
			pq.Create(process_id, priority, time);
			counter++;
			break;
		case 2: // 우선순위 젤 높은 노드 삭제 Remove 함수
			pq.remove();
			counter--;
			break;
		case 3: // 노드 중간에 삽입하는 Insert 함수
			cout << "프로세스 ID를 입력하시오 ";
			cin >> process_id;
			cout << "우선순위를 입력하시오:  ";
			cin >> priority;
			cout << "수행 시간을 입력하시오: ";
			cin >> time;
			pq.Insert(process_id, priority, time);
			counter++;
			break;
		case 4: // 모든 노드 보여주는 ShowAll 함수
			pq.showAll();
			cout << "큐의 개수: " << counter<<"\n\n";
			break;
		case 5: // 프로그램 종료 함수
			cout << "프로그램을 종료합니다.\n";
			return 0;
		default:
			cout << "유효하지 않은 옵션입니다. \n";
			break;
		}
	}
}

void printMenu()
{
	cout << "=============================================\n";
	cout << ("1.우선순위 큐 생성\n\n");
	cout << ("2.우선순위 큐 삭제\n\n");
	cout << ("3.우선순위 큐 삽입\n\n");
	cout << ("4.모든 큐 보기\n\n");
	cout << ("5.프로그램 종료\n");
	cout << ("--------------------------------------------\n");
	cout << ("\n 메뉴를 입력하세요:\n");
}