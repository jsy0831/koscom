#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

int main()
{
	ICalc* calc1 = get_proxy(); // ��Ģ 1. proxy ��ü�� ������ 
	calc1->AddRef();			//			������� ����

	ICalc* calc2 = calc1;		// ��Ģ 2. �Ǵٸ� �����ͷ� ����Ű�ԵǸ�
	calc2->AddRef();			//			������� ����

	// ��Ģ 3. ���̻� ������� ������ ������� ����
	calc1->Release();

	std::cout << "================\n";
	calc2->Release();
	std::cout << "================\n";
}




