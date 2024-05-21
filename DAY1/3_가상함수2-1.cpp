#include <iostream>
// 핵심 
// => 기반 클래스로 사용되는 클래스의 소멸자는 
// => public virtual 이거나 protected non-virtual 이어야 한다.
class Base
{
protected:
	~Base() {}
};
class Derived : public Base
{
public:
	Derived() { std::cout << "Derived() 자원할당" << std::endl; }
	~Derived() { std::cout << "~Derived() 자원해지" << std::endl; }
};
int main()
{
	// 기반 클래스를 가상 소멸자로 해야 하는 이유는
	// => 아래와 같이 Base* 타입으로 delete 하는 코드가 있을때를 위해서 입니다.
	// => 가상함수는 오버헤드를 가지게 됩니다.(가상함수 테이블)
	// => 그런데, 아래 같은 코드가 없다면 "virtual 소멸자"를 사용하지 않아도됩니다
	
	Base* p = new Derived;
//	delete p;	// error. protected 함수를 호출할수 없다.

	delete static_cast<Derived*>(p); // ok. 

}

// 구글에서 "C++ core guideline" 검색 - 1번째 링크 선택


