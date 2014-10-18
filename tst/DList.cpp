#include "DList.h"
#include "Unit.h"




DList::~DList(void)
{
	while (head) //Пока по адресу на начало списка что-то есть
     {
         tail = head->Next; //Резервная копия адреса следующего звена списка
         delete head; //Очистка памяти от первого звена
         head = tail; //Смена адреса начала на адрес следующего элемента
}
