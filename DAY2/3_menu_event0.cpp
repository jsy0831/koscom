// 3_menu_event0.cpp
void f1(int a) {}
void f2(int a, int b) {}

int main()
{
	// C 언어의 함수 포인터!
	// => 함수의 주소를 보관했다가 나중에 호출하기 위해 사용
	void(*f)(int) = &f1;	// f1 의 주소를 f 에 보관한것

	f(10); // 결국 f1(10) 의 의미.

	// C 함수포인터는 불편합니다.
	// 인자의 갯수가 다른 함수 주소 는 담을수 없습니다.
	f = &f2; // error

	// 그래서, C++ 에서는 함수 포인터를 발전시킨 std::function
	// 이 있습니다.

}