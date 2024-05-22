#include <iostream>
#include <functional>
using namespace std::placeholders;

void f1(int a)               { printf("f1 : %d\n", a); }
void f2(int a, int b)        { printf("f2 : %d, %d\n", a, b);}
void f3(int a, int b, int c) { printf("f3 : %d, %d, %d\n", a, b, c); }
void f4(int a, int b, int c, int d) { printf("f4 : %d, %d, %d, %d\n", a, b, c, d);}

class Dialog
{
public:
	void Init(int a, int b)
	{
		printf("Dialog Init : %d, %d\n", a, b);
	}
};

int main()
{
	// C 언어의 함수 포인터는 인자의 갯수가 동일한 함수 주소만 담을수 있습니다.
//	void(*f)(int);
//	f = &f1; // ok
//	f = &f2; // error

	// C++ STL 의 std::function 을 사용하면 함수 포인터 보다 편리합니다.
	// 사용법 : std::function<함수타입>

	std::function<void(int)> f;

	f = &f1;
	f(10); // f1(10) 의 의미. 즉, 함수 포인터와 사용법 같음.
    

	// std::function 의 장점 : std::bind() 의 결과를 담을수 있습니다.
	 
//	f = &f2; // error. 이렇게 담을수는 없지만

	f = std::bind(&f2, _1, 0);

	f(3); // f2(3, 0);

	//----------------------------
	// 4항 => 1항으로 변경해서 f 에 담기
	f = std::bind(&f4, 7, _1, 5, 9 );

	f(3); // f4(7, 3, 5, 9) 나오게 위 ? 채우세요.

	//--------------------------------
	// 멤버 함수를 호출할때는 객체가 필요 합니다.
	// => std::bind 사용시 멤버 함수주소를 전달하는 경우는 객체도 같이 전달
	Dialog dlg;
	dlg.Init(1, 2);

	f = std::bind(&Dialog::Init, &dlg, 0, _1);

	f(10); // dlg.Init(0, 10)

}












