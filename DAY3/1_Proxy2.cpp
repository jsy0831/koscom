// x86 으로 빌드하세요.
#define USING_GUI
#include "cppmaster.h"

// 서버의 대행자를 만들어 봅시다. 
// => Proxy 패턴

class Calc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b);	}
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b);	}
};

int main()
{
	Calc* calc = new Calc;

	int n1 = calc->Add(10, 20);
	int n2 = calc->Sub(10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}




