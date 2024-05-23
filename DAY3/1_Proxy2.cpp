// x86 으로 빌드하세요.
#define USING_GUI
#include "cppmaster.h"

// 서버의 대행자를 만들어 봅시다. 
// => Proxy 패턴
// => Proxy 는 서버 제작자가 만들어서 Client 제작자에게 배포 하게 됩니다.

// 아래 Calc 가 있으면
// 1. Client 제작자는 IPC 기술을 몰라도 됩니다.
// 2. 1, 2 같은 명령 코드를 몰라도 되고, Add, Sub 를 사용하면 됩니다.
// 3. 서버의 장애시 대응하는 방식을 Proxy 가 제공하면 됩니다.

// 4. Client 가 "Add" 를 호출하면 다른 프로세스(서버)의 Add 가 응답합니다.
// => Remote Procedure Call ( RPC 를 만들고 있는 과정 )

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




