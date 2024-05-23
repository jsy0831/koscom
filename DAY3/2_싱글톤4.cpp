#include <iostream>
#include <mutex>    

// RAII IDioms
// => 자원의 해지는 함수의 마지막 부분에서 하지 말라!!
// => 자원의 관리는 생성자/소멸자에 의존해라!

// => Resource Acquision Is (자원관리객체가) Initialization 
// => 자원의 획득은 자원 관리 객체의 생성자에서 이루어지는 코드를 가진 패턴



// 자원관리(lock/unlock) 을 자동화하기 위한 도구
template<typename T>
class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m) : mtx(m) { mtx.lock(); }
	~lock_guard()             { mtx.unlock(); }
};


class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

	static Cursor* sinstance;
	static std::mutex mtx;
public:

	static Cursor& get_instance()
	{
		{
			std::lock_guard<std::mutex> g(mtx); // 이미 표준에 lock_guard가 있습니다.
												// 외와 동일한 코드 입니다
												
//			lock_guard<std::mutex> g(mtx); // 생성자에서 mtx.lock() 수행
											// g가 파괴될때 소멸자에서 mtx.unlock()
											// 예외등이 발생해도 지역변수 파괴는 안전하게 보장됩니다.
											//  "stack unwinding" 이라고 합니다.
											// => 대부분의 언어의 공통의 특징.
								//		mtx.lock();	

			if (sinstance == nullptr)
				sinstance = new Cursor;

			//		mtx.unlock();
		}

		return *sinstance;
	}
};
Cursor* Cursor::sinstance = nullptr;
std::mutex Cursor::mtx;

int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();

}








