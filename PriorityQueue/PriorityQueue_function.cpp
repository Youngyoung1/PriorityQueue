#include "���.h"
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
	else { // ��尡 ���� ��带 ����Ű�� ���� ��
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
		node* current = head; // �� ��带 head�� �ʱ�ȭ�� 
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
		cout << "ť�� ������ϴ�.\n";
		return;}
	node* current = head;
	node* highprioritynode = head;
	node* previous = nullptr;
	// �켱������ ���� ���� ��� ��ġ ã��
	while (current->Next != nullptr) {
		if (current->Next-> priority < highprioritynode->priority) {
			highprioritynode = current->Next;
			previous = current;
		}
		current = current->Next;
	}
	// ù ��尡 ���� ���� �켱������ ���� ��
	if (previous == nullptr) {
		head = highprioritynode->Next;
	}
	// ù ��° ��尡 �ƴ� ���
	else {
		previous->Next = highprioritynode->Next;
	}
	delete highprioritynode;
}

void Priority_Queue::showAll()
{
	node* current = head;
	while (current != nullptr) {
		cout << "���μ��� ID: " << current->process_id << ", �켱����: " 
		<< current->priority << ", ���� �ð�: " << current->time<<"\n";
		current = current->Next;
	}
}