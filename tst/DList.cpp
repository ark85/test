#include "DList.h"
#include "Unit.h"




DList::~DList(void)
{
	while (head) //���� �� ������ �� ������ ������ ���-�� ����
     {
         tail = head->Next; //��������� ����� ������ ���������� ����� ������
         delete head; //������� ������ �� ������� �����
         head = tail; //����� ������ ������ �� ����� ���������� ��������
}
