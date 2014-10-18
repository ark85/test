#pragma once
#include "Unit.h"
template <class T>
class  DList
{
	int count;
	Unit *val;
	Unit *head;
	Unit *tail;
public:
	DList(): head(NULL) , tail(NULL) , count(0) {}; // Конеструктор по умолчанию
	~DList() // Деструктор
	{
		while (head) //Пока по адресу на начало списка что-то есть
		{
			tail = head->Next; //Резервная копия адреса следующего звена списка
			delete head; //Очистка памяти от первого звена
			head = tail; //Смена адреса начала на адрес следующего элемента
		}
		delete count;
	}
	bool empty() // пустой ли список
	{
		return count;
	}
	unsigned size() // сколько элементов в списке
	{
		return count;
	}
	void clear() // очистить список
	{
		while (head) //Пока по адресу на начало списка что-то есть
		{
			tail = head->Next; //Резервная копия адреса следующего звена списка
			delete head; //Очистка памяти от первого звена
			head = tail; //Смена адреса начала на адрес следующего элемента
		}
		head = NULL;
		tail = NULL;
		count = 0;
	}

	Unit* first() // вернуть 1-й элемент
	{
		return head;
	}
	Unit* last() // вернуть последний элемент
	{
		return tail;
	}

	void push_front (const T& val);
	{
		if (empty))
		{

		}
	}

};

