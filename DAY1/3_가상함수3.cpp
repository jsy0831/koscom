// 2_가상함수재정의
class Base
{
public:
	virtual void foo() {}
	virtual void goo(int) {}
};

class Derived : public Base
{
public:
	// 핵심 #1. 가상함수를 override 할때는 virtual 을
	//         표기해도 되고 표기하지 않아도 됩니다.
//	virtual void foo() {}

	// 핵심 #2. 가상함수 override 시에 실수(오타)가 있어도
	//          에러가 아닙니다
	// => 다른 가상함수를 만들었다고 컴파일러가 생각하게 됩니다.
//	virtual void fooo() {}
//	virtual void goo(double){}

	// 핵심 #3. 위 문제를 해결하기 위해 C++11 부터 override 키워드추가
	virtual void fooo()      override {} // error
	virtual void goo(double) override {} // error

};

int main()
{
}





