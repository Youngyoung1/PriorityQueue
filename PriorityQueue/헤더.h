#pragma once

struct node {
	int process_id;
	int priority;
	int time;
	node* Next;
	node(int process_id, int priority, int time) {
		this->process_id = process_id;
		this->priority = priority;
		this->time = time;
		Next = nullptr;
	}
};
class Priority_Queue {
public:
	node* head;
	Priority_Queue();
	bool IsEmpty();
	void Create(int process_id,int priority,int time);
	void Insert(int process_id, int priority, int time);
	void remove();
	void showAll();
};
