#include <iostream>
#include <mutex>    

// CRTP 
// => Curiously Recurring Template Pattern
// => ��� Ŭ�������� �Ļ� Ŭ������ �̸��� ����Ҽ� �ְ� �ϴ� ����
// => ��� Ŭ������ ���ø����� �����, �Ļ� Ŭ������ �ڽ��� �̸��� ���ø� ���ڷ� �����ϴ°�


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

// Mouse �� ���� ����� �̱��� ������ ����ϰ� �ʹ�.
class Mouse : public Singleton< Mouse >
{
};

int main()
{
	Mouse& c1 = Mouse::get_instance();
	Mouse& c2 = Mouse::get_instance();

}








