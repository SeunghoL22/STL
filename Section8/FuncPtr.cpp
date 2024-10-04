#include <iostream>
using namespace std;
#include <vector>
#include <queue>

void Print()
{
	cout << "Hello World" << endl;
}

#if 0
int Add(int a, int b)
{
	cout << a + b << endl;
	return a + b;
}

// �ݹ� �Լ�
// -ex) UI���� ��ư�� ������ � �Լ��� ������ �Ǿ���Ѵٰ� �� ��, �ᱹ � ������ ���ڷ� �Ѱ������ �ʿ䰡 �ִٰ� �� �� �ִ�.
// -ex) �¶��� ���� Ŭ�� �������� �� ������ � �ൿ�� ���� ������ ���� �����ϱ� �Լ������ͷ� ������ �������༭ ó���Ѵ�.
// -ex) Ű���� �Է� - Ư�� Ű�� ������ �����ΰ��� �Ͼ�ٰ� �Ҷ�, ���� ���̶�� �ϸ� Q��ư�� ������ ��ų�� �����µ�
//					  ���� ����Ű�� �����ؼ� �ٸ� Ű�� ������ �� �ش� ��ų�� ������ �ؾ��Ѵٸ� �Լ� �����͸� �̿��ϴ°� ����

// �ൿ ��ü�� ���ڷ� �ѱ�� ���� �� �Լ������͸� �̿��ϸ� ����.
using FuncPtrT = int(*)(int a, int b);

int DoSomething(int a, int b, FuncPtrT func)
{
	return func(a,b);
}

class Item
{
public:

public:
	int _itemId = 0;
	int _rarity = 0;
	int _ownerId = 0;
};

using ItemSelectorType = bool(*)(Item* item);

Item* FindItem(Item items[], int itemCount, ItemSelectorType selector)
{
	for (int i = 0; i < itemCount; i++)
	{
		Item* item = &item[i];
		if (selector(item))
			return item;
	}

	return nullptr;
}

bool IsRare(Item* item)
{
	return item->_rarity == 1;
}
int main()
{
	Item items[10];
	items[3]._rarity = 1;

	FindItem(items, 10, IsRare); // �Լ� �����ͷ� IsRare�Լ��� selector�Լ���  �Ѱ���, ���߿� �͸��Լ� ���ٷ� ó���Ѵ�
}

#endif

class Test
{
public:
	void PrintTest() {}
};

int main()
{

#if 0
	using FuncPtrType = void(*)();

	// ����
	FuncPtrType ptr = Print;  

	// �������� ����, ��� �Լ��� �׳� ������ ����/���� �Լ��� �ٸ��� 
	// FuncPtrType ptr = PrintTest; 

	// �Լ� ȣ�� �Ծ��� �޶� �׷���.
	// �Լ� ȣ�� �Ծ� : �Լ��� ȣ��� �� ���޵Ǵ� ���ڵ��� ���� , �Լ��� ����� �� ������ ���� �������� ��

	// �Ϲ� �Լ��� ȣ�� �Ծ� : cdecl, ��� �Լ��� ȣ�� �Ծ� : thiscall

	Test t;
	t.PrintTest(); // ȣ�� �Ծ��� �ڱ� �ڽ��� ��ü �ּҸ� �ѱ�� ������ ������ �Ǿ��ִ�.

#endif
	// ��� �Լ� ������
	using MemFuncPtrType = void(Test::*)();

	MemFuncPtrType funcPtr = &Test::PrintTest;

	funcPtr(); // ����
	
	Test t;
	(t.*funcPtr)(); // �̷��� ȣ���ؾ߸��Ѵ�

	Test* t2 = &t;
	(t2->*funcPtr)(); // �̰͵� �����ϴ� 

}