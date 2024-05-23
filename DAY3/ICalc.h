// ICalc.h
#pragma once
#define USING_GUI
#include "cppmaster.h"

struct ICalc
{
	// reference counting  기반으로 객체의 수명을 관리할때는
	// 인터페이스 안에 참조계수 관련 함수선언을 같이 제공해야 합니다.
	virtual void AddRef() = 0;
	virtual void Release() = 0;


	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};


ICalc* get_proxy()
{
	// 1. DLL load
	void* addr = ec_load_module("CalcProxy.dll");
	// linux : ldopen(),   Windws : LoadLibrary()


// 2. 약속된 함수 찾기
	using F = ICalc * (*)();
	F f = (F)ec_get_function_address(addr, "CreateProxy");
	// linux : ldsym()     Windows : GetProcAddress()

	ICalc* calc = f();

	return calc;
}
