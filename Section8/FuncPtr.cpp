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

// 콜백 함수
// -ex) UI에서 버튼을 누르면 어떤 함수가 실행이 되어야한다고 할 때, 결국 어떤 동작을 인자로 넘겨줘야할 필요가 있다고 할 수 있다.
// -ex) 온라인 게임 클라가 입장했을 때 서버가 어떤 행동을 할지 예측할 수가 없으니까 함수포인터로 동작을 연결해줘서 처리한다.
// -ex) 키보드 입력 - 특정 키를 누르면 무엇인가가 일어난다고 할때, 만약 롤이라고 하면 Q버튼을 누르면 스킬이 나가는데
//					  만약 단축키를 수정해서 다른 키를 눌렀을 때 해당 스킬이 나가게 해야한다면 함수 포인터를 이용하는게 좋다

// 행동 자체를 인자로 넘기고 싶을 때 함수포인터를 이용하면 좋다.
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

	FindItem(items, 10, IsRare); // 함수 포인터로 IsRare함수를 selector함수로  넘겨줌, 나중엔 익명함수 람다로 처리한다
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

	// 매핑
	FuncPtrType ptr = Print;  

	// 오류나는 예시, 멤버 함수는 그냥 보통의 정적/전역 함수와 다르다 
	// FuncPtrType ptr = PrintTest; 

	// 함수 호출 규약이 달라서 그렇다.
	// 함수 호출 규약 : 함수가 호출될 때 전달되는 인자들의 순서 , 함수가 종료될 때 스택을 누가 정리할지 등

	// 일반 함수의 호출 규약 : cdecl, 멤버 함수의 호출 규약 : thiscall

	Test t;
	t.PrintTest(); // 호출 규약이 자기 자신의 객체 주소를 넘기는 식으로 구성이 되어있다.

#endif
	// 멤버 함수 포인터
	using MemFuncPtrType = void(Test::*)();

	MemFuncPtrType funcPtr = &Test::PrintTest;

	funcPtr(); // 오류
	
	Test t;
	(t.*funcPtr)(); // 이렇게 호출해야만한다

	Test* t2 = &t;
	(t2->*funcPtr)(); // 이것도 가능하다 

}