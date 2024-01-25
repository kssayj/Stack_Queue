#include <iostream>
#include<random>
using namespace std;
struct NodeStack
{
	int data; //хранение значения элемента 
	NodeStack* next; //указатель на следующий элемент стека
};

void InitStack(NodeStack*& top) //функция, инициализирующая стек
{
	top = NULL; //присваиваем указателю на начальный элемент стека 0
}

void push(NodeStack*& top, int value) //функция добавления элементов в стек
{
	NodeStack* tmp = new NodeStack; //новый узел стека
	tmp->next = top; //присваиваем адрес текущей верхушки стека
	top = tmp; //указателю на верхушку стека присваиваем адрес нового узла 
	top->data = value; //вносим значение в новый узел
}

int pop(NodeStack*& top) //функция удаления элементов из стека
{
	NodeStack* tmp = top; //создание временного указателя на верхушку стека
	int d = top->data; //переменной d присваиваем значение data у верхушки стека
	top = top->next; //указателю на верхушку стека присваиваем адрес следующего элемента стека
	delete(tmp); //удаляем временный указатель
	return d;
}

bool Empty(NodeStack*& top) //функция проверки на отсутствие элементов/пустоту
{
	return top == NULL; //если пустой, то присваиваем верхушке стека 0
}

void NullStack(NodeStack*& top) //функция обнуления стека
{
	NodeStack* tmp; //создание временного указателя
	while (!Empty(top)) //пока указатель на верхушку не указывает на 0 
	{
		tmp = top; //временному указателю присваиваем адрес верхушки стека
		top = top->next; //указателю на верхушку стека присваиваем адрес следующего элемента
		delete(tmp); //удаляем временный указатель
	}
}

void print(NodeStack*& top) //функция вывода элементов списка в консоль, пока список не станет пуст
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
		Node* next; //указатель на следующий элемент
	};
	Node* head; //указатель начала очереди 
	Node* tail; //указатель конца очереди
public:
	Queue() //конструктор, присваивающий первому и последнему элементам 0
	{
		head = NULL; //присваиваем указателю на начало очереди 0
		tail = NULL; //присваиваем указателю на конец очереди 0
	}

	bool empty() //функция, проверяющая на отстутствие элементов в очереди
	{
		return head == NULL; //если пустой, то присваиваем началу очереди 0
	}

	void add(int value) //функция добавления элементов в очередь
	{
		if (empty()) //если очередь пуста
		{
			head = new Node; //создаем новый узел и присваиваем его адрес указателю на начало очереди
			head->data = value; //вносим значение в элемент
			head->next = NULL; //указателю на начальный элемент очереди присваиваем 0
			tail = head; //указателю на последний элемент очереди присваиваем адрес указателя на начальный элемент очереди
		}
		else //если очередь не пуста, то
		{
			tail->next = new Node; //создаем новый узел 
			tail = tail->next; //присваиваем адрес next указателя на последний элемент очереди
			tail->data = value; //указателю на последний элемент очереди присваиваем адрес нового узла, вносим значение в новый элемент
			tail->next = NULL; //указатель на последний элемент присваиваем 0
		}
	}

	int del() //функция удаления элементов из очереди
	{
		if (empty()) //если очередь пуста, то выводим сообщение
		{
			cout << "Пустая очередь";
			return 0;
		}
		else //если очередь не пуста, то 
		{
			int d = head->data; //вносим переменной d значение начала очереди
			Node* tmp = head; //создаем временный указатель на начало очереди
			head = head->next; //указателю на начало очереди присваиваем адрес следующего элемента
			delete tmp; //удаляем временный указатель
			return d;
		}
	}

	void nullQueue() //функция обнуления очереди
	{
		Node* tmp; //создаем временный указатель 
		while (!empty()) //пока очередь не пуста
		{
			tmp = head; //временному указателю присваиваем адрес начала очереди
			head = head->next; //указателю на начало очереди присваиваем адрес следующего элемента
			delete tmp; //удаляем временный указатель
		}
	}

	void print() //функция вывода элементов очереди в консоль
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
			cout << "Пустая очередь";
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
	capacity_1 = rd() % 31; //задаем размер для первого стека
	capacity_2 = rd() % 31; //задаем размер для второго стека
	NodeStack* first;
	InitStack(first);
	for (int i = capacity_1; i > 0; i--) //заполняем первый стек
	{
		stackValue = rd() % 31;
		push(first, stackValue);
	}
	cout << "Первый стек: ";
	print(first);
	NodeStack* second;
	InitStack(second);
	for (int i = capacity_2; i > 0; i--) //заполняем второй стек 
	{
		stackValue = rd() % 31;
		push(second, stackValue);
	}
	cout << "Второй стек: ";
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
		cout << "Количество элементов второго стека: " << i << endl;
		cout << "Сумма элементов второго стэка: " << average << endl;
		average /= i; //Среднее арифметическое элементов 2 стэка
		cout << "Среднее арифметическое второго стека: " << average << endl;
	}
	else cout << "\nЗначение среднего арифметического было не найдено, так как второй стек пуст" << endl;
	Queue queue;
	for (NodeStack* tmp = first; tmp != NULL; tmp = tmp->next) //заполняем очередь элементами первого стека
	{
		if (tmp->data < average)
		{
			queue.add(tmp->data);
		}
	}
	cout << endl;
	cout << "Очередь: ";
	queue.print();
	cout << endl;
}