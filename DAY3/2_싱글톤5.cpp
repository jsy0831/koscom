#include <iostream>
#include <mutex>    

// CRTP 
// => Curiously Recurring Template Pattern
// => 기반 클래스에서 파생 클래스의 이름을 사용할수 있게 하는 패턴
// => 기반 클래스를 템플릿으로 만들고, 파생 클래스가 자신의 이름을 템플릿 인자로 전달하는것


template<typename T>
class Singleton
{
protected:
	Singleton() {}

	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singletonursor&) = delete;

	static T* sinstance;    // <<===== !!!
	static std::mutex mtx;
public:

	static T& get_instance()  // <<===== !!!
	{
		std::lock_guard<std::mutex> g(mtx); 

		if (sinstance == nullptr)
			sinstance = new T;  // <<===== !!!

		return *sinstance;
	}
};

template<typename T> T* Singleton<T>::sinstance = nullptr;  //  <<===== !!!
template<typename T> std::mutex Singleton<T>::mtx;

// Mouse 도 힙에 만드는 싱글톤 패턴을 사용하고 싶다.
class Mouse : public Singleton< Mouse >
{
};

int main()
{
	Mouse& c1 = Mouse::get_instance();
	Mouse& c2 = Mouse::get_instance();

}








