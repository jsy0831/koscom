#include <iostream>

class Animal
{
public:
	// non-virtual : static binding 해달라는 의미.
	void cry1() { std::cout << "Animal Cry1" << std::endl; }


	// virtual : 함수 호출시 dynamic binding 해달라는 의미
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
	p->cry1(); // static binding : 포인터 타입으로 컴파일 시간에 결정 Animal cry1
	p->cry2(); // dynamic binding : 메모리 조사후 함수 호출 결정 Dog cry2
}


