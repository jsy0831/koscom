// 3_싱글톤1 - 123 page
#include <iostream>

// 싱글톤 : 오직 한개의 객체만 존재하는 것.
//			어디에서든지 동일한 방법으로 객체에 접근할수 있는것

// => 결국 전역변수!!
// => 전역변수는 좋지 않습니다.
// => 그래서 싱글톤 패턴에 대한 비판도 많이 있습니다.


class Cursor
{
	// 규칙 1. private 생성자
private:
	Cursor() {}

	// 규칙 2. 컴파일러에게 복사 생성자와 대입연산자를 만들지 못하게 해야 합니다
	Cursor(const Cursor&) = delete; 
	Cursor& operator=(const Cursor&) = delete; // 복사가 금지되면 관례적으로 대입도금지

	// 규칙 3. 오직 한개의 객체만 만들어서 반환하는 static 멤버 함수
public:
	static Cursor& get_instance()
	{
		static Cursor instance;
		return instance;
	}	
};

int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();

//	Cursor c3 = c1; // 복사 생성자 호출 로 객체 생성도 막아야 합니다.

//	Cursor c1, c2; // error
}








