//»ı¼ºÀÚ1.cpp - 3page
#include <iostream>

class Base
{
public:
	Base() {  }
	Base(int a) {  }
	~Base() {  }
};
class Derived : public Base
{
public:
	Derived()	   {}
	Derived(int a) {}
	~Derived()
	{
	}
};
int main()
{
//	Derived d1;		
	Derived d2(5);  

}