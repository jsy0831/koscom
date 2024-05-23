#include <iostream>

// 아래 코드는 
// => effective - c++ 책의 저자인 "scott mayer" 가 처음 제안한 코드
// => "mayer's singleton" 이라고 합니다.
// => 멀티 스레드 안전하고(C++11부터), 
// => 현재 C++ 진영에서 가장 좋은 모델로 평가 됩니다.



class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete; 



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
}








