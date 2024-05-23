// proxy4.cpp
#define USING_GUI
#include "cppmaster.h"

// Client 제작자는 서버 제작자에게 2개의 파일을 받아야 합니다.
// ICalc.h       : 인터페이스가 있는 헤더
// CalcProxy.dll  

ICalc* get_proxy()
{
	// 1. DLL load
	void* addr = ec_load_module("CalcProxy.dll");
				// linux : ldopen(),   Windws : LoadLibrary()


	// 2. 약속된 함수 찾기
	using F = ICalc* (*)();
	F f = (F)ec_get_function_address(addr, "CreateProxy");
				// linux : ldsym()     Windows : GetProcAddress()

	ICalc* calc = f();

	return calc;
}

int main()
{
	ICalc* calc = get_proxy();


	int n1 = calc->Add(10, 20);
	int n2 = calc->Sub(10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}




