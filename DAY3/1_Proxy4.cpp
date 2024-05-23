// proxy4.cpp
#define USING_GUI
#include "cppmaster.h"

// Client �����ڴ� ���� �����ڿ��� 2���� ������ �޾ƾ� �մϴ�.
// ICalc.h       : �������̽��� �ִ� ���
// CalcProxy.dll  

ICalc* get_proxy()
{
	// 1. DLL load
	void* addr = ec_load_module("CalcProxy.dll");
				// linux : ldopen(),   Windws : LoadLibrary()


	// 2. ��ӵ� �Լ� ã��
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




