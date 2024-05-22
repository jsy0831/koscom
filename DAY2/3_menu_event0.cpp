// 3_menu_event0.cpp

void f1(int a) {}
void f2(int a, int b) {}

int main()
{
	// C 언어의 함수 포인터!
	// => 함수의 주소를 보관했다가 나중에 호출하기 위해 사용
	void(*f)(int) = &f1;

	f(10); // 결국 f1(10) 의 의미.

}