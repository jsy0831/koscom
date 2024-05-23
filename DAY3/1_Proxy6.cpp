#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

int main()
{
	ICalc* calc = get_proxy(); // 이순간 최종적으로는 
	// DLL 내부의 CreateProxy() 가 호출되고
	// "new Calc" 로 객체를 만들게 됩니다.
	// delete 가 필요 하지 않을까요 ??

	int n1 = calc->Add(10, 20);
	int n2 = calc->Sub(10, 20);

	delete calc; // 이렇게 해도 될까요?
}




