#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

int main()
{
	ICalc* calc = get_proxy(); // �̼��� ���������δ� 
	// DLL ������ CreateProxy() �� ȣ��ǰ�
	// "new Calc" �� ��ü�� ����� �˴ϴ�.
	// delete �� �ʿ� ���� ������� ??

	int n1 = calc->Add(10, 20);
	int n2 = calc->Sub(10, 20);

	delete calc; // �̷��� �ص� �ɱ��?
}




