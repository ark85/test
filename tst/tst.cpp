#include <iostream>
#include <cassert>
using namespace std;
template <class T>
class D_List
{
private:


   class D_Node
   { public:
         D_Node *next;   // ��������� �� ��������� ����
         D_Node *prev;   // ��������� �� ���������� ����
         T val;                 // ���� �������
        
         D_Node(T node_val) : val(node_val) { } // �����������
         D_Node() {}                            // �����������
         ~D_Node(){}                            // ����������  
        // ��� ������ ���������, ��� ������� ��������� �������������,
        // ���������� ����������� �������� <<        operator<<( ).
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
  D_Node *head;    // ��������� �� ������ ������
  D_Node *tail;      // ��������� �� ������� ��� ������
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
         // �����������  (�������� ������, ����������� ���� �������)
  D_List(T node_val)
  { head = tail = new D_Node;
     tail->next = 0;        
     tail->prev = 0;
     head_iterator = iterator(head);
     tail_iterator = iterator(tail);
     add_front(node_val);
  }
         //  ����������
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
// ���������� ������ �������� � ������ ������
  void add_rear(T node_val) 
  {  if ( is_empty( ) )    // ������ �� ������
        add_front(node_val);
     else
       // �� ����������� ��� ������� ������, �.�. tail->prev =NULL
       // �, �������������, tail->prev->next ������������
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
      if ( dn == key_i.the_node )    // ������ ���� ��� ��������
     { dn->prev->next = dn->next;
        dn->next->prev = dn->prev;
        delete dn;                            // �������� ����
        key_i.the_node = 0;
        return true;
    }
    return false;
  }
  //  ����� ��������� �� �������� ����
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
  //  ����� ����������� ������
  void print( ) const
  {    for ( D_Node *dn = head; dn != tail; dn = dn->next )
      dn->print_val( );
      cout << endl;
  }
};
� ����� d_list.cpp ���������� main-�������, ��������������� ��������� ������� ������ �� �������.
 
#include "dlist_2.h"
typedef int tip;
D_List<tip> the_list;      // ��������� ������ ������
int main()
{ int ret  = 0;
  D_List<tip>::iterator list_iter;
    // ��������� ��������   0 1 2 3 4  � ������
  for (int j = 0; j < 5; ++j)
    the_list.add_front(j);
    // ����� ����������� ������ ��������� ����������-�������
    // ������ D_List
  the_list.print( );
    // ��������� ����� �������� ����������� ������
    // ��������� ��������
  for ( list_iter = the_list.front( ) ;
        list_iter != the_list.rear( ) ;
        ++list_iter )
    cout << *list_iter << " ";
  cout << endl;
    // ����� ����������� ������ � �������� �������
  for ( list_iter = the_list.rear( ) ; list_iter != the_list.front( ) ; )
  {   --list_iter;   // ��������� ���������
       cout << *list_iter << " ";
  }
  cout << endl;
  the_list.remove_it(the_list.find(3));
  the_list.print( );
  cout<<the_list.size( )<<endl;
  return 0;
}