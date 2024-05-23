#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

int main()
{
	ICalc* calc1 = get_proxy(); // 규칙 1. proxy 객체를 얻으면 
	calc1->AddRef();			//			참조계수 증가

	ICalc* calc2 = calc1;		// 규칙 2. 또다른 포인터로 가리키게되면
	calc2->AddRef();			//			참조계수 증가

	// 규칙 3. 더이상 사용하지 않으면 참조계수 감소
	calc1->Release();

	std::cout << "================\n";
	calc2->Release();
	std::cout << "================\n";
}




