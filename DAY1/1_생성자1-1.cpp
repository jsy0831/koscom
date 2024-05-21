//생성자1.cpp - 3page
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
	// 핵심 1. 아래 2줄이 왜 에러인지 명확히 알아 두세요
//	Derived()	   {} // Derived()	    : Base() {}
//	Derived(int a) {} // Derived(int a) : Base() {}

	// 핵심 2. 기반 클래스에 디폴트 생성자가 없다면
	//        반드시 파생 클래스의 생성자에서 기반 클래스의 다른 생성자를
	//        명시적으로 호출해야 합니다
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