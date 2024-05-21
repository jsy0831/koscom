//������1.cpp - 3page
#include <iostream>

class Base
{
public:
	Base()     { std::cout << "Base()" << std::endl; }
	Base(int a){ std::cout << "Base(int)" << std::endl; }
	~Base()    { std::cout << "~Base()" << std::endl; }
};
class Derived : public Base
{
public:		
	// ������ �ڵ�		// �����Ϸ��� ������ �ڵ�
	Derived()			// Derived() : Base()
	{ 
		std::cout << "Derived()" << std::endl; 
	}
	Derived(int a)		// Derived(int a) : Base()  // �ٽ� : �����Ϸ����߰���
	{												// �ڵ�� �׻� Base ����Ʈ ������ȣ��
		std::cout << "Derived(int)" << std::endl; 
	}
	~Derived()		
	{ 
		std::cout << "~Derived()" << std::endl; 
		// �Ҹ��ڴ� Derived ������ ���� ����ǰ� Base �Ҹ��� ȣ��
		// Base::~Base()
	}
};
int main()
{
	Derived d1;		// call Derived::Derived() 
//	Derived d2(5);  // call Derived::Derived(5) �� ���� �ڵ� ����

}