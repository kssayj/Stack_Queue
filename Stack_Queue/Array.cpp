#include <iostream>
#include<random>
using namespace std;
struct Stack
{
	int top; //индекс верхнего элемента стека
	int* data;
};

void InitStack(Stack& steck, int capacity) //функция инициализации стека
{
	steck.data = new int[capacity];
	steck.top = -1;
}

void push(Stack& steck, int value) //функция добавления элементов в стек
{
	steck.data[++steck.top] = value;
}

int pop(Stack& steck) //функция удаления элементов из стека
{
	return steck.data[steck.top--];
}

void nullStack(Stack& steck) //функция обнуления стека
{
	steck.top = -1;
}

bool EmptyStack(Stack& steck)
{
	return steck.top == -1;
}

void print(Stack& steck) //функция вывода элементов стека в консоль
{
	if (!EmptyStack(steck))
	{
		int i = steck.top; //i - кол-во элементов в стеке
		while (i >= 0)
		{
			cout << steck.data[i--] << " ";
		}
	}
	else
	{
		cout << "Пустой стек";
	}
}

struct Queue
{
	int tail; //индекс последнего элемента в очереди
	int head; //индекс начального элемента в очереди
	int size; //размер очереди
	int* data;
};

void nullQueue(Queue& queue) //функция обнуления очереди
{
	queue.head = 0;
	queue.tail = queue.size - 1;
}

void InitQueue(Queue& queue, int capacity) //функция инициализации очереди 
{
	queue.size = capacity + 1;
	queue.data = new int[queue.size];
	nullQueue(queue);
}

int next(Queue& queue, int n) //функция перехода на следующий индекс элемента очереди
{
	return (n + 1) % queue.size;
}

bool Empty(Queue& queue) //функция, проверяющая на отсутствие элементов очереди
{
	return next(queue, queue.tail) == queue.head;
}

void add(Queue& queue, int value) //функция добавления элементов в очередь
{
	if (next(queue, next(queue, queue.tail)) == queue.head)
	{
		cout << "Очередь переполнена" << endl;
	}
	else
	{
		queue.tail = next(queue, queue.tail);
		queue.data[queue.tail] = value;
	}
}

int del(Queue& queue) //удаление элементов из очереди
{
	if (Empty(queue))
	{
		cout << "Пустая очередь" << endl;
		return 0;
	}
	else
	{
		int d = queue.data[queue.head];
		queue.head = next(queue, queue.head);
		return d;
	}
}

void print(Queue& queue) //функция вывода элементов очереди в консоль
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
		cout << "Пустая очередь";
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	int stackValue;
	double average = 0;
	int capacity_1, capacity_2;
	random_device rd;
	capacity_1 = rd() % 31; //задаем размер для первого стека
	capacity_2 = rd() % 31; //задаем размер для второго стека
	Stack first;
	InitStack(first, capacity_1);
	for (int i = capacity_1; i > 0; i--) //заполняем первый стек значениями 
	{
		stackValue = rd() % 31;
		push(first, stackValue);
	}
	cout << "Первый стек: ";
	print(first);
	cout << endl;
	Stack second;
	InitStack(second, capacity_2);
	for (int i = capacity_2; i > 0; i--) //заполняем второй стек значениями
	{
		stackValue = rd() % 31;
		push(second, stackValue);
	}
	cout << "Второй стек: ";
	print(second);
	cout << endl << endl;
	if (!EmptyStack(second)) {
		for (int i = second.top; i >= 0; i--)
		{
			average += second.data[i];
		}
		cout << "Количество элементов второго стека: " << second.top + 1 << endl;
		cout << "Сумма элементов второго стэка: " << average;
		average /= second.top + 1; //Среднее арифметическое элементов второго стэка
		cout << endl;
		cout << "Среднее арифметическое второго стека: " << average << endl;
	}
	else cout << "\nЗначение среднего арифметического было не найдено, так как второй стек пуст" << endl;
	Queue queue;
	InitQueue(queue, capacity_1);
	for (int i = 0; i < first.top + 1; i++) //заполняем очередь значениями из второго стека, которые меньше среднего арифметического
	{
		if (first.data[i] < average)
		{
			add(queue, first.data[i]);
		}
	}
	cout << endl;
	cout << "Очередь: ";
	print(queue);
	cout << endl << endl;
}