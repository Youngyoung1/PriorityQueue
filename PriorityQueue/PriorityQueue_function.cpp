#include "헤더.h"
#include <iostream>
using namespace std;

Priority_Queue::Priority_Queue()
{
	head = nullptr;
}
bool Priority_Queue::IsEmpty() { if (head == nullptr)return true; else return false; }
void Priority_Queue::Create(int process_id,int priority, int time)
{
	node* newnode=new node(process_id,priority,time);
	if (IsEmpty())
	{
		head = newnode;
	}
	else { // 헤드가 다음 노드를 가리키고 있을 때
		newnode->Next = head;
		head = newnode;
	}
}
void Priority_Queue::Insert(int process_id, int priority, int time)
{
	node* newnode = new node(process_id, priority, time);
	if (IsEmpty() || priority > (head->priority)) {
		newnode->Next = head;
		head = newnode;
	}
	else {
		node* current = head; // 현 노드를 head로 초기화함 
		while (current->Next != nullptr && priority <= current->Next->priority) {
			current = current->Next;
		}
		newnode->Next = current->Next;
		current->Next = newnode;
	}
}
void Priority_Queue::remove() 
{
	if (IsEmpty()){
		cout << "큐가 비었습니다.\n";
		return;}
	node* current = head;
	node* highprioritynode = head;
	node* previous = nullptr;
	// 우선순위가 가장 높은 노드 위치 찾기
	while (current->Next != nullptr) {
		if (current->Next-> priority < highprioritynode->priority) {
			highprioritynode = current->Next;
			previous = current;
		}
		current = current->Next;
	}
	// 첫 노드가 가장 높은 우선순위를 가질 때
	if (previous == nullptr) {
		head = highprioritynode->Next;
	}
	// 첫 번째 노드가 아닌 경우
	else {
		previous->Next = highprioritynode->Next;
	}
	delete highprioritynode;
}

void Priority_Queue::showAll()
{
	node* current = head;
	while (current != nullptr) {
		cout << "프로세스 ID: " << current->process_id << ", 우선순위: " 
		<< current->priority << ", 수행 시간: " << current->time<<"\n";
		current = current->Next;
	}
}