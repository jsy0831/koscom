// CalcProxy.cpp
#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"
#include <atomic>

class Calc : public ICalc
{
	int server;

	std::atomic<int> ref = 0; // 멀티스레드에 안전하게 증가/감소 하는 변수
public:
	
	void AddRef() { ++ref; } // 멀티 스레드 환경에서도 안전하게 1증가

	void Release()
	{
		if (--ref == 0)
			delete this;
	}


	Calc() { server = ec_find_server("Calc"); }

	~Calc() { std::cout << "~Calc()\n"; }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

extern "C" __declspec(dllexport)	
ICalc* CreateProxy()
{
	return new Calc;
}
