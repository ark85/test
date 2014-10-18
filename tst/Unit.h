#pragma once
template <class T>
class Unit
{
	friend class DList<T>;
	Unit *next1;   // ��������� �� ��������� ����
	Unit *prev1;   // ��������� �� ���������� ����
	T value;
public:
	
	Unit(void); // �����������
	~Unit(void); // ���������� 
	 Unit(T node_val) : val(node_val) { } // �����������
        // ��� ������ ���������, ��� ������� ��������� �������������,
        // ���������� ����������� �������� <<        operator<<( ).
	 T& val()
	 {
		 return &value;
	 }
	 Unit *next()
	 {
		 return next1;
	 }
	 Unit *prev()
	 {
		 prev1;
	 }
};

