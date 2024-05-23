// ICalc.h
#pragma once
#define USING_GUI
#include "cppmaster.h"

struct ICalc
{
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
