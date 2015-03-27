#include <iostream>
#include <cassert>
using namespace std;
template <class T>
class D_List
{
private:


   class D_Node
   { public:
         D_Node *next;   // указатель на следующий узел
         D_Node *prev;   // указатель на предыдущий узел
         T val;                 // поле данного
        
         D_Node(T node_val) : val(node_val) { } // конструктор
         D_Node() {}                            // конструктор
         ~D_Node(){}                            // деструктор  
        // для вывода элементов, тип которых определен пользователем,
        // неодходимо перегрузить операцию <<        operator<<( ).
      void print_val( ) { cout << val << " "; }
  };
public:
  class iterator
  {private:
      friend class D_List<T>;
      D_Node * the_node;
   public:
      iterator( ) : the_node(0) { }
      iterator(D_Node * dn) : the_node(dn) { }
       // Copy constructor
      iterator(const iterator & it) : the_node(it.the_node) { }
 
      iterator& operator=(const iterator& it)
          { the_node = it.the_node;
        return *this;
     }
     bool operator==(const iterator& it) const
    { return (the_node == it.the_node); }
     bool operator!=(const iterator& it) const
    { return !(it == *this); }
     iterator& operator++( )
    { if ( the_node == 0 )
           throw "incremented an empty iterator";
       if ( the_node->next == 0 )
           throw "tried to increment too far past the end";
       the_node = the_node->next;
       return *this;
    }
    iterator& operator--( )
    { if ( the_node == 0 )
          throw "decremented an empty iterator";
       if ( the_node->prev == 0 )
          throw "tried to decrement past the beginning";
       the_node = the_node->prev;
       return *this;
    }
    T& operator*( ) const
    { if ( the_node == 0 )
       throw "tried to dereference an empty iterator";
       return the_node->val;
    }
 };
 
private:
  D_Node *head;    // указатель на начало списка
  D_Node *tail;      // указатель на элемент вне списка
  D_List & operator=(const D_List &);
  D_List(const D_List &);
 
  iterator head_iterator;
  iterator tail_iterator;
public:
  D_List( )
  {  head = tail = new D_Node;
      tail->next = 0;
      tail->prev = 0;
      head_iterator = iterator(head);
      tail_iterator = iterator(tail);
  }
         // конструктор  (создание списка, содержащего один элемент)
  D_List(T node_val)
  { head = tail = new D_Node;
     tail->next = 0;        
     tail->prev = 0;
     head_iterator = iterator(head);
     tail_iterator = iterator(tail);
     add_front(node_val);
  }
         //  деструктор
  ~D_List( ) 
  {  D_Node *node_to_delete = head;
      for (D_Node *sn = head; sn != tail;)
     { sn = sn->next;
        delete node_to_delete;
        node_to_delete = sn;
     }
     delete node_to_delete;
  }
  bool is_empty( ) {return head == tail;}
  iterator front( ) { return head_iterator; }
  iterator rear( )  { return tail_iterator; }
  void add_front(T node_val) 
  { D_Node *node_to_add = new D_Node(node_val);
     node_to_add->next = head;
     node_to_add->prev = 0;
     head->prev = node_to_add;
     head = node_to_add;
     head_iterator = iterator(head);
  }
// добавление нового элемента в начало списка
  void add_rear(T node_val) 
  {  if ( is_empty( ) )    // список не пустой
        add_front(node_val);
     else
       // не выполняется для пустого списка, т.к. tail->prev =NULL
       // и, следовательно, tail->prev->next бессмысленно
     { D_Node *node_to_add = new D_Node(node_val);
       node_to_add->next = tail;
       node_to_add->prev = tail->prev;
       tail->prev->next = node_to_add;
       tail->prev = node_to_add;
       tail_iterator = iterator(tail);
    }
  }
  bool remove_it(iterator & key_i) 
  {  for ( D_Node *dn = head; dn != tail; dn = dn->next )
      if ( dn == key_i.the_node )    // найден узел для удаления
     { dn->prev->next = dn->next;
        dn->next->prev = dn->prev;
        delete dn;                            // удаление узла
        key_i.the_node = 0;
        return true;
    }
    return false;
  }
  //  поиск итератора по значению узла
  iterator find(T node_val) const
 {   for ( D_Node *dn = head; dn != tail; dn = dn->next )
      if ( dn->val == node_val ) return iterator(dn);
      return tail_iterator;
  }
   int size( ) const
 {  int count = 0;
    for ( D_Node *dn = head; dn != tail; dn = dn->next ) ++count;
    return count;
 }
  //  Вывод содержимого списка
  void print( ) const
  {    for ( D_Node *dn = head; dn != tail; dn = dn->next )
      dn->print_val( );
      cout << endl;
  }
};
В файле d_list.cpp содержится main-функция, демонстрирующая некоторые примеры работы со списком.
 
#include "dlist_2.h"
typedef int tip;
D_List<tip> the_list;      // создается пустой список
int main()
{ int ret  = 0;
  D_List<tip>::iterator list_iter;
    // занесение значений   0 1 2 3 4  в список
  for (int j = 0; j < 5; ++j)
    the_list.add_front(j);
    // вывод содержимого списка используя компоненту-функцию
    // класса D_List
  the_list.print( );
    // повторный вывод значения содержимого списка
    // используя итератор
  for ( list_iter = the_list.front( ) ;
        list_iter != the_list.rear( ) ;
        ++list_iter )
    cout << *list_iter << " ";
  cout << endl;
    // вывод содержимого списка в обратном порядке
  for ( list_iter = the_list.rear( ) ; list_iter != the_list.front( ) ; )
  {   --list_iter;   // декремент итератора
       cout << *list_iter << " ";
  }
  cout << endl;
  the_list.remove_it(the_list.find(3));
  the_list.print( );
  cout<<the_list.size( )<<endl;
  return 0;
}