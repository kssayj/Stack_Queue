#include <iostream>
#include<random>
using namespace std;
struct Stack
{
	int top; //������ �������� �������� �����
	int* data;
};

void InitStack(Stack& steck, int capacity) //������� ������������� �����
{
	steck.data = new int[capacity];
	steck.top = -1;
}

void push(Stack& steck, int value) //������� ���������� ��������� � ����
{
	steck.data[++steck.top] = value;
}

int pop(Stack& steck) //������� �������� ��������� �� �����
{
	return steck.data[steck.top--];
}

void nullStack(Stack& steck) //������� ��������� �����
{
	steck.top = -1;
}

bool EmptyStack(Stack& steck)
{
	return steck.top == -1;
}

void print(Stack& steck) //������� ������ ��������� ����� � �������
{
	if (!EmptyStack(steck))
	{
		int i = steck.top; //i - ���-�� ��������� � �����
		while (i >= 0)
		{
			cout << steck.data[i--] << " ";
		}
	}
	else
	{
		cout << "������ ����";
	}
}

struct Queue
{
	int tail; //������ ���������� �������� � �������
	int head; //������ ���������� �������� � �������
	int size; //������ �������
	int* data;
};

void nullQueue(Queue& queue) //������� ��������� �������
{
	queue.head = 0;
	queue.tail = queue.size - 1;
}

void InitQueue(Queue& queue, int capacity) //������� ������������� ������� 
{
	queue.size = capacity + 1;
	queue.data = new int[queue.size];
	nullQueue(queue);
}

int next(Queue& queue, int n) //������� �������� �� ��������� ������ �������� �������
{
	return (n + 1) % queue.size;
}

bool Empty(Queue& queue) //�������, ����������� �� ���������� ��������� �������
{
	return next(queue, queue.tail) == queue.head;
}

void add(Queue& queue, int value) //������� ���������� ��������� � �������
{
	if (next(queue, next(queue, queue.tail)) == queue.head)
	{
		cout << "������� �����������" << endl;
	}
	else
	{
		queue.tail = next(queue, queue.tail);
		queue.data[queue.tail] = value;
	}
}

int del(Queue& queue) //�������� ��������� �� �������
{
	if (Empty(queue))
	{
		cout << "������ �������" << endl;
		return 0;
	}
	else
	{
		int d = queue.data[queue.head];
		queue.head = next(queue, queue.head);
		return d;
	}
}

void print(Queue& queue) //������� ������ ��������� ������� � �������
{
	if (!Empty(queue))
	{
		int i = queue.head;
		while (i != queue.tail)
		{
			cout << queue.data[i] << " ";
			i = next(queue, i);
		}
		cout << queue.data[queue.tail];
	}
	else {
		cout << "������ �������";
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	int stackValue;
	double average = 0;
	int capacity_1, capacity_2;
	random_device rd;
	capacity_1 = rd() % 31; //������ ������ ��� ������� �����
	capacity_2 = rd() % 31; //������ ������ ��� ������� �����
	Stack first;
	InitStack(first, capacity_1);
	for (int i = capacity_1; i > 0; i--) //��������� ������ ���� ���������� 
	{
		stackValue = rd() % 31;
		push(first, stackValue);
	}
	cout << "������ ����: ";
	print(first);
	cout << endl;
	Stack second;
	InitStack(second, capacity_2);
	for (int i = capacity_2; i > 0; i--) //��������� ������ ���� ����������
	{
		stackValue = rd() % 31;
		push(second, stackValue);
	}
	cout << "������ ����: ";
	print(second);
	cout << endl << endl;
	if (!EmptyStack(second)) {
		for (int i = second.top; i >= 0; i--)
		{
			average += second.data[i];
		}
		cout << "���������� ��������� ������� �����: " << second.top + 1 << endl;
		cout << "����� ��������� ������� �����: " << average;
		average /= second.top + 1; //������� �������������� ��������� ������� �����
		cout << endl;
		cout << "������� �������������� ������� �����: " << average << endl;
	}
	else cout << "\n�������� �������� ��������������� ���� �� �������, ��� ��� ������ ���� ����" << endl;
	Queue queue;
	InitQueue(queue, capacity_1);
	for (int i = 0; i < first.top + 1; i++) //��������� ������� ���������� �� ������� �����, ������� ������ �������� ���������������
	{
		if (first.data[i] < average)
		{
			add(queue, first.data[i]);
		}
	}
	cout << endl;
	cout << "�������: ";
	print(queue);
	cout << endl << endl;
}