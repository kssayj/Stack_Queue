#include <iostream>
#include<random>
using namespace std;
struct NodeStack
{
	int data; //�������� �������� �������� 
	NodeStack* next; //��������� �� ��������� ������� �����
};

void InitStack(NodeStack*& top) //�������, ���������������� ����
{
	top = NULL; //����������� ��������� �� ��������� ������� ����� 0
}

void push(NodeStack*& top, int value) //������� ���������� ��������� � ����
{
	NodeStack* tmp = new NodeStack; //����� ���� �����
	tmp->next = top; //����������� ����� ������� �������� �����
	top = tmp; //��������� �� �������� ����� ����������� ����� ������ ���� 
	top->data = value; //������ �������� � ����� ����
}

int pop(NodeStack*& top) //������� �������� ��������� �� �����
{
	NodeStack* tmp = top; //�������� ���������� ��������� �� �������� �����
	int d = top->data; //���������� d ����������� �������� data � �������� �����
	top = top->next; //��������� �� �������� ����� ����������� ����� ���������� �������� �����
	delete(tmp); //������� ��������� ���������
	return d;
}

bool Empty(NodeStack*& top) //������� �������� �� ���������� ���������/�������
{
	return top == NULL; //���� ������, �� ����������� �������� ����� 0
}

void NullStack(NodeStack*& top) //������� ��������� �����
{
	NodeStack* tmp; //�������� ���������� ���������
	while (!Empty(top)) //���� ��������� �� �������� �� ��������� �� 0 
	{
		tmp = top; //���������� ��������� ����������� ����� �������� �����
		top = top->next; //��������� �� �������� ����� ����������� ����� ���������� ��������
		delete(tmp); //������� ��������� ���������
	}
}

void print(NodeStack*& top) //������� ������ ��������� ������ � �������, ���� ������ �� ������ ����
{
	if (!Empty(top))
	{
		NodeStack* tmp = top;
		while (!Empty(tmp))
		{
			cout << tmp->data << " ";
			tmp = tmp->next;
		}
		cout << endl;
		delete(tmp);
	}
}

class Queue
{
private:
	struct Node
	{
		int data;
		Node* next; //��������� �� ��������� �������
	};
	Node* head; //��������� ������ ������� 
	Node* tail; //��������� ����� �������
public:
	Queue() //�����������, ������������� ������� � ���������� ��������� 0
	{
		head = NULL; //����������� ��������� �� ������ ������� 0
		tail = NULL; //����������� ��������� �� ����� ������� 0
	}

	bool empty() //�������, ����������� �� ����������� ��������� � �������
	{
		return head == NULL; //���� ������, �� ����������� ������ ������� 0
	}

	void add(int value) //������� ���������� ��������� � �������
	{
		if (empty()) //���� ������� �����
		{
			head = new Node; //������� ����� ���� � ����������� ��� ����� ��������� �� ������ �������
			head->data = value; //������ �������� � �������
			head->next = NULL; //��������� �� ��������� ������� ������� ����������� 0
			tail = head; //��������� �� ��������� ������� ������� ����������� ����� ��������� �� ��������� ������� �������
		}
		else //���� ������� �� �����, ��
		{
			tail->next = new Node; //������� ����� ���� 
			tail = tail->next; //����������� ����� next ��������� �� ��������� ������� �������
			tail->data = value; //��������� �� ��������� ������� ������� ����������� ����� ������ ����, ������ �������� � ����� �������
			tail->next = NULL; //��������� �� ��������� ������� ����������� 0
		}
	}

	int del() //������� �������� ��������� �� �������
	{
		if (empty()) //���� ������� �����, �� ������� ���������
		{
			cout << "������ �������";
			return 0;
		}
		else //���� ������� �� �����, �� 
		{
			int d = head->data; //������ ���������� d �������� ������ �������
			Node* tmp = head; //������� ��������� ��������� �� ������ �������
			head = head->next; //��������� �� ������ ������� ����������� ����� ���������� ��������
			delete tmp; //������� ��������� ���������
			return d;
		}
	}

	void nullQueue() //������� ��������� �������
	{
		Node* tmp; //������� ��������� ��������� 
		while (!empty()) //���� ������� �� �����
		{
			tmp = head; //���������� ��������� ����������� ����� ������ �������
			head = head->next; //��������� �� ������ ������� ����������� ����� ���������� ��������
			delete tmp; //������� ��������� ���������
		}
	}

	void print() //������� ������ ��������� ������� � �������
	{
		if (!empty())
		{
			Node* tmp = head;
			while (tmp != NULL)
			{
				cout << tmp->data << " ";
				tmp = tmp->next;
			}
			cout << endl;
		}
		else
		{
			cout << "������ �������";
		}
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	int stackValue;
	double average = 0;
	random_device rd;
	int capacity_1, capacity_2;
	capacity_1 = rd() % 31; //������ ������ ��� ������� �����
	capacity_2 = rd() % 31; //������ ������ ��� ������� �����
	NodeStack* first;
	InitStack(first);
	for (int i = capacity_1; i > 0; i--) //��������� ������ ����
	{
		stackValue = rd() % 31;
		push(first, stackValue);
	}
	cout << "������ ����: ";
	print(first);
	NodeStack* second;
	InitStack(second);
	for (int i = capacity_2; i > 0; i--) //��������� ������ ���� 
	{
		stackValue = rd() % 31;
		push(second, stackValue);
	}
	cout << "������ ����: ";
	print(second);
	cout << endl;
	if (!Empty(second)) {
		int i = 0;
		NodeStack* current = second;
		while (current != NULL)
		{
			average += current->data;
			current = current->next;
			i++;
		}
		cout << "���������� ��������� ������� �����: " << i << endl;
		cout << "����� ��������� ������� �����: " << average << endl;
		average /= i; //������� �������������� ��������� 2 �����
		cout << "������� �������������� ������� �����: " << average << endl;
	}
	else cout << "\n�������� �������� ��������������� ���� �� �������, ��� ��� ������ ���� ����" << endl;
	Queue queue;
	for (NodeStack* tmp = first; tmp != NULL; tmp = tmp->next) //��������� ������� ���������� ������� �����
	{
		if (tmp->data < average)
		{
			queue.add(tmp->data);
		}
	}
	cout << endl;
	cout << "�������: ";
	queue.print();
	cout << endl;
}