// proxy4.cpp
#define USING_GUI
#include "cppmaster.h"

// Client �����ڴ� ���� �����ڿ��� 2���� ������ �޾ƾ� �մϴ�.
// ICalc.h       : �������̽��� �ִ� ���
// CalcProxy.dll  

#include "ICalc.h"

int main()
{
	ICalc* calc = get_proxy();


	int n1 = calc->Add(10, 20);
	int n2 = calc->Sub(10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}




