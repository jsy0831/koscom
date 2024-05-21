#include <iostream>
// �ٽ� 
// => ��� Ŭ������ ���Ǵ� Ŭ������ �Ҹ��ڴ� 
// => public virtual �̰ų� protected non-virtual �̾�� �Ѵ�.
class Base
{
public:
//	~Base() {}
	virtual ~Base() {}
};
class Derived : public Base
{
public:
	Derived()  { std::cout << "Derived() �ڿ��Ҵ�" << std::endl; }
	~Derived() { std::cout << "~Derived() �ڿ�����" << std::endl; }
};
int main()
{
//	Derived d; // �ƹ� ���� ����

//	Derived* p = new Derived;
//	delete p;	// �ƹ� ���� ����

	Base* p = new Derived;
	delete p;	// ����!!! Derived �Ҹ��� ȣ�� �ȵ�.(�Ҹ��ڰ� �����̾ƴϸ�)

	// 1. �Ҹ��� ȣ�⵵ �Լ� ȣ���Դϴ�.
	// 2. �����Ϸ��� p �� Base* ��� ��Ǹ� �˰� �ֽ��ϴ�.
	// 3. �׷��� Base �� �����ؼ� �Ҹ��ڰ� �������� �ƴ��� ����
	// 
	// => �Ҹ��� ������ �ƴϸ� static binding
	// => �Ҹ��� �����̸� dynamic binding

}	
