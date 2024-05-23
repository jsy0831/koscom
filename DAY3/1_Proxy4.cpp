// proxy4.cpp
#define USING_GUI
#include "cppmaster.h"

// Client 제작자는 서버 제작자에게 2개의 파일을 받아야 합니다.
// ICalc.h       : 인터페이스가 있는 헤더
// CalcProxy.dll  

#include "ICalc.h"

int main()
{
	ICalc* calc = get_proxy();


	int n1 = calc->Add(10, 20);
	int n2 = calc->Sub(10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}




