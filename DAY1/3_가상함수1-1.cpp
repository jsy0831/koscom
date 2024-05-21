#include <iostream>

class Animal
{
public:
	// non-virtual : static binding �ش޶�� �ǹ�.
	void cry1() { std::cout << "Animal Cry1" << std::endl; }


	// virtual : �Լ� ȣ��� dynamic binding �ش޶�� �ǹ�
	virtual void cry2() { std::cout << "Animal Cry2" << std::endl; }
};


class Dog : public Animal
{
public:
	void cry1() { std::cout << "Dog Cry1" << std::endl; }

	virtual void cry2() { std::cout << "Dog Cry2" << std::endl; }
};


int main()
{
	Dog d;  

	Animal* p = &d;
	p->cry1(); // static binding : ������ Ÿ������ ������ �ð��� ���� Animal cry1
	p->cry2(); // dynamic binding : �޸� ������ �Լ� ȣ�� ���� Dog cry2
}


