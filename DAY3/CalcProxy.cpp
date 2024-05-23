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

// DLL 사용자(CLIENT) 는 DLL 안의 클래스 이름을
// 알지도 못하고, 알 필요도 없고, 사용해서도 안됩니다.

// Calc 의 객체를 생성하는 함수는 DLL 내부에서 약속된 이름의 함수로 제공해야 합니다.
extern "C" __declspec(dllexport)	// windows DLL 에서 함수 만들때 필요
ICalc* CreateProxy()
{
	return new Calc;
}

// 리눅스환경의 C++ 컴파일러이름 : "gcc, g++"
// 윈도우 환경우 MS가제공하는 C++ 컴파일러 : "cl.exe"

// CalcProxy.cpp 소스가 있는 곳으로 이동후

// cl CalcProxy.cpp /LD  /link user32.lib gdi32.lib kernel32.lib  
// 
// => /LD : DLL 로 빌드하라는 옵션
// => /link 이하는 IPC 기술 때문에 필요