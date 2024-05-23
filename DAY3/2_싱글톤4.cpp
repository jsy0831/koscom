#include <iostream>
#include <mutex>    

// RAII IDioms
// => �ڿ��� ������ �Լ��� ������ �κп��� ���� ����!!
// => �ڿ��� ������ ������/�Ҹ��ڿ� �����ض�!

// => Resource Acquision Is (�ڿ�������ü��) Initialization 
// => �ڿ��� ȹ���� �ڿ� ���� ��ü�� �����ڿ��� �̷������ �ڵ带 ���� ����



// �ڿ�����(lock/unlock) �� �ڵ�ȭ�ϱ� ���� ����
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
			std::lock_guard<std::mutex> g(mtx); // �̹� ǥ�ؿ� lock_guard�� �ֽ��ϴ�.
												// �ܿ� ������ �ڵ� �Դϴ�
												
//			lock_guard<std::mutex> g(mtx); // �����ڿ��� mtx.lock() ����
											// g�� �ı��ɶ� �Ҹ��ڿ��� mtx.unlock()
											// ���ܵ��� �߻��ص� �������� �ı��� �����ϰ� ����˴ϴ�.
											//  "stack unwinding" �̶�� �մϴ�.
											// => ��κ��� ����� ������ Ư¡.
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








