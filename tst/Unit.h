#pragma once
template <class T>
class Unit
{
	friend class DList<T>;
	Unit *next1;   // указатель на следующий узел
	Unit *prev1;   // указатель на предыдущий узел
	T value;
public:
	
	Unit(void); // конструктор
	~Unit(void); // деструктор 
	 Unit(T node_val) : val(node_val) { } // конструктор
        // для вывода элементов, тип которых определен пользователем,
        // неодходимо перегрузить операцию <<        operator<<( ).
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

