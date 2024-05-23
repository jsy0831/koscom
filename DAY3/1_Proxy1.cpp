// x86 으로 빌드하세요.
#define USING_GUI
#include "cppmaster.h"

// 아래 코드의 단점
// 1. 보통 서버는 한개지만 Client 는 여러개 입니다.
//    아래처럼 하면 모든 Client 가 IPC 기술을 알아야 합니다

// 2. 서버에 문제가 생기면 모든 Client 가 각각 에러에 대응해야 합니다.


int main()
{
	// 1. 서버의 핸들을 얻어 옵니다.
	int server = ec_find_server("Calc");

	std::cout << "서버 번호 : " << server << std::endl;

	// 2. 서버에 명령코드와 파라미터를 전달합니다.
	int n1 = ec_send_server(server, 1, 10, 20);
	int n2 = ec_send_server(server, 2, 10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}




