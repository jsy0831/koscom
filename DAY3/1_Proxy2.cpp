// x86 ���� �����ϼ���.
#define USING_GUI
#include "cppmaster.h"

// ������ �����ڸ� ����� ���ô�. 
// => Proxy ����
// => Proxy �� ���� �����ڰ� ���� Client �����ڿ��� ���� �ϰ� �˴ϴ�.

// �Ʒ� Calc �� ������
// 1. Client �����ڴ� IPC ����� ���� �˴ϴ�.
// 2. 1, 2 ���� ��� �ڵ带 ���� �ǰ�, Add, Sub �� ����ϸ� �˴ϴ�.
// 3. ������ ��ֽ� �����ϴ� ����� Proxy �� �����ϸ� �˴ϴ�.

// 4. Client �� "Add" �� ȣ���ϸ� �ٸ� ���μ���(����)�� Add �� �����մϴ�.
// => Remote Procedure Call ( RPC �� ����� �ִ� ���� )

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




