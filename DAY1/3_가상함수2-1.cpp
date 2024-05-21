#include <iostream>
// �ٽ� 
// => ��� Ŭ������ ���Ǵ� Ŭ������ �Ҹ��ڴ� 
// => public virtual �̰ų� protected non-virtual �̾�� �Ѵ�.
class Base
{
protected:
	~Base() {}
};
class Derived : public Base
{
public:
	Derived() { std::cout << "Derived() �ڿ��Ҵ�" << std::endl; }
	~Derived() { std::cout << "~Derived() �ڿ�����" << std::endl; }
};
int main()
{
	// ��� Ŭ������ ���� �Ҹ��ڷ� �ؾ� �ϴ� ������
	// => �Ʒ��� ���� Base* Ÿ������ delete �ϴ� �ڵ尡 �������� ���ؼ� �Դϴ�.
	// => �����Լ��� ������带 ������ �˴ϴ�.(�����Լ� ���̺�)
	// => �׷���, �Ʒ� ���� �ڵ尡 ���ٸ� "virtual �Ҹ���"�� ������� �ʾƵ��˴ϴ�
	
	Base* p = new Derived;
//	delete p;	// error. protected �Լ��� ȣ���Ҽ� ����.

	delete static_cast<Derived*>(p); // ok. 

}

// ���ۿ��� "C++ core guideline" �˻� - 1��° ��ũ ����


