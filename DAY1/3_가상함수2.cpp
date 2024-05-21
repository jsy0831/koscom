#include <iostream>
// 핵심 
// => 기반 클래스로 사용되는 클래스의 소멸자는 
// => public virtual 이거나 protected non-virtual 이어야 한다.
class Base
{
public:
//	~Base() {}
	virtual ~Base() {}
};
class Derived : public Base
{
public:
	Derived()  { std::cout << "Derived() 자원할당" << std::endl; }
	~Derived() { std::cout << "~Derived() 자원해지" << std::endl; }
};
int main()
{
//	Derived d; // 아무 문제 없음

//	Derived* p = new Derived;
//	delete p;	// 아무 문제 없음

	Base* p = new Derived;
	delete p;	// 버그!!! Derived 소멸자 호출 안됨.(소멸자가 가상이아니면)

	// 1. 소멸자 호출도 함수 호출입니다.
	// 2. 컴파일러는 p 가 Base* 라는 사실만 알고 있습니다.
	// 3. 그래서 Base 를 조사해서 소멸자가 가상인지 아닌지 조사
	// 
	// => 소멸자 가상이 아니면 static binding
	// => 소멸자 가상이면 dynamic binding

}	
