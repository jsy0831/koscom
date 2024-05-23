#define USING_GUI
#include "cppmaster.h"

struct ICalc
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};

class Calc : public ICalc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

int main()
{
	// Proxy 는 서버 제작자가 만들게 되는데

	// 아래 처럼 사용하면 "새로운 Proxy 배포시 코드가 변경되게 됩니다."

	// 인터페이스를 사용해야 교체 가능한 설계가 됩니다.
//	Calc* calc = new Calc;

	ICalc* calc = new ??;


	int n1 = calc->Add(10, 20);
	int n2 = calc->Sub(10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}




