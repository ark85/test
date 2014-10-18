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
	DList(): head(NULL) , tail(NULL) , count(0) {}; // ������������ �� ���������
	~DList() // ����������
	{
		while (head) //���� �� ������ �� ������ ������ ���-�� ����
		{
			tail = head->Next; //��������� ����� ������ ���������� ����� ������
			delete head; //������� ������ �� ������� �����
			head = tail; //����� ������ ������ �� ����� ���������� ��������
		}
		delete count;
	}
	bool empty() // ������ �� ������
	{
		return count;
	}
	unsigned size() // ������� ��������� � ������
	{
		return count;
	}
	void clear() // �������� ������
	{
		while (head) //���� �� ������ �� ������ ������ ���-�� ����
		{
			tail = head->Next; //��������� ����� ������ ���������� ����� ������
			delete head; //������� ������ �� ������� �����
			head = tail; //����� ������ ������ �� ����� ���������� ��������
		}
		head = NULL;
		tail = NULL;
		count = 0;
	}

	Unit* first() // ������� 1-� �������
	{
		return head;
	}
	Unit* last() // ������� ��������� �������
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

