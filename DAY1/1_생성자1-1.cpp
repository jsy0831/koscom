//������1.cpp - 3page
#include <iostream>

class Base
{
public:
//	Base() {  }
	Base(int a) {  }
	~Base() {  }
};
class Derived : public Base
{
public:
	// �ٽ� 1. �Ʒ� 2���� �� �������� ��Ȯ�� �˾� �μ���
//	Derived()	   {} // Derived()	    : Base() {}
//	Derived(int a) {} // Derived(int a) : Base() {}

	// �ٽ� 2. ��� Ŭ������ ����Ʈ �����ڰ� ���ٸ�
	//        �ݵ�� �Ļ� Ŭ������ �����ڿ��� ��� Ŭ������ �ٸ� �����ڸ�
	//        ��������� ȣ���ؾ� �մϴ�
	Derived()      : Base(0) {}
	Derived(int n) : Base(n) {}

	~Derived()
	{
	}
};
int main()
{
//	Derived d1;		
	Derived d2(5);  

}