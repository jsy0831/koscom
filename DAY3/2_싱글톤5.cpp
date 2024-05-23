#include <iostream>
#include <mutex>    

class Singleton
{
private:
	Singleton() {}

	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singletonursor&) = delete;

	static Singleton* sinstance;
	static std::mutex mtx;
public:

	static Singleton& get_instance()
	{
		std::lock_guard<std::mutex> g(mtx); 

		if (sinstance == nullptr)
			sinstance = new Singleton;

		return *sinstance;
	}
};
Singleton* Singleton::sinstance = nullptr;
std::mutex Singleton::mtx;

// Mouse 도 힙에 만드는 싱글톤 패턴을 사용하고 싶다.
class Mouse : public Singleton
{
};

int main()
{
	Mouse& c1 = Mouse::get_instance();
	Mouse& c2 = Mouse::get_instance();

}








