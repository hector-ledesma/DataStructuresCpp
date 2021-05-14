#pragma once
class Queue1
{
private:
	int front;
	int rear;
	int size;
	int* Q;
public:
	Queue1(int sz);
	void queue(int x);
	int dequeue();
	void Display();
};

