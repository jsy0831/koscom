// CalcProxy.cpp
#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

class Calc : public ICalc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

// DLL �����(CLIENT) �� DLL ���� Ŭ���� �̸���
// ������ ���ϰ�, �� �ʿ䵵 ����, ����ؼ��� �ȵ˴ϴ�.

// Calc �� ��ü�� �����ϴ� �Լ��� DLL ���ο��� ��ӵ� �̸��� �Լ��� �����ؾ� �մϴ�.
extern "C" __declspec(dllexport)	// windows DLL ���� �Լ� ���鶧 �ʿ�
ICalc* CreateProxy()
{
	return new Calc;
}