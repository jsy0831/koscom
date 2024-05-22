#include <iostream>
#include <functional>
using namespace std::placeholders;

void f1(int a)               { printf("f1 : %d\n", a); }
void f2(int a, int b)        { printf("f2 : %d, %d\n", a, b);}
void f3(int a, int b, int c) { printf("f3 : %d, %d, %d\n", a, b, c); }
void f4(int a, int b, int c, int d) { printf("f4 : %d, %d, %d, %d\n", a, b, c, d);}

class Dialog
{
public:
	void Init(int a, int b)
	{
		printf("Dialog Init : %d, %d\n", a, b);
	}
};

int main()
{
	// C ����� �Լ� �����ʹ� ������ ������ ������ �Լ� �ּҸ� ������ �ֽ��ϴ�.
//	void(*f)(int);
//	f = &f1; // ok
//	f = &f2; // error

	// C++ STL �� std::function �� ����ϸ� �Լ� ������ ���� ���մϴ�.
	// ���� : std::function<�Լ�Ÿ��>

	std::function<void(int)> f;

	f = &f1;
	f(10); // f1(10) �� �ǹ�. ��, �Լ� �����Ϳ� ���� ����.
    

	// std::function �� ���� : std::bind() �� ����� ������ �ֽ��ϴ�.
	 
//	f = &f2; // error. �̷��� �������� ������

	f = std::bind(&f2, _1, 0);

	f(3); // f2(3, 0);

	//----------------------------
	// 4�� => 1������ �����ؼ� f �� ���
	f = std::bind(&f4, 7, _1, 5, 9 );

	f(3); // f4(7, 3, 5, 9) ������ �� ? ä�켼��.

	//--------------------------------
	// ��� �Լ��� ȣ���Ҷ��� ��ü�� �ʿ� �մϴ�.
	// => std::bind ���� ��� �Լ��ּҸ� �����ϴ� ���� ��ü�� ���� ����
	Dialog dlg;
	dlg.Init(1, 2);

	f = std::bind(&Dialog::Init, &dlg, 0, _1);

	f(10); // dlg.Init(0, 10)

}












